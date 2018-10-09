# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <errno.h>
# include <setjmp.h>
# include <time.h>

static void                         sig_usr1(int);
static void                         sig_alrm(int);
static sigjmp_buf                   jmpbuf;
static volatile sig_atomic_t       canjump;
void pr_mask(const char*);

/*
 * Reliable version of singal(), using POSIX sigaction().
 */
typedef void Sigfunc(int);

Sigfunc*
signal(int signo, Sigfunc *func){
    struct sigaction act, oact;
    act.sa_handler = func;
    sigemptyset(&act.sa_mask);
    act.sa_flags = 0;
    if (signo == SIGALRM){
#ifdef SA_INTERRUPT
        act.sa_flags |= SA_INTERRUPT;
#endif
    } else {
        act.sa_flags |= SA_RESTART;
    }
    if (sigaction(signo, &act, &oact) < 0){
        return SIG_ERR;
    }
    return oact.sa_handler;
}

int
main(void){
    if (signal(SIGUSR1, sig_usr1) == SIG_ERR){
        perror("signal(SIGUSR1) error");
        exit(1);
    }
    if (signal(SIGALRM, sig_alrm) == SIG_ERR) {
        perror("signal(SIGALRM) error");
        exit(1);
    }

    pr_mask("starting main: ");

	if (sigsetjmp(jmpbuf, 1)) {
        pr_mask("ending main: ");
        exit(0);
    }
    canjump = 1; /* now sigsetjmp() is OK */
    while(1)
        pause();
}

static void
sig_usr1(int signo){
    time_t      starttime;

    if (canjump == 0){
        return;                 /* unexpected signal, ignore */
    }

    pr_mask("starting sig_usr1: ");

    alarm(3);                   /* SIGALRM in 3 seconds */
    starttime = time(NULL);
    while(1)                    /* busy wait for 5 seconds */
        if (time(NULL) > starttime + 5){
            break;
        }

    pr_mask("finishing sig_usr1: ");

    canjump = 0;
    siglongjmp(jmpbuf, 1);      /* jump back to main, don't return */
}

static void
sig_alrm(int signo){
    pr_mask("in sig_alrm: ");
}

void
pr_mask(const char *str){
    sigset_t        sigset;
    int             errno_save;

    errno_save = errno;
    if (sigprocmask(0, NULL, &sigset) < 0){
        perror("sigpromask error");
        exit(1);
    } else {
        printf("%s", str);
        if (sigismember(&sigset, SIGINT))
            printf(" SIGINT");
        if (sigismember(&sigset, SIGQUIT))
            printf(" SIGQUIT");
        if (sigismember(&sigset, SIGUSR1))
            printf(" SIGUSR1");
        if (sigismember(&sigset, SIGALRM))
            printf(" SIGALRM");

        /* remaining signals can go here */
        printf("\n");
    }

    errno = errno_save;
}


# include "signal_util.h"

/*
 * Reliable version of singal(), using POSIX sigaction().
 */

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


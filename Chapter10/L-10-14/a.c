# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <unistd.h>
# include <errno.h>

void
pr_mask(const char *str){
    sigset_t        sigset;
    int             errno_save;

    errno_save = errno;
    if (sigpromask(0, NULL, &sigset) < 0){
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

# include "signal_util.h"

static void
sig_int(int signo){
    printf("caught SIGINT\n");
}

static void
sig_chld(int signo){
    printf("caught SIGCHLD\n");
}

int
main(void){
    if (signal(SIGINT, sig_int) == SIG_ERR){
        perror("signal(SIGINT) error");
        exit(1);
    }
    if (signal(SIGCHLD, sig_chld) == SIG_ERR){
        perror("signal(SIGCHLD) error");
        exit(1);
    }
    if (system("/bin/edit") < 0){
        perror("system() error");
        exit(1);
    }
    exit(0);
}

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <errno.h>
# include <sys/types.h>

static void sig_usr(int);       /* one handler for both signal */

int
main(void){
    if (signal(SIGUSR1, sig_usr) == SIG_ERR){
        perror("can't catch SIGUSR1");
        exit(1);
    }
    if (signal(SIGUSR2, sig_usr) == SIG_ERR){
        perror("can't catch SIGUSR2");
        exit(1);
    }
    while(1){
        pause();
    }
}

static void
sig_usr(int signo){             /* argument is signal number */
    if (signo == SIGUSR1){
        printf("recevied SIGUSR1\n");
    } else if (signo == SIGUSR2){
        printf("received SIGUSR2\n");
    } else{
        fprintf(stderr,"received signal %d\n",signo);
        exit(1);
    }
}

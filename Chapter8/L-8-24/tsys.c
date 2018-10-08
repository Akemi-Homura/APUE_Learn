# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/wait.h>

void pr_exit(int status);

void
pr_exit(int status){
    if (WIFEXITED(status)){
        printf("normal terminatin, exit status = %d\n",
                WEXITSTATUS(status));
    }else if (WIFSIGNALED(status)){
        printf("abnormal termination, singal number = %d%s\n",
                WTERMSIG(status),
#ifdef  WCOREDUMP
                WCOREDUMP(status) ? " (core file generated)" : "");
#else
        "");
#endif
    }else if (WIFSTOPPED(status)){
        printf("child stopped, signal number = %d\n",
                WSTOPSIG(status));
    }
}


int
main (int argc, char** argv){
    int     status;

    if (argc < 2){
        perror("command-line argument required");
        exit(1);
    }

    if ((status = system(argv[1])) < 0){
        perror("system() error");
        exit(1);
    }

    pr_exit(status);

    exit(0);
}

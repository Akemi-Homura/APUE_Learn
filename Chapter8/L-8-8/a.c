# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>

int
main(void){
    pid_t       pid;
    if ((pid = fork()) < 0){
        perror("fork error");
        exit(1);
    } else if (pid == 0){       /* first child */
        if ((pid = fork()) < 0){
            perror("fork error");
            exit(1);
        }else if (pid > 0){
            exit(0);    /* parent from second fork == first child */
        }
        /*
         * We're the second child; our parent become init as soon
         * as our real parent calls exit() in the statement above.
         * Here's where we'd continue executing, knowing that when
         * we're done, init will reap our status.
         */
        sleep(2);
        printf("second child, parent pid = %ld\n", (long)getppid());
        exit(0);
    }

    if (waitpid(pid, NULL, 0) != pid) {   /* wait for first child */
        perror("waitpid error");
        exit(1);
    }

    /*
     * We're the parent (the original process); we continue executing,
     * knowing that we're not the parent of the second child.
     */
    exit(0);
}

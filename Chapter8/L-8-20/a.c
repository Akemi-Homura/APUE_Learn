# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>

int
main(void){
    pid_t   pid;

    if ((pid = fork()) < 0) {
        perror("fork error");
        exit(1);
    } else if (pid == 0) { /* child */
        if (execl("/home/quals/bin/testinterp",
                    "testinterp", "myarg1", "MY ARG2", (char *)0) < 0){
            perror("execl error");
        }
    }
    if (waitpid(pid, NULL, 0) < 0 ) {/* parent */
        perror("waitpid error");
        exit(1);
    }
    exit(0);
}

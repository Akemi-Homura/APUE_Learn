# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/sysmacros.h>

pid_t vfork(void);

int     globvar = 6;        /* external variable in initialized data */
int
main(void){
    int     var;
    pid_t   pid;    /* automatic variable on the stack */

    var = 88;
    printf("before vfork\n");   /* we don't flush stdio */
    if ((pid = vfork()) < 0) {
        perror("vfork error");
        exit(1);
    }else if (pid == 0) {
        globvar++;
        var++;
        _exit(0);
    }
    /* parent continues here */
    printf("pid = %ld, glob = %d, var = %d\n", (long)getpid(), globvar, var);
    exit(0);
}

# include <stdio.h>
# include <unistd.h>
# include <sys/wait.h>
# include <stdlib.h>

static void charatatime(char *);

int
main(void){
    pid_t       pid;

    if ((pid = fork()) < 0){
        perror("fork errror");
        exit(1);
    } else if (pid == 0){
        charatatime("output from child\n");
    } else {
        charatatime("output form parent\n");
    }
    exit(0);
}

static void
charatatime(char *str){
    char        *ptr;
    int         c;
    setbuf(stdout, NULL);       /* set unbuffered */
    for (ptr = str; ( c = *ptr++) != 0;){
        putc(c, stdout);
    }
}

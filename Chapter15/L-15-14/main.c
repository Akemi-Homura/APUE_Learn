# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>
# include <sys/types.h>

# define MAXLINE 100

int
main(void){
    char        line[MAXLINE];
    FILE        *fpin;

    if ((fpin = popen("./myuclc", "r")) == NULL){
        perror("popen error");
        exit(1);
    }
    while(1){
        fputs("prompt> ", stdout);
        fflush(stdout);
        if (fgets(line, MAXLINE, fpin) == NULL)     /* read from pipe */
            break;
        if (fputs(line, stdout) == EOF){
            perror("fputs error to pipe");
            exit(1);
        }
    }
    if (pclose(fpin) == -1){
        perror("pclose error");
        exit(1);
    }
    putchar('\n');
    exit(0);
}

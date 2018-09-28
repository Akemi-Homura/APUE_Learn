# include <stdio.h>
# include <stdlib.h>

# define MAXLINE 100

int main(){
    char    buf[MAXLINE];

    while (fgets(buf, MAXLINE, stdin) != NULL){
        if (fputs(buf, stdout) == EOF){
            perror("output error");
        }
    }

    if (ferror(stdin)){
        perror("input error");
    }
    return 0;
}

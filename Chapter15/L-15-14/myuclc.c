# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <string.h>

int
main(void){
    int             c;

    while ((c = getchar()) != EOF){
        if (isupper(c)){
            c = tolower(c);
        }
        if (putchar(c) == EOF){
            perror("output error");
            exit(1);
        }
        if (c == '\n')
            fflush(stdout);
    }
}

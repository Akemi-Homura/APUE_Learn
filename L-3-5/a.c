# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define BUFFSIZE 4096

# define oops(m) { perror(m); exit(-1); }

int main(){
    int n;
    char buf[BUFFSIZE];

    while ( ( n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0 ){
        if (write(STDOUT_FILENO, buf, n) != n){
            oops("write error");
        }
    }

    if ( n < 0 ){
        oops("read error");
    }

    return 0;
}

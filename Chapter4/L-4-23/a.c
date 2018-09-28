# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

int main(){
    if (chdir("/tmp") < 0){
        perror("chdir failed");
        exit(1);
    }
    printf("chdir to /tmp succeeded\n");
    return 0;
}

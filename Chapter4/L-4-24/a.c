# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

int main(){
    char ptr[256];
    size_t  size = 256;
    if (chdir("/usr/src/") < 0){
        perror("chdir failed");
        exit(1);
    }
    if (getcwd(ptr, size) == NULL){
        perror("getcwd failed");
        exit(1);
    }
    printf("cwd = %s\n", ptr);
    return 0;
}

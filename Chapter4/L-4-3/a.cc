# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

int main(int argc, char** argv){
    struct stat buf;
    char *ptr;

    for(int i=1;i<argc; i++){
        printf("%s: ",argv[i]);
        if (lstat(argv[i], &buf) < 0){
            perror("lstat error");
            continue;
        }
        if (S_ISREG(buf.st_mode)){
            ptr = strdup("regular");
        }else if(S_ISDIR(buf.st_mode)){
            ptr = strdup("directory");
        }else if(S_ISCHR(buf.st_mode)){
            ptr = strdup("character special");
        }else if(S_ISBLK(buf.st_mode)){
            ptr = strdup("block special");
        }else if(S_ISFIFO(buf.st_mode)){
            ptr = strdup("fifo");
        }else if(S_ISLNK(buf.st_mode)){
            ptr = strdup("symbolic link");
        }else if(S_ISSOCK(buf.st_mode)){
            ptr = strdup("socket");
        }
        printf("%s\n",ptr);
    }
    return 0;
}

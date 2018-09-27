# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/stat.h>

int main(){
    struct stat statbuf;

    /* turn on set-group-ID and turn off group-execute */

    if (stat("foo", &statbuf) < 0){
        perror("stat error for foo");
        exit(1);
    }

    if (chmod("foo", (statbuf.st_mode & ~S_IXGRP) | S_ISGID) < 0){
        perror("chmod error for foo");
        exit(1);
    }

    /* set absolute mode to "rw-r--r--" */

    if (chmod("bar", S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH) < 0){
        perror("chmod error for bar");
        exit(1);
    }
    return 0;
}

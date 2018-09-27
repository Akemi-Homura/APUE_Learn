# include <fcntl.h>
# include <sys/types.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/stat.h>

/*
 * read and write permission for user.
 * read permission for group members
 * read permission for others
 */
# define FILE_MODE (S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)

# define oops(m) {perror(m); exit(1);}

int main(){
    int fd;
    const char buf1[] = "abcdefghij";
    const char buf2[] = "ABCDEFGHIJ";

    if ((fd = creat("file.hole", FILE_MODE)) < 0 ){
        oops("creat error");
    }

    if (write(fd, buf1, 10) != 10){
        oops("buf1 write error");
    }
    /* offset now 10 */

    if (lseek(fd, 16384, SEEK_SET) == -1){
        oops("lseek error");
    }
    /* offset now 16384 */

    if (write(fd, buf2, 10) != 10){
        oops("buf2 write error");
    }
    /* offset now 16394 */

    return 0;
}

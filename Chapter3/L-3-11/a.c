# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

# define oops(m) { perror(m); exit(1); }

int main(int argc, char** argv){
    int val;

    if (argc != 2){
        fprintf(stderr,"usage: a.out <descriptor#>");
        exit(1);
    }

    if (( val = fcntl(atoi(argv[1]), F_GETFL, 0)) < 0 ){
        fprintf(stderr,"fcntl error for fd %d", atoi(argv[1]));
    }

    /* mask O_ACCMODE first */
    switch (val & O_ACCMODE){
        case O_RDONLY:
            printf("read only");
            break;

        case O_WRONLY:
            printf("write only");
            break;

        case O_RDWR:
            printf("read write");
            break;

        default:
            perror("unkown access mode");
    }

    /* didn't mask O_ACCMODE */
    if (val & O_APPEND){
        printf(", append");
    }
    if( val & O_NONBLOCK){
        printf(", nonblocking");
    }
    if (val & O_SYNC){
        printf(", synchronous writes");
    }

#if !defined(_POSIX_C_SOURCE) && defined(O_FSYNC) && (O_FSYNC != O_SYNC)
    if (val & O_FSYNC){
        printf(", synchronous writes");
    }
#endif

    putchar('\n');
    return 0;
}

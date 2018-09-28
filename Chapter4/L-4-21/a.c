# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <time.h>
# include <sys/types.h>
# include <sys/stat.h>

int main(int argc, char** argv){
    int         i,fd;
    struct stat statbuf;
    struct timespec times[2];
    for (i = 1;i<argc;i++){
        if (stat(argv[i], &statbuf) < 0){ /* fetch current times */
            fprintf(stderr,"%s: stat error",argv[i]);
            perror("");
            continue;
        }

        if ((fd = open(argv[i], O_RDWR | O_TRUNC)) < 0) {  /* truncate */
            fprintf(stderr,"%s: open error", argv[i]);
            perror("");
            continue;
        }
        times[0] = statbuf.st_atim;
        times[1] = statbuf.st_mtim;
        if (futimens(fd, times) < 0){ /* reset times */
            fprintf(stderr,"%s: futimens error",argv[i]);
            perror("");
            continue;
        }
        close(fd);
    }
    return 0;
}

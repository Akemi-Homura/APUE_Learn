# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>

# define PAGER  "${PAGER:-more}"
# define MAXLINE 100

int
main(int argc, char** argv){
    char line[MAXLINE];
    FILE *fpin, *fpout;

    if (argc != 2){
        fprintf(stderr, "usage: a.out <pathname>\n");
        exit(1);
    }
    if ((fpin = fopen(argv[1], "r")) == NULL){
        fprintf(stderr,"can't open %s", argv[1]);
        perror("");
        exit(1);
    }

    if ((fpout = popen(PAGER, "w")) == NULL){
        perror("popen error");
        exit(1);
    }

    /* copy argv[1] to pager */
    while (fgets(line, MAXLINE, fpin) != NULL) {
        if (fputs(line, fpout) == EOF){
            perror("fputs error to pipe");
            exit(1);
        }
    }

    if (ferror(fpin)){
        perror("fgets error");
        exit(1);
    }
    if (pclose(fpout) == -1){
        perror("pclose error");
        exit(1);
    }

    exit(0);
}

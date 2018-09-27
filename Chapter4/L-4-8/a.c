# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int main(int argc, char** argv){
    if (argc != 2){
        fprintf(stderr,"usage: a.out <pathname>");
    }

    if (access(argv[1], R_OK) < 0){
        fprintf(stderr,"access error for %s\n",argv[1]);
    }else{
        printf("read access OK\n");
    }

    if(open(argv[1], O_RDONLY) < 0){
        fprintf(stderr,"open error for %s",argv[1]);
        perror("");
    }else{
        printf("open for reading OK\n");
    }
    return 0;
}

#include <stdint.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>

int main(int argc, char *argv[]){

    //printf("args %d\n", argc);

    if (argc < 3) {
        printf("Not enough arguments, filename or text not specified\n");
        syslog(LOG_ERR,"Not enough arguments, filename or text not specified\n");
        perror("arguments");
        return 1;
    }

    int openRet;
    ssize_t writeText;
    
    printf("Writing %s to %s \n", argv[2], argv[1]);
    syslog(LOG_DEBUG,"Writing %s to %s \n", argv[2], argv[1]);
    
    openRet = open(argv[1],O_WRONLY|O_TRUNC|O_CREAT, 0664 );

    if(openRet == -1) {
        printf("Couldn't create the file\n");
        syslog(LOG_ERR,"Couldn't create the file\n");
        perror("create-file");
        return -1;
    }

    writeText = write(openRet,argv[2],(strlen(argv[2])));
    
    if( writeText == -1) {
        printf("Couldn't write text to the file\n");
        syslog(LOG_ERR,"Couldn't write text to the file\n");
        perror("write");
        return -1;
    }

    openRet = close(openRet);

    if(openRet == -1) {
        printf("Couldn't close the file\n");
        syslog(LOG_ERR,"Couldn't close the file\n");
        perror("close");
        return -1;
    }
   
    printf("Success\n");
    syslog(LOG_DEBUG,"Success\n");
    return 0;
}
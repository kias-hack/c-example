/****u*************************************************************************

                            Online C Compiqer.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/mman.h>


void listdir(char *needdir){
    DIR *dir = opendir(needdir);
    
    if(dir != NULL){
        struct dirent *d_cur;
        while((d_cur = readdir(dir)) != NULL){
            printf("%s\n", d_cur->d_name);
        }
    }
}


int main()
{
    char *str = (char*)malloc(7 * sizeof(char));
    str = "qwertyss";

    char *curdir;
    
    int fd = open("./main.c", O_RDWR);
    
    // char *buf = (char*)malloc(15*sizeof(char));
    char *buf;
    buf = mmap(0, 12, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);

    if(buf == MAP_FAILED){
        printf("error");
        return 1;
    }
    
    *(buf+5) = *(buf+5)+1;
    
    printf("%s\npagesize %d\n", buf, getpagesize());

    // printf("%s\n", str);
    
    // getwd(curdir);
    // printf("curdir %s\n", curdir);
    // listdir(".");
    // chdir("..");
    // getwd(curdir);
    // printf("curdir before chdir %s\n", curdir);
    // listdir("..");
    
    int count = 0;
    while (*(str+count++));
    
    char *s2 = (char*)malloc(count * sizeof(char));
    
    int i = 0;
    while(*(s2+i) = *(str+i))
        i++;
    
    *(s2+1) = 'q';
    
    // printf("%s %d\n", s2, count);
}


#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>

int main(int argc,char *argv[]){
     int n;
     char buffer[1024];
     if(argc < 2){
     	printf("No proper execution ");
     	return 1;
     }
     int fd = open(argv[1],O_RDONLY);
     if(fd == -1){
     	perror("open");
     	return 1;	
     }
     while((n=read(fd,buffer,sizeof(buffer)))>0){
     	write(1,buffer,n);
     }
     return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc , char *argv[]){
    if(argc < 2){
    	printf("NO prpoper execution (incorrect format)");
    	return 1;
    }
    if(rename(argv[1],argv[2]) == 0){
    	printf("mv done");
    	return 0;
    }
    else{
    	perror("rename");
    	return 1;
    }
}

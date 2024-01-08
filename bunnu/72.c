#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(){
	
    int pid;
    pid = fork();
    if(pid > 0 ){
    	sleep(10);
    	printf("hello zombie");	
    }
    else{
    	exit(0);
    }
    return 0;
}

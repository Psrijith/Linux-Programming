#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
    int pid;
    pid = fork();
    if(pid == -1){
    	printf("NO");
    	return 1;
    }	
    if(pid == 0){
    	printf("I am childp = %d \n",pid);
    }
    else {
    	printf("I am parent =  %d ",pid);
    }
    return 0;
}

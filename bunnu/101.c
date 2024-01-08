#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void sig_alarm(int signo) {
    printf("Received SIGALRM - Alarm signal\n");
}

int main() {
    signal(SIGALRM, sig_alarm);
    alarm(3);

    for (int n = 0; n < 6; n++) {
        printf("from for loop n = %d\n", n);
        sleep(1);
    }

    printf("Main program terminated\n");

    return 0;
}


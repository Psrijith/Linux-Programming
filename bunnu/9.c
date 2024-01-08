#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/msg.h>

#define MAX_MSG_SIZE 256

struct msg {
    long type;  // Change data type to long
    char text[MAX_MSG_SIZE];
};

int main() {
    struct msg message;
    int msgid;
    msgid = msgget(IPC_PRIVATE, IPC_CREAT | 0666);
    if (msgid == -1) {
        perror("msgget");
        return 0;
    }

    for (int i = 1; i <= 3; i++) {
        message.type = i;  // Change field name to 'type'
        sprintf(message.text, "Message with priority %d", i);

        if (msgsnd(msgid, &message, sizeof(struct msg) - sizeof(long), 0) == -1) {
            perror("msgsnd");
            return 0;
        }
    }

    printf("Reading messages from the queue:\n");

    for (int i = 1; i <= 3; i++) {
        if (msgrcv(msgid, &message, sizeof(struct msg) - sizeof(long), i, 0) == -1) {
            perror("msgrcv");
            return 0;
        }

        printf("Priority %ld: %s\n", message.type, message.text);
    }
    return 0;
}

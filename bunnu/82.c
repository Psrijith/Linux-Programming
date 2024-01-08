#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    int pfds[2];
    char buf[80];

    // Create a pipe
    if (pipe(pfds) == -1) {
        perror("pipe failed");
        exit(1);
    }

    // Child process
    if (!fork()) {
        // Close the read end of the pipe
        close(pfds[0]);

        // Redirect stdout to the write end of the pipe
        close(1);
        dup(pfds[1]);
        close(pfds[1]);

        // Execute the "ls -l" command
        execlp("ls", "ls", "-l", NULL);
    } else {
        // Parent process
        // Close the write end of the pipe
        close(pfds[1]);

        printf("Parent reading from pipe:\n");

        // Read from the pipe and print the output
        while (read(pfds[0], buf, 80) > 0) {
            printf("%s\n", buf);
        }

        // Close the read end of the pipe
        close(pfds[0]);
    }

    return 0;
}


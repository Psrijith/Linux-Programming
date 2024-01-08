#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    FILE *sourceFile, *destinationFile;
    char buffer[BUFFER_SIZE];
    size_t bytesRead;
 
    if (argc != 3) {
        printf("Usage:<source_file> <destination_file>\n");
        exit(EXIT_FAILURE);
    }
 
    sourceFile = fopen(argv[1], "rb");
    if (sourceFile == NULL) {
        perror("Error opening source file");
        exit(EXIT_FAILURE);
    }
 
    destinationFile = fopen(argv[2], "wb");
    if (destinationFile == NULL) {
        perror("Error opening destination file"); 
        exit(EXIT_FAILURE);
    } 
    while ((bytesRead = fread(buffer, 1, sizeof(buffer), sourceFile)) > 0) {
        fwrite(buffer, 1, bytesRead, destinationFile);
    }

    printf("File copy successful: %s -> %s\n", argv[1], argv[2]);

    return 0;
}


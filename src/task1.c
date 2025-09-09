#include "task1.h"
#include <stdio.h>

void print_file_position(FILE *file) {
    long position = ftell(file);
    if (position == -1L) {
        perror("Error getting file position");
        return;
    }
    printf("Current file position: %ld\n", position);
}
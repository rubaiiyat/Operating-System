#include <stdio.h>

int main() {
    int start, length, i;

    int disk[100] = {0}; // 0 = free, 1 = allocated

    printf("Enter starting block: ");
    scanf("%d", &start);

    printf("Enter length of the file: ");
    scanf("%d", &length);

    // Check if space is free
    for (i = start; i < start + length; i++) {
        if (disk[i] == 1) {
            printf("Error: Block %d already allocated!\n", i);
            return 0;
        }
    }

    // Allocate blocks
    for (i = start; i < start + length; i++) {
        disk[i] = 1;
    }

    printf("\nFile allocated successfully!\nAllocated blocks: ");
    for (i = start; i < start + length; i++) {
        printf("%d ", i);
    }
    printf("\n");

    return 0;
}

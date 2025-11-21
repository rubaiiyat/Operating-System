#include <stdio.h>

int main() {
    int pages[30], frames[10];
    int n, f, i, j, k, pageFaults = 0;
    int index = 0;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter the page sequence: ");
    for(i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    // Initialize frames
    for(i = 0; i < f; i++)
        frames[i] = -1;

    for(i = 0; i < n; i++) {
        int found = 0;

        // Check if page already exists
        for(j = 0; j < f; j++) {
            if(frames[j] == pages[i]) {
                found = 1;
                break;
            }
        }

        if(!found) {
            frames[index] = pages[i];
            index = (index + 1) % f;
            pageFaults++;
        }

        // Print frames
        printf("Step %d: ", i+1);
        for(k = 0; k < f; k++)
            printf("%d ", frames[k]);
        printf("\n");
    }

    printf("Total Page Faults = %d\n", pageFaults);

    return 0;
}
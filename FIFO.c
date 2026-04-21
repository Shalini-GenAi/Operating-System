#include <stdio.h>

void fifoPageReplacement(int pages[], int n, int capacity) {
    int frame[capacity];   // Memory frames
    int front = 0;         // Points to the oldest page
    int count = 0;         // Number of pages currently in frame
    int pageFaults = 0;

    // Initialize frames with -1 (empty)
    for (int i = 0; i < capacity; i++)
        frame[i] = -1;

    printf("\nPage\tFrames\t\tPage Fault\n");

    for (int i = 0; i < n; i++) {
        int currentPage = pages[i];
        int found = 0;

        // Check if page is already in frame
        for (int j = 0; j < capacity; j++) {
            if (frame[j] == currentPage) {
                found = 1;
                break;
            }
        }

        // If not found, replace using FIFO
        if (!found) {
            frame[front] = currentPage;
            front = (front + 1) % capacity; // Move pointer circularly
            pageFaults++;
        }

        // Print current status
        printf("%d\t", currentPage);
        for (int j = 0; j < capacity; j++) {
            if (frame[j] != -1)
                printf("%d ", frame[j]);
            else
                printf("- ");
        }
        if (!found)
            printf("\t\tYes");
        else
            printf("\t\tNo");
        printf("\n");
    }

    printf("\nTotal Page Faults = %d\n", pageFaults);
}

int main() {
    int pages[] = {1, 3, 0, 3, 5, 6, 3}; // Reference string
    int n = sizeof(pages) / sizeof(pages[0]);
    int capacity = 3; // Number of frames

    printf("Reference String: ");
    for (int i = 0; i < n; i++) printf("%d ", pages[i]);
    printf("\nFrame Capacity: %d\n", capacity);

    fifoPageReplacement(pages, n, capacity);

    return 0;
}

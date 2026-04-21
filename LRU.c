#include <stdio.h>

int findLRU(int time[], int n) {
    int i, minimum = time[0], pos = 0;
    for (i = 1; i < n; ++i) {
        if (time[i] < minimum) {
            minimum = time[i];
            pos = i;
        }
    }
    return pos;
}

void lruPageReplacement(int pages[], int n, int capacity) {
    int frame[capacity], time[capacity];
    int counter = 0, pageFaults = 0;
    int i, j, pos;

    for (i = 0; i < capacity; ++i) {
        frame[i] = -1;
    }

    printf("\nPage\tFrames\t\tPage Fault\n");

    for (i = 0; i < n; ++i) {
        int currentPage = pages[i];
        int found = 0;

        // Check if page is already in frame
        for (j = 0; j < capacity; ++j) {
            if (frame[j] == currentPage) {
                counter++;
                time[j] = counter;
                found = 1;
                break;
            }
        }

        // If not found, replace using LRU
        if (!found) {
            if (pageFaults < capacity) {
                frame[pageFaults] = currentPage;
                counter++;
                time[pageFaults] = counter;
            } else {
                pos = findLRU(time, capacity);
                frame[pos] = currentPage;
                counter++;
                time[pos] = counter;
            }
            pageFaults++;
        }

        // Print current status
        printf("%d\t", currentPage);
        for (j = 0; j < capacity; ++j) {
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
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3};
    int n = sizeof(pages) / sizeof(pages[0]);
    int capacity = 3; // Number of frames

    printf("Reference String: ");
    for (int i = 0; i < n; i++) printf("%d ", pages[i]);
    printf("\nFrame Capacity: %d\n", capacity);

    lruPageReplacement(pages, n, capacity);

    return 0;
}

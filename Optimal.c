#include <stdio.h>

int predict(int pages[], int n, int frame[], int capacity, int index) {
    int res = -1, farthest = index;
    for (int i = 0; i < capacity; i++) {
        int j;
        for (j = index; j < n; j++) {
            if (frame[i] == pages[j]) {
                if (j > farthest) {
                    farthest = j;
                    res = i;
                }
                break;
            }
        }
        if (j == n) // If page not found in future
            return i;
    }
    return (res == -1) ? 0 : res;
}

void optimalPageReplacement(int pages[], int n, int capacity) {
    int frame[capacity];
    int pageFaults = 0;
    int i, j;

    for (i = 0; i < capacity; i++)
        frame[i] = -1;

    printf("\nPage\tFrames\t\tPage Fault\n");

    for (i = 0; i < n; i++) {
        int currentPage = pages[i];
        int found = 0;

        // Check if page is already in frame
        for (j = 0; j < capacity; j++) {
            if (frame[j] == currentPage) {
                found = 1;
                break;
            }
        }

        // If not found, replace using Optimal
        if (!found) {
            if (pageFaults < capacity) {
                frame[pageFaults] = currentPage;
            } else {
                int pos = predict(pages, n, frame, capacity, i + 1);
                frame[pos] = currentPage;
            }
            pageFaults++;
        }

        // Print current status
        printf("%d\t", currentPage);
        for (j = 0; j < capacity; j++) {
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

    optimalPageReplacement(pages, n, capacity);

    return 0;
}

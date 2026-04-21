#include <stdio.h>

void bestFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[n]; // Stores block index for each process
    for (int i = 0; i < n; i++)
        allocation[i] = -1; // Initially no allocation

    // For each process
    for (int i = 0; i < n; i++) {
        int bestIdx = -1;
        for (int j = 0; j < m; j++) {
            if (blockSize[j] >= processSize[i]) {
                if (bestIdx == -1 || blockSize[j] < blockSize[bestIdx]) {
                    bestIdx = j;
                }
            }
        }

        // If found, allocate
        if (bestIdx != -1) {
            allocation[i] = bestIdx;
            blockSize[bestIdx] -= processSize[i];
        }
    }

    // Print results
    printf("\nProcess No.\tProcess Size\tBlock No.\n");
    for (int i = 0; i < n; i++) {
        if (allocation[i] != -1)
            printf("%d\t\t%d\t\t%d\n", i + 1, processSize[i], allocation[i] + 1);
        else
            printf("%d\t\t%d\t\tNot Allocated\n", i + 1, processSize[i]);
    }
}

int main() {
    int blockSize[] = {100, 500, 200, 300, 600}; // Memory blocks
    int processSize[] = {212, 417, 112, 426};    // Processes
    int m = sizeof(blockSize) / sizeof(blockSize[0]);
    int n = sizeof(processSize) / sizeof(processSize[0]);

    printf("Memory Blocks: ");
    for (int i = 0; i < m; i++) printf("%d ", blockSize[i]);
    printf("\nProcesses: ");
    for (int i = 0; i < n; i++) printf("%d ", processSize[i]);

    bestFit(blockSize, m, processSize, n);

    return 0;
}

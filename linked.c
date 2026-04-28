#include <stdio.h>

int main() {
    int memory[50], n, i, blocks[10];

    // Initialize memory blocks as free
    for(i = 0; i < 50; i++) {
        memory[i] = 0;
    }

    printf("Enter number of blocks: ");
    scanf("%d", &n);

    printf("Enter block numbers: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &blocks[i]);
    }

    // Check if blocks are free
    for(i = 0; i < n; i++) {
        if(memory[blocks[i]] == 1) {
            printf("Allocation failed. Block %d already allocated.\n", blocks[i]);
            return 0;
        }
    }

    // Allocate blocks
    for(i = 0; i < n; i++) {
        memory[blocks[i]] = 1;
    }

    // Display linked allocation
    printf("File allocated successfully.\n");
    printf("Linked blocks: ");

    for(i = 0; i < n - 1; i++) {
        printf("%d -> ", blocks[i]);
    }
    printf("%d -> NULL", blocks[n - 1]);

    return 0;
}

#include <stdio.h>

int main() {
    int memory[50], indexBlock, n, i, blocks[10];

    // Initialize all blocks as free
    for(i = 0; i < 50; i++) {
        memory[i] = 0;
    }

    printf("Enter index block: ");
    scanf("%d", &indexBlock);

    if(memory[indexBlock] == 1) {
        printf("Index block already allocated.\n");
        return 0;
    }

    printf("Enter number of blocks needed: ");
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

    // Allocate index block and file blocks
    memory[indexBlock] = 1;
    for(i = 0; i < n; i++) {
        memory[blocks[i]] = 1;
    }

    printf("File allocated successfully.\n");
    printf("Index Block: %d\n", indexBlock);
    printf("Blocks allocated: ");
    for(i = 0; i < n; i++) {
        printf("%d ", blocks[i]);
    }

    return 0;
}

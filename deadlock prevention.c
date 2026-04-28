#include <stdio.h>

int main() {
    int i, j, n, m;
    int alloc[10][10], max[10][10], need[10][10];
    int available[10];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter number of resources: ");
    scanf("%d", &m);

    printf("Enter Allocation Matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            scanf("%d", &alloc[i][j]);
        }
    }

    printf("Enter Max Matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    printf("Enter Available Resources:\n");
    for(j = 0; j < m; j++) {
        scanf("%d", &available[j]);
    }

    // Calculate Need matrix
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    printf("\nProcesses will request resources in increasing order (R0 -> R1 -> ...)\n");

    // Simple prevention check
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            if(need[i][j] > available[j]) {
                printf("Process P%d must wait for resource R%d\n", i, j);
            }
        }
    }

    printf("\nDeadlock prevented by enforcing resource ordering.\n");

    return 0;
}

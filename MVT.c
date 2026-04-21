#include <stdio.h>

int main() {
    int ms, mp[10], i, temp, n;
    int allocated[10];

    printf("Enter the total memory available (in Bytes) -- ");
    scanf("%d", &ms);

    temp = ms; // available memory

    printf("Enter the number of processes -- ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter memory required for process %d (in Bytes) -- ", i + 1);
        scanf("%d", &mp[i]);
        allocated[i] = 0;
    }

    printf("\nPROCESS\tMEMORY REQUIRED\tALLOCATED\tAVAILABLE MEMORY\n");

    for (i = 0; i < n; i++) {
        printf("%d\t\t%d", i + 1, mp[i]);

        if (mp[i] <= temp) {
            allocated[i] = 1;
            temp = temp - mp[i];
            printf("\t\tYES\t\t%d\n", temp);
        } else {
            printf("\t\tNO\t\t---\n");
        }
    }

    printf("\nTotal Memory Available = %d", ms);
    printf("\nTotal Memory Allocated = %d", ms - temp);
    printf("\nTotal Memory Remaining = %d\n", temp);

    return 0;
}

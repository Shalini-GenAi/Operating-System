#include <stdio.h>
#include <stdlib.h>

int main() {
    int queue[20], n, head, i;
    int seek = 0, diff;

    printf("Enter number of disk requests: ");
    scanf("%d", &n);

    printf("Enter disk request queue: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &queue[i]);
    }

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("\nOrder of servicing:\n");

    for(i = 0; i < n; i++) {
        diff = abs(queue[i] - head);
        seek += diff;
        head = queue[i];

        printf("%d ", head);
    }

    printf("\n\nTotal Seek Time = %d\n", seek);

    return 0;
}

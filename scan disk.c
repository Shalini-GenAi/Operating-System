#include <stdio.h>
#include <stdlib.h>

int main() {
    int queue[20], n, head, i, j, temp;
    int size = 200; // disk size (0 to 199)
    int seek = 0, diff;
    int left[20], right[20];
    int l = 0, r = 0;

    printf("Enter number of disk requests: ");
    scanf("%d", &n);

    printf("Enter disk request queue: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &queue[i]);
    }

    printf("Enter initial head position: ");
    scanf("%d", &head);

    // Add boundary values
    queue[n++] = 0;
    queue[n++] = size - 1;

    // Sorting queue
    for(i = 0; i < n; i++) {
        for(j = i + 1; j < n; j++) {
            if(queue[i] > queue[j]) {
                temp = queue[i];
                queue[i] = queue[j];
                queue[j] = temp;
            }
        }
    }

    // Divide into left and right of head
    for(i = 0; i < n; i++) {
        if(queue[i] < head)
            left[l++] = queue[i];
        else
            right[r++] = queue[i];
    }

    printf("\nOrder of servicing:\n");

    // Move right first
    for(i = 0; i < r; i++) {
        diff = abs(right[i] - head);
        seek += diff;
        head = right[i];
        printf("%d ", head);
    }

    // Then move left
    for(i = l - 1; i >= 0; i--) {
        diff = abs(left[i] - head);
        seek += diff;
        head = left[i];
        printf("%d ", head);
    }

    printf("\n\nTotal Seek Time = %d\n", seek);

    return 0;
}

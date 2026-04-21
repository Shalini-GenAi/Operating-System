// Non-Preemptive

#include <stdio.h>

int main() {
    int n, i;
    int at[20], bt[20], ct[20], wt[20], tat[20];
    int completed[20] = {0};
    int time = 0, min_bt, idx;
    float total_wt = 0, total_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("\nProcess %d\n", i+1);
        printf("Arrival Time: ");
        scanf("%d", &at[i]);
        printf("Burst Time: ");
        scanf("%d", &bt[i]);
    }

    int count = 0;
    while(count < n) {
        min_bt = 9999;
        idx = -1;

        // Find shortest job among arrived processes
        for(i = 0; i < n; i++) {
            if(at[i] <= time && completed[i] == 0 && bt[i] < min_bt) {
                min_bt = bt[i];
                idx = i;
            }
        }

        if(idx == -1) {
            time++; // No process has arrived yet
        } else {
            time += bt[idx]; // Run chosen process till completion
            ct[idx] = time;
            tat[idx] = ct[idx] - at[idx];
            wt[idx] = tat[idx] - bt[idx];

            total_wt += wt[idx];
            total_tat += tat[idx];
            completed[idx] = 1;
            count++;
        }
    }

    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT");
    for(i = 0; i < n; i++) {
        printf("\nP%d\t%d\t%d\t%d\t%d\t%d",
               i+1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("\n\nAverage Waiting Time = %.2f", total_wt/n);
    printf("\nAverage Turnaround Time = %.2f\n", total_tat/n);

    return 0;
}

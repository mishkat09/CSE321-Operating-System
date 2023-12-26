#include <stdio.h>

int main() {
    int n, bt[10], at[10], pp[10], wt[10], tat[10], ct[10], p[10];
    float awt = 0, atat = 0;

    FILE *fp = fopen("priority_input.txt", "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening the file.\n");
        return 1; 
    }

    fscanf(fp, "%d", &n);

    for (int i = 0; i < n; i++) {
        fscanf(fp, "%d %d %d", &bt[i], &at[i], &pp[i]);
        p[i] = i + 1;
    }

    fclose(fp);

    // Sort the processes by priority in descending order
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (pp[i] < pp[j]) {
                int temp = pp[i];
                pp[i] = pp[j];
                pp[j] = temp;
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;
                temp = at[i];
                at[i] = at[j];
                at[j] = temp;
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    ct[0] = bt[0] + at[0];
    tat[0] = ct[0] - at[0];
    wt[0] = tat[0] - bt[0];

    for (int i = 1; i < n; i++) {
        int minPriorityIndex = i;

        for (int j = i + 1; j < n; j++) {
            if (pp[j] > pp[minPriorityIndex] && at[j] <= ct[i - 1]) {
                minPriorityIndex = j;
            }
        }

        ct[minPriorityIndex] = ct[i - 1] + bt[minPriorityIndex];
        tat[minPriorityIndex] = ct[minPriorityIndex] - at[minPriorityIndex];
        wt[minPriorityIndex] = tat[minPriorityIndex] - bt[minPriorityIndex];
        pp[minPriorityIndex] = -1; // Set the priority to -1 so that it is not selected again
    }

    printf("\nProcess\tBurst Time\tArrival Time\tPriority\tCompletion Time\tTurnaround Time\tWaiting Time\n");

    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i], bt[i], at[i], pp[i], ct[i], tat[i], wt[i]);
        awt += wt[i];
        atat += tat[i];
    }

    awt /= n;
    atat /= n;

    printf("\nAverage Waiting Time: %.2f", awt);
    printf("\nAverage Turnaround Time: %.2f\n", atat);

    return 0;
}


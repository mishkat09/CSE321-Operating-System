#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

struct Process {
    int pid;
    int bt;
    int art;
};

void findWaitingTime(struct Process proc[], int n, int wt[]) {
    int rt[n];

        for (int i = 0; i < n; i++)
                rt[i] = proc[i].bt;

        int complete = 0, t = 0, minm = INT_MAX;
        int shortest = 0, finish_time;
        bool check = false;

        while (complete != n) {
            for (int j = 0; j < n; j++) {
                if ((proc[j].art <= t) && (rt[j] < minm) && rt[j] > 0) {
                    minm = rt[j];
                    shortest = j;
                    check = true;
                }
            }

            if (check == false) {
                t++;
                continue;
            }

            rt[shortest]--;

            minm = rt[shortest];
            if (minm == 0)
                minm = INT_MAX;

            if (rt[shortest] == 0) {
                complete++;
                check = false;

                finish_time = t + 1;

                wt[shortest] = finish_time - proc[shortest].bt - proc[shortest].art;

                if (wt[shortest] < 0)
                    wt[shortest] = 0;
            }

            t++;
        }
}

void findTurnAroundTime(struct Process proc[], int n, int wt[], int tat[]) {
    for (int i = 0; i < n; i++)
        tat[i] = proc[i].bt + wt[i];
}

void findCompletionTime(struct Process proc[], int n, int ct[], int tat[]) {
    for (int i = 0; i < n; i++) {
        ct[i] = proc[i].art + tat[i];
    }
}

void findavgTime(struct Process proc[], int n) {
     int wt[n], tat[n], ct[n];
    int total_wt = 0, total_tat = 0;

    findWaitingTime(proc, n, wt);
    findTurnAroundTime(proc, n, wt, tat);
    findCompletionTime(proc, n, ct, tat);

    printf("Processes\t Burst time\t Arrival time\t Completion time\t Waiting time\t Turn around time\n");

    for (int i = 0; i < n; i++) {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        printf("%d\t\t %d\t\t %d\t\t %d\t\t\t %d\t\t %d\n", proc[i].pid, proc[i].bt, proc[i].art, ct[i], wt[i], tat[i]);
    }

    printf("Average waiting time = %f\n", (float) total_wt / (float) n);
    printf("Average turn around time = %f\n", (float) total_tat / (float) n);
}



int main() {
    FILE *fp = fopen("sjf_input.txt", "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening the file.\n");
        return 1; 
    }

    int n;
    fscanf(fp, "%d", &n);

    struct Process proc[n];

    for (int i = 0; i < n; i++) {
        int temp;
        fscanf(fp, "%d %d %d", &proc[i].pid, &proc[i].bt, &proc[i].art);
    }

    fclose(fp);

    findavgTime(proc, n);

    return 0;
}
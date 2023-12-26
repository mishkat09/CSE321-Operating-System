#include <stdio.h>

int main() {
    int i, number_of_processes, sum = 0, count = 0, y, time_quantum, waiting_time = 0, turn_around_time = 0, arrival_time[10], burst_time[10], temp[10];
    float average_waiting_time, average_turn_around_time, completion_time = 0, average_completion_time;

    FILE *fp = fopen("rr_input.txt", "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening the file.\n");
        return 1; 
    }

    fscanf(fp, "%d", &number_of_processes);
    y = number_of_processes;

    for (i = 0; i < number_of_processes; i++) {
        fscanf(fp, "%d %d", &arrival_time[i], &burst_time[i]);
        temp[i] = burst_time[i];
    }

    fclose(fp);

    printf("Enter the time quantum for the process: ");
    scanf("%d", &time_quantum);

    printf("\nProcess No\tBurst Time\tTAT\tWaiting Time");
    for (sum = 0, i = 0; y != 0;) {
        if (temp[i] <= time_quantum && temp[i] > 0) {
            sum = sum + temp[i];
            temp[i] = 0;
            count = 1;
        } else if (temp[i] > 0) {
            temp[i] = temp[i] - time_quantum;
            sum = sum + time_quantum;
        }
        if (temp[i] == 0 && count == 1) {
            y--;
            printf("\n%d\t\t%d\t\t%d\t\t%d", i + 1, burst_time[i], sum - arrival_time[i], sum - arrival_time[i] - burst_time[i]);
            waiting_time = waiting_time + sum - arrival_time[i] - burst_time[i];
            turn_around_time = turn_around_time + sum - arrival_time[i];
            completion_time = completion_time + sum;
            count = 0;
        }
        if (i == number_of_processes - 1) {
            i = 0;
        } else if (arrival_time[i + 1] <= sum) {
            i++;
        } else {
            i = 0;
        }
    }

    average_waiting_time = waiting_time * 1.0 / number_of_processes;
    average_turn_around_time = turn_around_time * 1.0 / number_of_processes;
    average_completion_time = completion_time * 1.0 / number_of_processes;
    printf("\nAverage Completion Time: %.2f", average_completion_time);
    printf("\nAverage Turn Around Time: %.2f", average_turn_around_time);
    printf("\nAverage Waiting Time: %.2f\n", average_waiting_time);

    getchar(); // to wait for the user to press Enter before exiting
    return 0;
}


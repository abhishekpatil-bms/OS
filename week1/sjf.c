#include <stdio.h>

int main() {
    int n;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int arrival_time[n], burst_time[n], waiting_time[n], turnaround_time[n], completion_time[n];

    for (int i = 0; i < n; i++) {
        printf("Enter arrival time and burst time for process P%d: ", i + 1);
        scanf("%d %d", &arrival_time[i], &burst_time[i]);
        completion_time[i] = 0;
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arrival_time[i] > arrival_time[j] || 
               (arrival_time[i] == arrival_time[j] && burst_time[i] > burst_time[j])) {
                int temp = arrival_time[i];
                arrival_time[i] = arrival_time[j];
                arrival_time[j] = temp;
                
                temp = burst_time[i];
                burst_time[i] = burst_time[j];
                burst_time[j] = temp;
            }
        }
    }

    int total_time = 0;
    for (int completed = 0; completed < n;) {
        int idx = -1;
        for (int i = 0; i < n; i++) {
            if (arrival_time[i] <= total_time && completion_time[i] == 0) {
                if (idx == -1 || burst_time[i] < burst_time[idx]) {
                    idx = i;
                }
            }
        }
        
        if (idx != -1) {
            completion_time[idx] = total_time + burst_time[idx];
            turnaround_time[idx] = completion_time[idx] - arrival_time[idx];
            waiting_time[idx] = turnaround_time[idx] - burst_time[idx];
            total_time = completion_time[idx];
            completed++;
        } else {
            total_time++;
        }
    }

    float total_waiting = 0, total_turnaround = 0;
    printf("\nProcess | Arrival Time | Burst Time | Waiting Time | Turnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d      | %d            | %d          | %d            | %d\n", 
                i + 1, arrival_time[i], burst_time[i], waiting_time[i], turnaround_time[i]);
        total_waiting += waiting_time[i];
        total_turnaround += turnaround_time[i];
    }

    printf("\nAvg Waiting Time: %.2f\n", total_waiting / n);
    printf("Avg Turnaround Time: %.2f\n", total_turnaround / n);

    return 0;
}
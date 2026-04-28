#include <stdio.h>

// Structure to store process details
typedef struct {
    int pid;
    int arrival;
    int burst;
    int end_time;      // Completion Time
    int waiting;
    int turnaround;
} Process;

int main() {
    int n;
    float total_wt = 0, total_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    Process p[n];

    // 🔹 Input
    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;

        printf("Enter Arrival Time for P%d: ", p[i].pid);
        scanf("%d", &p[i].arrival);

        printf("Enter Burst Time for P%d: ", p[i].pid);
        scanf("%d", &p[i].burst);
    }

    // 🔹 Sort by Arrival Time (FCFS rule)
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (p[i].arrival > p[j].arrival) {
                Process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    int current_time = 0;

    // 🔹 Execute processes in order
    for (int i = 0; i < n; i++) {

        // If CPU is idle, jump to arrival time
        if (current_time < p[i].arrival)
            current_time = p[i].arrival;

        // Execute process completely
        current_time += p[i].burst;

        p[i].end_time = current_time;

        // TAT = ET - AT
        p[i].turnaround = p[i].end_time - p[i].arrival;

        // WT = TAT - BT
        p[i].waiting = p[i].turnaround - p[i].burst;

        total_wt += p[i].waiting;
        total_tat += p[i].turnaround;
    }

    // 📊 Output
    printf("\nProcess\tAT\tBT\tET\tWT\tTAT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].pid,
               p[i].arrival,
               p[i].burst,
               p[i].end_time,
               p[i].waiting,
               p[i].turnaround);
    }

    printf("\nAverage Waiting Time = %.2f", total_wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", total_tat / n);

    return 0;
}

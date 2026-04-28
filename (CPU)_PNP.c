#include <stdio.h>
#include <limits.h>

typedef struct {
    int pid;
    int arrival;
    int burst;
    int priority;
    int end_time;      // Completion Time
    int waiting;
    int turnaround;
    int done;          // To check completion
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
        p[i].done = 0;

        printf("Enter Arrival Time for P%d: ", p[i].pid);
        scanf("%d", &p[i].arrival);

        printf("Enter Burst Time for P%d: ", p[i].pid);
        scanf("%d", &p[i].burst);

        printf("Enter Priority for P%d: ", p[i].pid);
        scanf("%d", &p[i].priority);
    }

    int current_time = 0, completed = 0;

    // 🔹 Main loop
    while (completed < n) {

        int idx = -1;
        int highest_priority = INT_MAX; // lower value = higher priority

        // 🔍 Find highest priority process among arrived
        for (int i = 0; i < n; i++) {
            if (p[i].arrival <= current_time && !p[i].done) {

                if (p[i].priority < highest_priority) {
                    highest_priority = p[i].priority;
                    idx = i;
                }
            }
        }

        // ❗ CPU idle
        if (idx == -1) {
            current_time++;
            continue;
        }

        // ▶️ Execute selected process completely (no preemption)
        current_time += p[idx].burst;

        p[idx].end_time = current_time;

        // TAT = ET - AT
        p[idx].turnaround = p[idx].end_time - p[idx].arrival;

        // WT = TAT - BT
        p[idx].waiting = p[idx].turnaround - p[idx].burst;

        total_wt += p[idx].waiting;
        total_tat += p[idx].turnaround;

        p[idx].done = 1;
        completed++;
    }

    // 📊 Output
    printf("\nProcess\tAT\tBT\tPR\tET\tWT\tTAT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].pid,
               p[i].arrival,
               p[i].burst,
               p[i].priority,
               p[i].end_time,
               p[i].waiting,
               p[i].turnaround);
    }

    printf("\nAverage Waiting Time = %.2f", total_wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", total_tat / n);

    return 0;
}

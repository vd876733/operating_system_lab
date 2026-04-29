#include <stdio.h>
#include <limits.h>

typedef struct {
    int pid;
    int arrival;
    int burst;
    int remaining;
    int end_time;
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

        p[i].remaining = p[i].burst;
    }

    int current_time = 0, completed = 0;

    // 🔹 Main loop
    while (completed < n) {

        int idx = -1;
        int min_remain = INT_MAX;

        // 🔍 Selection using 2 IFs
        for (int i = 0; i < n; i++) {
            if (p[i].arrival <= current_time && p[i].remaining > 0) {

                // 1️⃣ Smaller remaining time
                if (idx == -1 || p[i].remaining < min_remain) {
                    min_remain = p[i].remaining;
                    idx = i;
                }

                // 2️⃣ Tie-breaker: earlier arrival
                else if (p[i].remaining == min_remain &&
                         p[i].arrival < p[idx].arrival) {
                    idx = i;
                }
            }
        }

        // ❗ CPU idle
        if (idx == -1) {
            current_time++;
            continue;
        }

        // ▶️ Execute for 1 unit
        p[idx].remaining--;
        current_time++;

        // 🔹 Completion
        if (p[idx].remaining == 0) {
            completed++;

            p[idx].end_time = current_time;
            p[idx].turnaround = p[idx].end_time - p[idx].arrival;
            p[idx].waiting = p[idx].turnaround - p[idx].burst;

            total_wt += p[idx].waiting;
            total_tat += p[idx].turnaround;
        }
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

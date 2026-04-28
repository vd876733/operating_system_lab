#include <stdio.h>

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
    int n, tq;

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

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    int queue[100], front = 0, rear = 0;
    int visited[n];

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    int current_time = 0, completed = 0;

    // 🔹 Push first arriving processes
    for (int i = 0; i < n; i++) {
        if (p[i].arrival == 0) {
            queue[rear++] = i;
            visited[i] = 1;
        }
    }

    // 🔹 Main loop
    while (completed < n) {

        // ❗ If queue empty → move time
        if (front == rear) {
            current_time++;
            for (int i = 0; i < n; i++) {
                if (p[i].arrival <= current_time && !visited[i]) {
                    queue[rear++] = i;
                    visited[i] = 1;
                }
            }
            continue;
        }

        int idx = queue[front++];

        // ▶️ Execute process
        int exec_time = (p[idx].remaining > tq) ? tq : p[idx].remaining;

        p[idx].remaining -= exec_time;
        current_time += exec_time;

        // 🔹 Add newly arrived processes
        for (int i = 0; i < n; i++) {
            if (p[i].arrival <= current_time && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }

        // 🔹 If not finished → push back to queue
        if (p[idx].remaining > 0) {
            queue[rear++] = idx;
        }
        else {
            // 🔹 Process completed
            completed++;
            p[idx].end_time = current_time;

            p[idx].turnaround = p[idx].end_time - p[idx].arrival;
            p[idx].waiting = p[idx].turnaround - p[idx].burst;
        }
    }

    // 📊 Output
    float total_wt = 0, total_tat = 0;

    printf("\nProcess\tAT\tBT\tET\tWT\tTAT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].pid,
               p[i].arrival,
               p[i].burst,
               p[i].end_time,
               p[i].waiting,
               p[i].turnaround);

        total_wt += p[i].waiting;
        total_tat += p[i].turnaround;
    }

    printf("\nAverage Waiting Time = %.2f", total_wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", total_tat / n);

    return 0;
}

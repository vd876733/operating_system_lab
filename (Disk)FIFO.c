#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, head, total_move = 0;
    printf("Enter no of requests: ");
    scanf("%d", &n);
    int req[n];
    printf("Enter request list: ");
    for(int i = 0; i < n; i++) scanf("%d", &req[i]);
    printf("Enter initial head: ");
    scanf("%d", &head);

    printf("\n%-15s | %-10s\n", "Current Head", "Movement");
    printf("%-15d | --\n", head);

    for(int i = 0; i < n; i++) {
        int move = abs(req[i] - head);
        total_move += move;
        printf("%-15d | %-10d\n", req[i], move);
        head = req[i];
    }
    printf("\nTotal movement: %d\n", total_move);
    return 0;
}

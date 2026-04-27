#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, head, total = 0;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    int req[n];

    printf("Enter request queue:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &req[i]);

    printf("Enter initial head: ");
    scanf("%d", &head);

    printf("\nCurrent Head\tMovement\n");
    printf("%d\t\t--\n", head);

    for(int i = 0; i < n; i++){
        int move = abs(head - req[i]);

        printf("%d\t\t%d\n", req[i], move);

        total += move;
        head = req[i];
    }

    printf("Total Movement: %d\n", total);
    return 0;
}

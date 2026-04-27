#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, head, size, total = 0;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    int req[n];

    printf("Enter request queue:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &req[i]);

    printf("Enter initial head: ");
    scanf("%d", &head);

    printf("Enter disk size: ");
    scanf("%d", &size);

    // sort
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            if(req[i]>req[j]){
                int t=req[i]; req[i]=req[j]; req[j]=t;
            }

    int index;
    for(int i=0;i<n;i++)
        if(head < req[i]) { index = i; break; }

    printf("\nCurrent Head\tMovement\n");
    printf("%d\t\t--\n", head);

    // right
    for(int i=index;i<n;i++){
        int move = abs(head - req[i]);
        printf("%d\t\t%d\n", req[i], move);
        total += move;
        head = req[i];
    }

    // go to end
    int move = abs(head - (size-1));
    printf("%d\t\t%d\n", size-1, move);
    total += move;

    // jump to start
    move = size-1;
    printf("0\t\t%d\n", move);
    total += move;
    head = 0;

    // continue
    for(int i=0;i<index;i++){
        move = abs(head - req[i]);
        printf("%d\t\t%d\n", req[i], move);
        total += move;
        head = req[i];
    }

    printf("Total Movement: %d\n", total);
    return 0;
}

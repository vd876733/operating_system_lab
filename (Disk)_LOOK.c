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

    // left
    for(int i=index-1;i>=0;i--){
        int move = abs(head - req[i]);
        printf("%d\t\t%d\n", req[i], move);
        total += move;
        head = req[i];
    }

    printf("Total Movement: %d\n", total);
    return 0;
}

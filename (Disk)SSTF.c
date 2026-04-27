#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(){
    int n ;
    int head;
    int move ;
    int total_move = 0 ;
    
    
    printf("enter no of request:");
    scanf("%d" , &n);
    int req[n];
    int visited[n];
        
    printf("enter request list:");
    for(int i = 0 ; i < n ; i++){
        scanf("%d" , &req[i]);
        visited[i] = 0;
    }
    
        
    printf("enter inital head:");
        scanf("%d" , &head);
        
    
    printf("\n current head \t movement\n");
    printf("%d\t               \t--\n", head); // Prints the starting point
    
    for( int i = 0 ; i < n ; i++){
        int min = INT_MAX;
        int index  = -1;
        for(int j = 0 ; j < n ; j++){
            if(!visited[j]){
                move = abs(head - req[j ]);
                if(move < min){
                    min = move;
                    index = j;
                }
            }
        }
        visited[index] = 1;
        printf("%d\t               \t%d\n" , req[index] , min);
        total_move += min;
        head = req[index];
        
        
    }
    printf("total movement:%d\n" , total_move);
    return 0 ;
}

//82, 170, 43, 140, 24, 16, 190








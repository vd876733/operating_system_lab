#include <stdio.h>

int main() {

    int frames[3], pages[50];
    int n, i, j, pos = 0;
    int faults = 0, flag;

    // 🔹 Input
    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter reference string:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    // 🔹 Initialize frames
    for(i = 0; i < 3; i++)
        frames[i] = -1;

    // 🔹 Simple Table Header
    printf("\nPage\tF1\tF2\tF3\tStatus\n");

    // 🔹 Process each page
    for(i = 0; i < n; i++) {

        flag = 0;

        // 🔍 Check HIT
        for(j = 0; j < 3; j++) {
            if(frames[j] == pages[i]) {
                flag = 1;
                break;
            }
        }

        // ❗ FAULT → Replace using FIFO
        if(flag == 0) {
            frames[pos] = pages[i];      // Replace oldest page
            pos = (pos + 1) % 3;         // Move pointer circularly
            faults++;
        }

        // 🔹 Print row
        printf("%d\t", pages[i]);

        for(j = 0; j < 3; j++) {
            if(frames[j] != -1)
                printf("%d\t", frames[j]);
            else
                printf("-\t");
        }

        if(flag == 0)
            printf("Fault\n");
        else
            printf("Hit\n");
    }

    printf("\nTotal Page Faults = %d\n", faults);

    return 0;
}

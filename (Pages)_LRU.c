#include <stdio.h>

int main() {

    int frames[3], pages[50], time[3];
    int n, i, j, pos;
    int faults = 0, flag;

    // 🔹 Input
    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter reference string:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    // 🔹 Initialize
    for(i = 0; i < 3; i++) {
        frames[i] = -1;
        time[i] = 0;
    }

    // 🔹 Simple Table Header
    printf("\nPage\tF1\tF2\tF3\tStatus\n");

    // 🔹 Process pages
    for(i = 0; i < n; i++) {

        flag = 0;

        // 🔍 Check HIT
        for(j = 0; j < 3; j++) {
            if(frames[j] == pages[i]) {
                flag = 1;
                time[j] = i;   // Update usage
                break;
            }
        }

        // ❗ FAULT → Replace LRU
        if(flag == 0) {
            pos = 0;

            for(j = 1; j < 3; j++) {
                if(time[j] < time[pos])
                    pos = j;
            }

            frames[pos] = pages[i];
            time[pos] = i;
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

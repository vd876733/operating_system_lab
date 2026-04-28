#include <stdio.h>

int main() {

    int frames[3], pages[50];
    int n, i, j, k, pos;
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

        // ❗ FAULT → Replace optimally
        if(flag == 0) {

            int farthest = -1;
            pos = -1;

            // 🔍 Find page used farthest in future
            for(j = 0; j < 3; j++) {

                int found = 0;

                for(k = i + 1; k < n; k++) {
                    if(frames[j] == pages[k]) {

                        if(k > farthest) {
                            farthest = k;
                            pos = j;
                        }

                        found = 1;
                        break;
                    }
                }

                // If page not used again → best to replace
                if(found == 0) {
                    pos = j;
                    break;
                }
            }

            frames[pos] = pages[i];
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

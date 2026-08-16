#include <stdio.h>

int main() {
    int pages[50], frames[10], time[10];
    int n, f, i, j, pos, faults = 0, counter = 0;
    int found, min;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string: ");
    for(i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &f);

    for(i = 0; i < f; i++)
        frames[i] = -1;

    for(i = 0; i < n; i++) {
        found = 0;

        for(j = 0; j < f; j++) {
            if(frames[j] == pages[i]) {
                counter++;
                time[j] = counter;
                found = 1;
                break;
            }
        }

        if(!found) {
            faults++;
            pos = -1;

            for(j = 0; j < f; j++) {
                if(frames[j] == -1) {
                    pos = j;
                    break;
                }
            }

            if(pos == -1) {
                min = time[0];
                pos = 0;

                for(j = 1; j < f; j++) {
                    if(time[j] < min) {
                        min = time[j];
                        pos = j;
                    }
                }
            }

            frames[pos] = pages[i];
            counter++;
            time[pos] = counter;
        }

        printf("%d: ", pages[i]);
        for(j = 0; j < f; j++)
            printf("%d ", frames[j]);
        printf("\n");
    }

    printf("Total Page Faults = %d\n", faults);
    return 0;
}
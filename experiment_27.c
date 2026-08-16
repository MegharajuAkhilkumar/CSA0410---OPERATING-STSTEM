#include <stdio.h>

int main() {
    int pages[50], frames[10];
    int n, f, i, j, k, pos, farthest, next;
    int faults = 0, found;

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

        for(j = 0; j < f; j++)
            if(frames[j] == pages[i])
                found = 1;

        if(!found) {
            faults++;

            for(j = 0; j < f; j++) {
                if(frames[j] == -1) {
                    frames[j] = pages[i];
                    break;
                }
            }

            if(j == f) {
                farthest = -1;
                pos = -1;

                for(j = 0; j < f; j++) {
                    next = n + 1;

                    for(k = i + 1; k < n; k++) {
                        if(frames[j] == pages[k]) {
                            next = k;
                            break;
                        }
                    }

                    if(next > farthest) {
                        farthest = next;
                        pos = j;
                    }
                }

                frames[pos] = pages[i];
            }
        }

        printf("%d: ", pages[i]);
        for(j = 0; j < f; j++)
            printf("%d ", frames[j]);
        printf("\n");
    }

    printf("Total Page Faults = %d\n", faults);
    return 0;
}
#include <stdio.h>

int main() {
    int pages[50], frames[10];
    int n, f, i, j, k = 0, faults = 0, hit;

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
        hit = 0;

        for(j = 0; j < f; j++)
            if(frames[j] == pages[i])
                hit = 1;

        if(!hit) {
            frames[k] = pages[i];
            k = (k + 1) % f;
            faults++;
        }

        printf("%d: ", pages[i]);
        for(j = 0; j < f; j++)
            printf("%d ", frames[j]);
        printf("\n");
    }

    printf("Total Page Faults = %d\n", faults);
    return 0;
}
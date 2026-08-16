#include <stdio.h>
#include <stdlib.h>

int main() {
    int req[50], n, head, size, i, j, temp;
    int movement = 0;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter request queue: ");
    for(i = 0; i < n; i++)
        scanf("%d", &req[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("Enter disk size: ");
    scanf("%d", &size);

    /* Sort requests */
    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {
            if(req[i] > req[j]) {
                temp = req[i];
                req[i] = req[j];
                req[j] = temp;
            }
        }
    }

    printf("\nSeek Sequence: %d", head);

    /* Move towards higher cylinders */
    for(i = 0; i < n; i++) {
        if(req[i] >= head) {
            movement += abs(head - req[i]);
            head = req[i];
            printf(" -> %d", head);
        }
    }

    /* Move to end of disk */
    movement += abs(head - (size - 1));
    head = size - 1;
    printf(" -> %d", head);

    /* Reverse direction */
    for(i = n - 1; i >= 0; i--) {
        if(req[i] < head) {
            movement += abs(head - req[i]);
            head = req[i];
            printf(" -> %d", head);
        }
    }

    printf("\nTotal Head Movement = %d cylinders\n", movement);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

int main() {
    int req[50], n, head, i, movement = 0;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter request queue: ");
    for(i = 0; i < n; i++)
        scanf("%d", &req[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("\nSeek Sequence: %d", head);

    for(i = 0; i < n; i++) {
        movement += abs(head - req[i]);
        head = req[i];
        printf(" -> %d", head);
    }

    printf("\nTotal Head Movement = %d cylinders\n", movement);

    return 0;
}
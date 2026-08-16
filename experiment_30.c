#include <stdio.h>

int main() {
    int block[20], next[20];
    int n, i;

    printf("Enter number of blocks: ");
    scanf("%d", &n);

    printf("Enter block numbers:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &block[i]);

    for(i = 0; i < n - 1; i++)
        next[i] = block[i + 1];

    next[n - 1] = -1;

    printf("\nLinked File Allocation:\n");

    for(i = 0; i < n; i++)
        printf("Block %d -> %d\n", block[i], next[i]);

    printf("First Block = %d\n", block[0]);
    printf("Last Block = %d\n", block[n - 1]);

    return 0;
}
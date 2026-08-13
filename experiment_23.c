#include <stdio.h>

int main() {
    int block[20], process[20];
    int n, m, i, j;

    printf("Enter number of blocks: ");
    scanf("%d", &n);

    printf("Enter block sizes:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &block[i]);

    printf("Enter number of processes: ");
    scanf("%d", &m);

    printf("Enter process sizes:\n");
    for(i = 0; i < m; i++)
        scanf("%d", &process[i]);

    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            if(block[j] >= process[i]) {
                printf("P%d -> B%d\n", i + 1, j + 1);
                block[j] -= process[i];
                break;
            }
        }

        if(j == n)
            printf("P%d -> Not Allocated\n", i + 1);
    }

    return 0;
}
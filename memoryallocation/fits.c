
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int i, j, temp, b[10], c[10], arr, n, ch, a, run = 1;
    printf("\t\t FIRST FIT, BEST FIT, WORST FIT\n");
    printf("Enter number of memory blocks available: ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        printf("Enter the size of block %d: ", i);
        scanf("%d", &b[i]);
        c[i] = b[i];
    }
    while (run) {
        printf("\nEnter the size of arriving block: ");
        scanf("%d", &arr);
        printf("\n1. First fit\t2. Best fit\t3. Worst fit\nEnter your choice: ");
        scanf("%d", &ch);
        a = -1;
        switch (ch) {
            case 1: // First Fit
                for (i = 1; i <= n; i++) {
                    if (c[i] >= arr) {
                        printf("Arriving block is allocated to block %d.\n", i);
                        c[i] -= arr;
                        a = 0;
                        break;
                    }
                }
                if (a == -1)
                    printf("Cannot allocate memory for arriving block\n");
                break;
            case 2: { // Best Fit
                int bestIdx = -1, minFit = 1e9;
                for (i = 1; i <= n; i++) {
                    if (c[i] >= arr && c[i] < minFit) {
                        minFit = c[i];
                        bestIdx = i;
                    }
                }
                if (bestIdx != -1) {
                    printf("Arriving block is allocated to block %d.\n", bestIdx);
                    c[bestIdx] -= arr;
                } else {
                    printf("Cannot allocate memory for arriving block\n");
                }
                break;
            }
            case 3: { // Worst Fit
                int worstIdx = -1, maxFit = -1;
                for (i = 1; i <= n; i++) {
                    if (c[i] >= arr && c[i] > maxFit) {
                        maxFit = c[i];
                        worstIdx = i;
                    }
                }
                if (worstIdx != -1) {
                    printf("Arriving block is allocated to block %d.\n", worstIdx);
                    c[worstIdx] -= arr;
                } else {
                    printf("Cannot allocate memory for arriving block\n");
                }
                break;
            }
            default:
                printf("Enter a valid choice.\n");
                continue;
        }
        printf("Do you want to enter another? 1. Yes  2. No\n");
        scanf("%d", &ch);
        if (ch != 1) {
            printf("\nFinal block sizes:\n");
            for (i = 1; i <= n; ++i)
                printf("Block %d: %d\n", i, c[i]);
            run = 0;
        }
    }
    return 0;
}

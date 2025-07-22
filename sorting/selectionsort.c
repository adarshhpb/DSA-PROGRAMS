#include <stdio.h>

int main(void) {
    int a[20], n, i, j, temp, min;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &a[i]);
    }
    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            if (a[min] > a[j]) {
                min = j;
            }
        }
        if (min != i) {
            temp = a[min];
            a[min] = a[i];
            a[i] = temp;
        }
    }
    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d\t", a[i]);
    }
    printf("\n");
    return 0;
}

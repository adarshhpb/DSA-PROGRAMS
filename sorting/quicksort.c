#include <stdio.h>

int partition(int a[20], int l, int r) {
    int pivot = a[l];
    int i = l + 1, j = r, temp;
    while (1) {
        while (i <= r && a[i] <= pivot) i++;
        while (a[j] > pivot) j--;
        if (i < j) {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        } else {
            break;
        }
    }
    temp = a[l];
    a[l] = a[j];
    a[j] = temp;
    return j;
}
void quicksort(int a[20], int l, int r) {
    if (l < r) {
        int q = partition(a, l, r);
        quicksort(a, l, q - 1);
        quicksort(a, q + 1, r);
    }
}

int main(void) {
    int a[20], n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &a[i]);
    }
    quicksort(a, 0, n - 1);
    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d\t", a[i]);
    }
    printf("\n");
    return 0;
}

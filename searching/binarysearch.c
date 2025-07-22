#include <stdio.h>

// Simple bubble sort for sorting the array before binary search
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main(void)
{
    int a[20], i, n, key, mid, l, r, flag = 0;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &a[i]);
    }

    // Sort the array before binary search
    bubbleSort(a, n);
    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    printf("Enter the element to be searched: ");
    scanf("%d", &key);
    l = 0;
    r = n - 1;
    while (l <= r) {
        mid = (l + r) / 2;
        if (a[mid] == key) {
            flag = 1;
            break;
        } else if (a[mid] < key) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    if (flag == 1) {
        printf("Element is found at index %d (1-based position: %d)\n", mid, mid + 1);
    } else {
        printf("Element not found\n");
    }
    return 0;
}

#include <stdio.h>

int main(void) {
    int a[20], i, n, key, flag = 0;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &a[i]);
    }
    printf("Enter the element to be searched: ");
    scanf("%d", &key);
    for (i = 0; i < n; i++) {
        if (a[i] == key) {
            if (!flag) printf("Element found at position(s): ");
            printf("%d ", i + 1);
            flag = 1;
        }
    }
    if (!flag) {
        printf("Element not found");
    }
    printf("\n");
    return 0;
}

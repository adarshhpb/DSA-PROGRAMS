#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int queue[10], op, r = -1, f = -1, i, n;
    while (1) {
        printf("\nMenu\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display Queue\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &op);
        switch (op) {
            case 1:
                if (r == 9) {
                    printf("Queue is full.\n");
                } else if (r == -1) {
                    r = f = 0;
                    printf("Enter the element: ");
                    scanf("%d", &n);
                    queue[r] = n;
                    printf("%d enqueued.\n", n);
                } else {
                    r = r + 1;
                    printf("Enter the element: ");
                    scanf("%d", &n);
                    queue[r] = n;
                    printf("%d enqueued.\n", n);
                }
                break;
            case 2:
                if (f == -1) {
                    printf("Queue is empty.\n");
                } else if (f == r) {
                    printf("Removed element is: %d\n", queue[f]);
                    f = r = -1;
                } else {
                    printf("Removed element is: %d\n", queue[f]);
                    f = f + 1;
                }
                break;
            case 3:
                if (f == -1) {
                    printf("Queue is empty.\n");
                } else {
                    printf("Queue: ");
                    for (i = f; i <= r; i++)
                        printf("%d ", queue[i]);
                    printf("\n");
                }
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int stack[10], op, i, top = -1, n;
    while (1) {
        printf("\nMenu:\n");
        printf("1. Push an element to stack\n");
        printf("2. Pop an element from stack\n");
        printf("3. Peek top element of stack\n");
        printf("4. Display the entire stack\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &op);
        switch (op) {
            case 1:
                if (top == 9) {
                    printf("Stack overflow.\n");
                } else {
                    printf("Enter the element to push: ");
                    scanf("%d", &n);
                    stack[++top] = n;
                    printf("%d pushed to stack.\n", n);
                }
                break;
            case 2:
                if (top == -1) {
                    printf("Stack underflow.\n");
                } else {
                    printf("Removed element is: %d\n", stack[top--]);
                }
                break;
            case 3:
                if (top == -1) {
                    printf("Stack is empty.\n");
                } else {
                    printf("Top element is: %d\n", stack[top]);
                }
                break;
            case 4:
                if (top == -1) {
                    printf("Stack is empty.\n");
                } else {
                    printf("Stack: ");
                    for (i = top; i >= 0; i--)
                        printf("%d ", stack[i]);
                    printf("\n");
                }
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}

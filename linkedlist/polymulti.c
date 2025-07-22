#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int coeff;
    int expo;
    struct Node *next;
};

struct Node *createNode(int coeff, int expo)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    if (temp == NULL)
    {
        printf("Memory allocation failed");
        exit(1);
    }
    temp->coeff = coeff;
    temp->expo = expo;
    temp->next = NULL;
    return temp;
}

struct Node *insertTerm(struct Node *head, int coeff, int expo)
{
    if (coeff == 0)
    {
        // If the coefficient is zero, do not insert the term
        return head;
    }

    struct Node *temp = createNode(coeff, expo);
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        struct Node *current = head;
        struct Node *prev = NULL;

        // Traverse the polynomial to find the correct position to insert the term
        while (current != NULL && current->expo > expo)
        {
            prev = current;
            current = current->next;
        }

        // Check if a term with the same exponent already exists
        if (current != NULL && current->expo == expo)
        {
            // Add the coefficients of like terms
            current->coeff += coeff;
            free(temp); // Free the memory allocated for the new term
        }
        else
        {
            // Insert the term at the correct position
            temp->next = current;
            if (prev == NULL)
            {
                head = temp;
            }
            else
            {
                prev->next = temp;
            }
        }
    }
    return head;
}

struct Node *multiplyPolynomials(struct Node *poly1, struct Node *poly2)
{
    struct Node *result = NULL;
    struct Node *ptr1 = poly1;

    while (ptr1 != NULL)
    {
        struct Node *ptr2 = poly2;
        while (ptr2 != NULL)
        {
            int newCoeff = ptr1->coeff * ptr2->coeff;
            int newExpo = ptr1->expo + ptr2->expo;
            // Insert the term into the result polynomial
            result = insertTerm(result, newCoeff, newExpo);
            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }

    return result;
}

void displayPolynomial(struct Node *poly)
{
    if (poly == NULL)
    {
        printf("0\n");
        return;
    }

    while (poly != NULL)
    {
        printf("%dx^%d", poly->coeff, poly->expo);
        poly = poly->next;
        if (poly != NULL)
        {
            printf(" + ");
        }
    }
    printf("\n");
}

void freePolynomial(struct Node *poly)
{
    while (poly != NULL)
    {
        struct Node *temp = poly;
        poly = poly->next;
        free(temp);
    }
}

int main()
{
    int m, n, i, j;

    struct Node *poly1 = NULL;
    struct Node *poly2 = NULL;
    struct Node *resultMultiplication = NULL;

    printf("Enter the number of terms of the first polynomial: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        int coeff, expo;
        printf("Enter the coefficient of the first polynomial: ");
        scanf("%d", &coeff);
        printf("Enter the exponent of the first polynomial: ");
        scanf("%d", &expo);
        poly1 = insertTerm(poly1, coeff, expo);
    }

    printf("First polynomial:\n");
    displayPolynomial(poly1);
    printf("\n");

    printf("Enter the number of terms of the second polynomial: ");
    scanf("%d", &m);

    for (j = 0; j < m; j++)
    {
        int coeff, expo;
        printf("Enter the coefficient of the second polynomial: ");
        scanf("%d", &coeff);
        printf("Enter the exponent of the second polynomial: ");
        scanf("%d", &expo);
        poly2 = insertTerm(poly2, coeff, expo);
    }

    printf("Second polynomial:\n");
    displayPolynomial(poly2);
    printf("\n");

    resultMultiplication = multiplyPolynomials(poly1, poly2);

    printf("Resultant polynomial after multiplication:\n");
    displayPolynomial(resultMultiplication);
    printf("\n");

    // Free allocated memory
    freePolynomial(poly1);
    freePolynomial(poly2);
    freePolynomial(resultMultiplication);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *Next;
};
struct node *Head = NULL;

struct node *temp, *ptr, *ptr2;
int item, i, pos;

struct node *createNode()
{
    temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        printf("Memory allocation failed");
        exit(1);
    }
    printf("Enter the data to insert: ");
    scanf("%d", &item);
    temp->data = item;
    temp->Next = NULL;
    return temp;
}

void insertion_head()
{
    temp = createNode();
    if (Head == NULL)
    {
        Head = temp;
    }
    else
    {
        temp->Next = Head;
        Head = temp;
    }
}

void insertion_tail()
{
    temp = createNode();
    if (Head == NULL)
    {
        Head = temp;
    }
    else
    {
        ptr = Head;
        while (ptr->Next != NULL)
        {
            ptr = ptr->Next;
        }
        ptr->Next = temp;
    }
}

void insertion_position()
{
    temp = createNode();
    printf("Enter the position to insert: ");
    scanf("%d", &pos);

    if (pos < 1)
    {
        printf("Invalid position");
        free(temp);
        return;
    }

    if (pos == 1)
    {
        insertion_head();
        return;
    }

    ptr = Head;
    i = 1;

    while (i < pos - 1 && ptr != NULL)
    {
        ptr = ptr->Next;
        i++;
    }

    if (ptr == NULL)
    {
        printf("Invalid position");
        free(temp);
        return;
    }

    temp->Next = ptr->Next;
    ptr->Next = temp;
}

void deletion_head()
{
    if (Head == NULL)
    {
        printf("List is empty");
        return;
    }
    else
    {
        ptr = Head;
        printf("deleted data is:%d", ptr->data);
        Head = Head->Next;

        free(ptr);
    }
}

void deletion_tail()
{
    if (Head == NULL)
    {
        printf("List is empty");
        return;
    }
    else
    {
        ptr = Head;
        ptr2 = NULL;

        while (ptr->Next != NULL)
        {
            ptr2 = ptr;
            ptr = ptr->Next;
        }

        if (ptr2 == NULL)
        {
            printf("deleted data is:%d", ptr->data);
            free(ptr);
            Head = NULL;
        }
        else
        {
            printf("deleted data is:%d", ptr->data);
            ptr2->Next = NULL;
            free(ptr);
        }
    }
}

void deletion_position()
{
    printf("Enter the position to delete: ");
    scanf("%d", &pos);

    if (Head == NULL || pos < 1)
    {
        printf("Invalid position");
        return;
    }

    if (pos == 1)
    {
        deletion_head();
        return;
    }

    ptr = Head;
    i = 1;

    while (i < pos - 1 && ptr != NULL)
    {
        ptr = ptr->Next;
        i++;
    }

    if (ptr == NULL || ptr->Next == NULL)
    {
        printf("Invalid position");
        return;
    }
    ptr2 = ptr->Next;
    ptr->Next = (ptr->Next)->Next;
    printf("deleted data is:%d", ptr2->data);
    free(ptr2);
}

void traverse()
{
ptr=Head;
while(ptr!=NULL)
{
printf("%d\t",ptr->data);
ptr=ptr->Next;
}
printf("\n");
}

int main()
{
    int ch;
    while (1)
    {
        printf("\n\tMenu\t\n");
        printf("1.insertion_head\n2.insertion_tail\n3.insertion_position\n4.deletion_head\n5.deletion_tail\n6.deletion_position\n7.traverse\n8.exit\n");
        printf("\nENTER THE CHOICE:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insertion_head();
            break;
        case 2:
            insertion_tail();
            break;
        case 3:
            insertion_position();
            break;
        case 4:
            deletion_head();
            break;
        case 5:
            deletion_tail();
            break;
        case 6:
            deletion_position();
            break;
         case 7:
            traverse();
            break;
        case 8:
            exit(0);
            break;
        default:
            printf("\nError: No Choice Found.");
            break;
        }
    }

    return 0;
}

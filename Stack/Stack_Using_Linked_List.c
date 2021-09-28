#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

int isEmpty(struct Node *tp)
{
    if (tp == NULL)
    {
        printf("\nNode underflow.");
        return 0;
    }
    return 1;
}

struct Node *push(struct Node *tp)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    if (ptr == NULL)
    {
        printf("\nStack overflow");
        return 0;
    }
    printf("\nEnter data you want to push.");
    scanf("%d", &(ptr->data));
    ptr->next = tp;
    tp = ptr;
    return tp;
}

struct Node *pop(struct Node *tp)
{
    struct Node *p = tp;
    printf("\n%d is sucessfully poped.", tp->data);
    tp = tp->next;
    free(p);
    return tp;
}

void peek(struct Node *tp)
{
    printf("\nPeek -> %d ", tp->data);
}

void main()
{
    int ch;
    system("cls");
    struct Node *top = NULL;

    while (1)
    {
        system("cls");
        printf("\n1.Push.");
        printf("\n2.Pop.");
        printf("\n3.Peek.");
        printf("\n4.Exit.");
        printf("\nEnter your choice.");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            top = push(top);
            break;
        case 2:
            if (isEmpty(top)) top = pop(top);
            break;
        case 3:
            if (isEmpty(top)) peek(top);
            break;
        case 4:
            exit(0);
        }
        getch();
    }
    return;
}
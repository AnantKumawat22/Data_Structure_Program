#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Stack
{
    int size;
    int top;
    int *arr;
};

int isFull(struct Stack *s)
{

    if (s->top == s->size - 1)
    {
        printf("\nStack overflow.");
        return 0;
    }
    return 1;
}

int isEmpty(struct Stack *s)
{

    if (s->top == -1)
    {
        printf("\nStack underflow.");
        return 0;
    }
    return 1;
}

struct Stack *push(struct Stack *s)
{
    s->top++;
    printf("\nEnter data you want to push.");
    scanf("%d", &(s->arr[s->top]));
    return s;
}

struct Stack *pop(struct Stack *s)
{
    printf("\n%d is sucessfully poped.", s->arr[s->top]);
    s->top--;
    return s;
}

void *peek(struct Stack *s)
{
    printf("\nPeek -> %d ", s->arr[s->top]);
}

void main()
{
    int ch;
    system("cls");
    struct Stack *st = (struct Stack *)malloc(sizeof(struct Stack));
    printf("Enter total size of array.");
    scanf("%d", &(st->size));
    st->top = -1;
    st->arr = (int *)malloc(sizeof(int) * st->size);

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
            if (isFull(st))
            {
                st = push(st);
            }
            break;
        case 2:
            if (isEmpty(st))
            {
                st = pop(st);
            }
            break;
        case 3:
            if (isEmpty(st))
            {
                peek(st);
            }
            break;
        case 5:
            exit(0);
        }
        getch();
    }
    return;
}
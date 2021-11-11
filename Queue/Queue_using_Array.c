#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Queue
{
    int f;
    int r;
    int size;
    int *arr;
};

int isFull(struct Queue *q1)
{
    if (q1->r == (q1->size - 1))
    {
        printf("\nQueue is full.");
        return 1;
    }
    return 0;
}

int isEmpty(struct Queue *q1)
{
    if (q1->r == q1->f)
    {
        printf("\nQueue is Empty.");
        return 1;
    }
    return 0;
}

struct Queue *Enqueue(struct Queue *q1)
{
    printf("\nEnter the data you want to insert.");
    scanf("%d", &(q1->arr[++q1->r]));
    return q1;
}

struct Queue *Dequeue(struct Queue *q1)
{
    printf("%d is Dequeued succesfully.", q1->arr[q1->f + 1]);
    q1->f++;
    return q1;
}

void peek(struct Queue *q1)
{
    printf("\nThe front most element in the queue is: %d", q1->arr[q1->f + 1]);
    return;
}

void main()
{
    int ch;
    struct Queue *q1 = (struct Queue *)malloc(sizeof(struct Queue));
    q1->f = q1->r = -1;
    printf("\nEnter the size of queue.");
    scanf("%d", &(q1->size));
    q1->arr = (int *)malloc(sizeof(int) * q1->size);

    while (1)
    {
        system("cls");
        printf("\n1.Enqueue.");
        printf("\n2.Dequeue.");
        printf("\n3.Peek.");
        printf("\n4.Exit.");
        printf("\nEnter your choice.");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            if (!isFull(q1))
                q1 = Enqueue(q1);
            break;
        case 2:
            if (!isEmpty(q1))
                q1 = Dequeue(q1);
            break;
        case 3:
            if (!isEmpty(q1))
                peek(q1);
            break;
        case 4:
            exit(0);
        }
        getch();
    }
    return;
}
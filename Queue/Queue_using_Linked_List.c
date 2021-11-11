#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Queue
{
    int data;
    struct Queue *next;
};

struct Queue *f = NULL, *r = NULL;

int isEmpty()
{
    if (f == NULL)
    {
        printf("\nQueue is Empty.");
        return 1;
    }
    return 0;
}

void Enqueue()
{
    struct Queue *newptr = (struct Queue *)malloc(sizeof(struct Queue));
    if(newptr == NULL){
        printf("\nQueue is full.");
        return;
    }
    printf("\nEnter the data you want to insert.");
    scanf("%d", &(newptr->data));
    newptr->next = NULL;
    if(f == NULL){
        f = r = newptr;   
        return;
    }
    r->next = newptr;
    r = newptr;
    return;
}

void Dequeue()
{
    struct Queue *q = f;
    printf("%d is Dequeued succesfully.", f->data);
    f = f->next;
    free(q);
    return;
}

void peek()
{
    printf("\nThe front most element in the queue is: %d", f->data);
    return;
}

void main()
{
    int ch;
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
            Enqueue();
            break;
        case 2:
            if (!isEmpty())
                Dequeue();
            break;
        case 3:
            if (!isEmpty())
                peek();
            break;
        case 4:
            exit(0);
        }
        getch();
    }
    return;
}
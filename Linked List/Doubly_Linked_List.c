#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

void Traversal(struct Node *head1)
{
    struct Node *p = head1;
    if(head1 == NULL)
    {
        printf("\nList is Empty.");
        return;
    }
    printf("\n");
    while(p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

struct Node *InsertAtFirst(struct Node *head1)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));

    printf("\nEnter data.");
    scanf("%d", (&ptr->data));
    ptr->next = head1;
    ptr->prev = NULL;
    head1->prev = ptr;
    head1 = ptr;
    return head1;
}

struct Node *InsertAtIndex(struct Node *head1)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head1;
    int ind, i = 0;

    printf("\nEnter Index at which you want to insert.");
    scanf("%d", &ind);

    if(ind == 0)
    {
        head1 = InsertAtFirst(head1);
        return head1;
    }
    if(head1 == NULL)
    {
        printf("\nList is Empty.");
        return head1;
    }

    printf("\nEnter data.");
    scanf("%d", (&ptr->data));

    while(i < ind - 1)
    {
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    if(p->next == NULL)
    {
        p->next = ptr;
        ptr->prev = p;
        return head1;
    }
    p->next->prev = ptr;
    p->next = ptr;
    ptr->prev = p;

    return head1;
}

struct Node *InsertAtLast(struct Node *head1)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head1;
    int ind;

    if(head1 == NULL)
    {
        printf("\nList is Empty.");
        return head1;
    }
    printf("\nEnter data.");
    scanf("%d", (&ptr->data));

    while(p->next != NULL)
    {
        p = p->next;
    }
    ptr->next = NULL;
    ptr->prev = p;
    p->next = ptr;

    return head1;
}

struct Node *DeleteAtFirst(struct Node *head1)
{
    struct Node *q = head1;
    if(head1 == NULL)
    {
        printf("\nList is Empty.");
        return head1;
    }
    head1 = q->next;
    head1->prev = NULL;
    free(q);
    return head1;
}

struct Node *DeleteAtIndex(struct Node *head1)
{
    struct Node *p = head1;
    struct Node *q = NULL;
    int ind, i = 0;

    printf("\nEnter Index at which you want to delete.");
    scanf("%d", &ind);

    if(head1 == NULL)
    {
        printf("\nList is Empty.");
        return head1;
    }
    if(ind == 0)
    {
        head1 = DeleteAtFirst(head1);
        return head1;
    }

    while(i < ind - 1)
    {
        p = p->next;
        i++;
    }
    q = p->next;
    p->next = q->next;
    free(q);

    return head1;
}

struct Node *DeleteAtLast(struct Node *head1)
{
    struct Node *p = head1;
    struct Node *q = head1->next;

    if(head1 == NULL)
    {
        printf("\nList is Empty.");
        return head1;
    }
    while(q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);

    return head1;
}

struct Node* CreateNode(struct Node *head1){
    int n,value;
    struct Node *nxtnode, *temp;

	printf("\nEnter the number of nodes you want: ");
	scanf("%d", &n);

	printf("\nEnter the value for node1: ");
	scanf("%d", &value);
	head1->data = value;
	head1->next = NULL;
    head1->prev = NULL;
	temp = head1;

	for (int i = 1; i < n; i++)
	{
		nxtnode = (struct Node *)malloc(sizeof(struct Node));
		printf("\nEnter the value for node %d: ", i);
		scanf("%d", &(nxtnode->data));
		nxtnode->next = NULL;
		temp->next = nxtnode;
        nxtnode->prev = temp;
		temp = nxtnode;
	}
}

int main()
{
    int n, ch, i;
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    CreateNode(head);
    while (1)
    {
        system("CLS");
        printf("\nEnter your choice.\n");
        printf("\n1.Insert a node at First.");
        printf("\n2.Insert a node at Index.");
        printf("\n3.Insert a node at Last.");
        printf("\n4.Delete a node at First.");
        printf("\n5.Delete a node at Index.");
        printf("\n6.Delete a node at Last.");
        printf("\n7.View Linked List.");
        printf("\n8.Exit.");
        scanf("%d", &ch);
        switch (ch)
        {
            
            case 1:
                    head = InsertAtFirst(head);
                    break;
            case 2:
                    head = InsertAtIndex(head);
                    break;
            case 3:
                    head = InsertAtLast(head);
                    break;
            case 4:
                    head = DeleteAtFirst(head);
                    break;
            case 5:
                    head = DeleteAtIndex(head);
                    printf("Hello");
                    break;
            case 6:
                    head = DeleteAtLast(head);
                    break;
            case 7:
                    Traversal(head);
                    getch();
                    break;
            case 8: exit(0);
        }
    }

    return 0;
}
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Stack
{
    int size;
    int top;
    char *arr;
};

int isEmpty(struct Stack *s)
{
    if (s->top == -1)
        return 1;
    return 0;
}

struct Stack *push(struct Stack *s, char data)
{
    s->arr[++s->top] = data;
    return s;
}

struct Stack *pop(struct Stack *s){
    s->top--;
    return s;
}

int check(char A, char B)
{
    if (A == '(' && B == ')')
        return 1;
    else if (A == '[' && B == ']')
        return 1;
    else if (A == '{' && B == '}')
        return 1;
    return 0;
}

int parenthesis(struct Stack *sp, char exp[])
{
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
            sp = push(sp, exp[i]);
        else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}')
        {
            if (isEmpty(sp))
                return 0;
            if(check(sp->arr[sp->top], exp[i]))
                sp = pop(sp);
            else
                return 0;
        }
    }
    if (isEmpty(sp))
    {
        return 1;
    }
    return 0;
}

void main()
{
    char exp[400];
    system("cls");

    struct Stack *sp = (struct Stack *)malloc(sizeof(struct Stack));
    sp->size = 400;
    sp->top = -1;
    sp->arr = (char *)malloc(sizeof(char) * sp->size);

    printf("\nEnter any Expression to check parenthesis balanced or unbalanced.");
    scanf("%s", exp);
    if (parenthesis(sp, exp))
    {
        printf("\nParenthesis balanced.");
    }
    else
    {
        printf("\nParenthesis not balanced.");
    }
    return;
}
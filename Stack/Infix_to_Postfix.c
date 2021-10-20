#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Stack
{
    int top;
    int size;
    char *arr;
};

int isEmpty(struct Stack *sp)
{
    if (sp->top == -1)
        return 1;
    return 0;
}

struct Stack *push(struct Stack *sp, char data)
{
    sp->arr[++sp->top] = data;
    return sp;
}

char pop(struct Stack *sp)
{
    return sp->arr[sp->top--];
}

int priority(char ch){
    if(ch == '+' || ch == '-')
        return 2;
    else if(ch == '*' || ch == '/')
        return 3;
    return 0;
}

char *infixtopostfix(struct Stack *sp, char exp[])
{
    char *topost = (char *)malloc(sizeof(char) * 200);
    int k = 0, i = 0;
    while(exp[i] != '\0'){
        if(exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/'){
            if(priority(exp[i]) > priority(sp->arr[sp->top]))
                sp = push(sp, exp[i++]);
            else
                topost[k++] = pop(sp);
        }
        else
            topost[k++] = exp[i++];
    }
    while(!isEmpty(sp)){
        topost[k++] = pop(sp);
    }
    topost[k] = '\0';
    return topost;
}

void main()
{
    struct Stack *sp = (struct Stack *)malloc(sizeof(struct Stack));
    sp->top = -1;
    sp->size = 200;
    sp->arr = (char *)malloc(sizeof(char) * sp->size);
    char exp[200];
    system("CLS");
    printf("\nEnter the infix expression.");
    scanf("%s", exp);
    printf("Infix to Postfix : %s", infixtopostfix(sp, exp));
    return;
}
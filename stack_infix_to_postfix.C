#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct stack
{
    int size;
    int top;
    char *arr;
};
int isfull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        printf("stack overflow!\n");
    }
    else
    {
        return 0;
    }
}
int isempty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        printf("stack underflow!\n");
        return -1;
    }
    else
    {
        return 0;
    }
}
int push(struct stack *ptr, int data)
{
    if (isfull(ptr))
    {
        printf("Stack overflow! push operation cannot be performed\n");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = data;
    }
}
int pop(struct stack *ptr)
{
    if (isempty(ptr))
    {
        printf("Stack underflow!");
    }
    else
    {
        int val = ptr->arr[ptr->top];
        ptr->top--;
    }
}
int stacktop(struct stack *ptr)
{
    printf("the top element of the stack is %d", ptr->arr[ptr->top]);
}
int isoperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int precedence(char ch)
{
    if (ch == '*' || ch == '/')
    {
        return 3;
    }
    else if (ch == '+' || ch == '-')
    {
        return 2;
    }
    else
    {
        return 0;
    }
}
char *infixtopostfix(char *infix)
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack)); // initialising the stack
    sp->top = -1;
    sp->size = 100;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    char *pos = (char *)malloc((strlen(infix) + 1) * sizeof(char));
    int i = 0, j = 0;
    while (infix[i] != '\0')
    {
        if (!isoperator(infix[i]))
        {
            pos[j] = infix[i];
            
            i++;
            j++;
        }
        else
        {
            if (precedence(infix[i]) > precedence(stacktop(sp)))
            {
                push(sp, infix[i]);
                i++;
            }
            else
            {
                pos[j] = pop(sp);
                j++;
            }
        }
    }
    while (!isempty(sp))
    {
        pos[j] = pop(sp);
        j++;
    }
    pos[j] = '\0';
    return pos;
}
int main()
{
    char *exp = (char *)"a-b*d+c";
    printf("The postfix expression is %s", infixtopostfix(exp));
    return 0;
}
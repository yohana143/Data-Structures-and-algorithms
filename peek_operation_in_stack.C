#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int *arr;
    int top;
    int size;
};
int display(struct stack *ptr)
{
    printf("The elements of the stack are %d: ", ptr->arr);
}
int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void push(struct stack *ptr, int data)
{
    if (isFull(ptr))
    {
        printf("Stack overflow ! You cannot insert %d into the stack\n");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = data;
    }
}
void pop(struct stack *ptr)
{   
    if(isEmpty(ptr))
{
        printf("stack underflow !");
}
else{
        int val = ptr->arr[ptr->top];
        ptr->top--;
}
}
int peek(struct stack *s,int i)
{
    int arrindex=s->top-i+1;
    if(arrindex < 0)
    {
        printf("Invalid position\n");
    }
    else{
        return s->arr[arrindex];
    }
}
int main()
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 20; // or s->size=20;
    s->top = -1;  // or s->top=-1;
    s->arr = (int *)malloc(s->size * sizeof(int));
    printf("The stack is created\n");
    printf("%d\n", isFull(s));
    printf("%d\n", isEmpty(s));
    push(s, 30);
    push(s, 36);
    push(s, 35);
    push(s, 31);
    push(s, 39);
    printf("%d\n", isFull(s));
    printf("%d\n", isEmpty(s));
    pop(s);
    printf("%d\n", isFull(s));
    printf("%d\n", isEmpty(s));
    for (int j=0 ; j<= s->top+1 ;j++)
    {
        printf("The value at position %d is %d \n:",j,peek(s,j));
    }
    //display(s);
}
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct stack
{
    int size;
    int top;
    char *arr;
};
int isempty(struct stack *ptr)
{
    if(ptr->top==-1)
    {
        printf("Stack is completely empty\n");
    }
    else{
        printf("Stack is not empty\n");
    }
}
int isfull(struct stack *ptr)
{
    if(ptr->top==ptr->size-1)
    {
        printf("stack overflow !!!!!!!!\n");
    }
    else{
        printf("The stack still has some space !!!!\n");
    }
}
void push(struct stack *ptr,int data)
{
    if(isfull(ptr))
    {
        printf("stack overflow!!!!");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top]=data;
    }
}
void pop(struct stack *ptr)
{
    char val;
    if(isempty(ptr))
    {
        printf("stack underflow!!!!");
    }
    else
    {
        val=ptr->arr[ptr->top];
        ptr->top--;
    }
    printf("The popped element from the stack is %d ",val);
}
int paranthesismatch(char * exp)
{
    struct stack *s;
    s->size=100;
    s->top = -1;
    s->arr=(char *)malloc(s->size*sizeof(char));
    for (int i=0 ; exp[i]!='\0' ; i++)
    {
        if(exp[i]=='(')
        {
            push(s,'(');
        }
        else if (exp[i]==')')
        {
            if(isempty(s))
            {
                return 0;
            }
            pop(s);
        }
        
    }
    if(isempty(s))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    char * exp="8*(9+2)";
    if(paranthesismatch(exp))
    {
        printf("The paranthesis is balanced\n");
    }
    else
    {
        printf("The parathesis is balanced\n");
    }
   // push(s,10);
   // push(s,20);
   // push(s,30);
//
   // pop(s);
   return 0;

}
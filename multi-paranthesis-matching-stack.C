#include<stdio.h>
#include<stdlib.h>
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
        printf("stack underflow!\n");
    }
    else
    {
        return 0;
    }
}
int isfull(struct stack *ptr)
{
    if(ptr->top == ptr->size-1)
    {
        printf("stack overflow!\n");
    }
    else
    {
        return 0;
    }
}
int push(struct stack *ptr,int data)
{
    if(isfull(ptr))
    {
        printf("The stcak is full,so push operation cannot be done!\n");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top]=data;
    }
}
int pop(struct stack *ptr)
{
    if(isempty(ptr))
    {
        printf("The stack is empty,so the pop operation cannot be done!");
    }
    else
    {
        int val=ptr->arr[ptr->top];
        ptr->top--;
        printf("The poped element from the stack is %d\n",val);
    }
}
int match(char a,char b)
{
    if(a=='(' && b==')')
    {
        return 1;
    }
    if(a=='{' && b=='}')
    {
        return 1;
    }
    if(a=='[' && b==']')
    {
        return 1;
    }
    return 0;
}
int multiparanthesismatch(char *exp)
{
    struct stack *s=(struct stack *)malloc(sizeof(struct stack));
    s->size=100;
    s->top=-1;
    s->arr=(char *)malloc(s->size*sizeof(char));
    char popped_char;
    for (int i=0; exp[i]='\0';i++)
    {
        if(exp[i]=='(' || exp[i]=='[' || exp[i]=='{')
        {
            push(s,exp[i]);
        }
        else if(exp[i]==')' || exp[i]==']' || exp[i]=='}')
        {
            if(isempty(s))
            {
            return 0;
            }
            popped_char=pop(s);
        if(!match(popped_char,exp[i]));
        {
            return 0;
        }
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
    char *exp;
    exp=(char*)"((8)(*--$$9))";
    if(multiparanthesismatch(exp))
    {
        printf("The expression is balanced\n");
    }
    else
    {
        printf("The expression is not balanced\n");
    }
    
   /* push(s,100);
    push(s,200);
    push(s,300);
    pop(s);
    isempty(s);
    isfull(s); */
    return 0;

}
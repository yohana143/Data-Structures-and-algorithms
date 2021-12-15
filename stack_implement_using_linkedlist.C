#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
void display(struct Node *ptr)
{
    while(ptr!=NULL)
    {
    printf("%d \n",ptr->data);
    ptr=ptr->next;
    }

}
int isEmpty(struct Node *top)
{
    if(top==NULL)
    {
        printf("stack is Empty\n");
    }
    else
    {
        printf("Stack is not empty\n");
    }
}
int isFull(struct Node *top)
{
    struct Node *p=(struct Node *)malloc(sizeof(struct Node));//if linked list is full, it will not accept my newly created node p
    if(p==NULL)
    {
        printf("The stack if Full\n");
    }
    else{
        printf("The stack has space, you can push the elements\n");
    }
}
struct Node* push(struct Node *top, int data)
{
    if(isFull(top)){
        printf("Stack overflow\n");
    }
    else{
        struct Node *n=(struct Node *)malloc(sizeof(struct Node));
        n->data=data;
        n->next=top;
        top=n;
        return top;
    }

}
int pop(struct Node **top)
{
    if(isEmpty(*top))
    {
        printf("The stack is empty,you cannot pop the elements\n");
    }
    else{
        struct Node *n=*top;
        *top=(*top)->next;
        int x=n->data;
        free(n);
        return x;
    }
}
int peek(struct Node *top,int pos)
{
    struct Node *ptr=top;
    for(int i=0;(i<pos-1 && ptr!=NULL);i++)
    {
        ptr=ptr->next;
    }
    if(ptr!=NULL)
    {
        return ptr->data;
    }
}
int main()
{   
    struct Node *top=NULL;
    top= push(top,100);
    top= push(top,200);
    top= push(top,300);
    top= push(top,400);

    int element=pop(&top);
    printf("popped element is :%d\n",element);

    display(top);
    printf("The value at position 1 is: %d\n",peek(top,1));//for single element 

    //For multiple elements
    for (int i=1;i<=2;i++)
    {
        printf("The value at position %d is: %d\n",i,peek(top,i));
    }
    isEmpty(top);
    isFull(top);
    display(top);

}
#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
void linkedlisttraversal(struct Node *ptr)
{
    while(ptr!=NULL)
    {
        printf("%d \n",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}
//CASE 1
struct Node * insertatbeginning(struct Node *head,int data)
{
    struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
    ptr->next=head;
    ptr->data=data;
    return ptr;
}
//CASE 2
struct Node * insertinbetween(struct Node * head,int data,int index)
{
    struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
    struct Node *p=head;
    int i=0;
    while(i!=index-1)
    {
        p=p->next;
        i++;
    }
    ptr->data=data;
    ptr->next=p->next;
    p->next=ptr;
}
//CASE 3
struct Node * insertatend(struct Node * head,int data)
{
    struct Node * ptr=(struct Node *)malloc(sizeof(struct Node));
    struct Node *p=head;
     ptr->data=data;
    int i=0;
    while(p->next!=NULL)
    {
        p=p->next;
        i++;
    }
    p->next=ptr;
    ptr->next=NULL;
    return ptr;
}
//CASE 4
struct  Node *insertafternode(struct Node * head,struct Node * prevnode,int data)
{
    struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
    ptr->data=data;
    ptr->next=prevnode->next;
    prevnode->next=ptr;
    return prevnode;
}
int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    //allocation of heap memory 
    head=(struct Node *)malloc(sizeof(struct Node));
    second=(struct Node *)malloc(sizeof(struct Node));
    third=(struct Node *)malloc(sizeof(struct Node));
    fourth=(struct Node *)malloc(sizeof(struct Node));

    head->data=7;
    head->next=second;

    second->data=8;
    second->next=third;

    third->data=6;
    third->next=fourth;

    fourth->data=4;
    fourth->next=NULL;

    linkedlisttraversal(head);
    insertatbeginning(head,12);  //case 1
    linkedlisttraversal(head);
    insertinbetween(head,100,2); //CASE 2
    linkedlisttraversal(head);
    insertatend(head,200);       //CASE 3
    linkedlisttraversal(head); 
    insertafternode(head,second,300);  //CASE 4
    linkedlisttraversal(head);
}
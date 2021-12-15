#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
void linkedlisttraversal(struct Node * ptr)
{
    while(ptr!=NULL)
    {
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}
//CASE 1
struct Node * deleteatfirst(struct Node *head)
{
    struct Node *ptr=head;
    head=head->next;
    free(ptr);
    return head;
}
struct Node * deleteatindex(struct Node * head,int index)
{
    struct Node *p=head;
    struct Node *q=head->next;
    for(int i=0;i<index-1;i++)
    {
        p=p->next;
        q=q->next;
    }
    p->next=q->next;
    free(q);
    return head;

}
struct Node * deleteatlast(struct Node * head)
{
    struct Node *ptr=head;
    while(ptr!=NULL)
    {
        ptr=ptr->next;
    }
    free(ptr->next);
    ptr->next=NULL;
    return head;
}
int length(struct Node *ptr)
{
    int sum=0;
    //struct Node *ptr=head;
    while(ptr!=NULL)
    {
        ptr=ptr->next;
        sum=sum+1;
    }
   printf("Number of nodes in the linked list are %d:",sum);
   // return sum;
}
int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    struct Node *fifth;

    head=(struct Node *)malloc(sizeof(struct Node));
    second=(struct Node *)malloc(sizeof(struct Node));
    third=(struct Node *)malloc(sizeof(struct Node));
    fourth=(struct Node *)malloc(sizeof(struct Node));
    fifth=(struct Node *)malloc(sizeof(struct Node));

    head->data=10;
    head->next=second;

    second->data=20;
    second->next=third;

    third->data=30;
    third->next=fourth;

    fourth->data=40;
    fourth->next=fifth;

    fifth->data=50;
    fifth->next=NULL;
    linkedlisttraversal(head);
    head=deleteatfirst(head);
    linkedlisttraversal(head);
    head=deleteatindex(head,3);
    linkedlisttraversal(head);
    head=deleteatlast(head);
    linkedlisttraversal(head);
    length(head);
    return 0;
}
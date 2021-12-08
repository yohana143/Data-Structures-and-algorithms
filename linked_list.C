#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};

void traversal(struct Node *ptr)
{
    while(ptr != NULL)
    {
    printf("Element : %d\n",ptr->data);
    ptr=ptr->next;
    }
}
int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;

    //Heap memory allocation
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    //linking 1st and 2nd nodes
    head->data=7;
    head->next=second;

    //linking 2nd and 3rd nodes
    second->data=10;
    second->next=third;

    //terminating the last nodes
    third->data=7;
    third->next=NULL;

    traversal(head);

    return 0;
}
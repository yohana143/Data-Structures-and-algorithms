#include<stdio.h>
#include<stdlib.h>
struct queue{
    int size,f,r;
    int *arr;
};
int isempty(struct queue *q)
    {
        if(q->r==q->f)
        {
            printf("Queue is empty!\n");
        }
        return 0;
    }
int  isfull(struct queue *q)
{
    if(q->r==q->size-1)
    {
        printf("The queue is full!\n");
    }
    return 0;
}
void enqueue(struct queue *q,int val)
{
    if(isfull(q))
    {
       printf("queue full\n");
    }
    else
    {
        q->r++;
        q->arr[q->r]=val;
        printf("%d\n",val);
    }
}
int dequeue(struct queue *q)
{
    int a=-1;
    if(isempty(q))
    {
        printf("the queue is empty");
    }
    else
    {
        q->f++;
        a=q->arr[q->f];
    }
    return a;
}
int main()
{
    struct queue q;
    q.size=30;
    int  n=q.size;
    q.r=q.f=-1;
    q.arr=(int *)malloc(q.size*sizeof(int));
    printf("The elements of the queue are:\n");
    enqueue(&q,10);
    enqueue(&q,20);
    enqueue(&q,30);
    enqueue(&q,40);
    enqueue(&q,50);
    printf("The dequeued elements is %d\n",dequeue(&q));
    printf("The dequeued elements is %d\n",dequeue(&q));
    printf("The dequeued elements is %d\n",dequeue(&q));
    printf("The dequeued elements is %d\n",dequeue(&q));
    printf("The dequeued elements is %d\n",dequeue(&q));
    if(isempty(&q))
    {
        printf("Finally the Queue is empty\n");
    }
    if(isfull(&q))
    {
        printf("Queue is full\n");
    }
    return 0;
}
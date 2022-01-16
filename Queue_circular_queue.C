#include<stdio.h>
#include<stdlib.h>
struct queue {
    int *arr;
    int f,r;
    int size;
};
void enqueue(struct queue *q,int val)
{
    if((q->r+1)%q->size==q->f)
    {
        printf("Queue overflow!\n");
    }
    else
    {
        q->r=((q->r+1)%q->size);
        q->arr[q->r]=val;
    }
}
int dequeue(struct queue *q)
{
    int val=-1;
    if(q->r==q->f)
    {
        printf("Queue is empty!\n");
    }
    else
    {
        q->f++;
        val=q->arr[q->f];
    }
    return val;
}
int main()
{
    struct queue q;
    q.f=q.r=-1;
    q.size=30;
    q.arr=(int *)malloc(q.size*sizeof(int));
    enqueue(&q,23);
    enqueue(&q,52);
    enqueue(&q,1);
    printf("The dequeued element is %d\n",dequeue(&q));
    printf("The dequeued element is %d\n",dequeue(&q));
    printf("The dequeued element is %d\n",dequeue(&q));
}
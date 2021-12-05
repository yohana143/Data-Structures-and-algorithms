#include<stdio.h>
#include<stdlib.h>
void display(int arr[],int n)
{
    for (int i=0;i<=n ;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}
void indexdeletion(int arr[], int size , int index)
{
    int temp;
    for(int i=index ;i<size; i++)
    {
        arr[i]=arr[i+1];
    }
}
int main()
{
    int arr[20]={1,4,8,2,4,7,5,0,4};
    int size=8;
    display(arr,size);
    int index=4;
    indexdeletion(arr, size, index);
    size=size-1;
    display(arr,size);
    return 0;
}
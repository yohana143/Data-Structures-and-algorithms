#include<stdio.h>
#include<stdlib.h>
void display(int arr[],int n)
{
    //traversal code
    for (int i=0;i<=n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}
int  indexinsertion(int arr[], int size ,int element ,int index,int capacity)
{
    //code for insertion
    if(size>=capacity)
    {
        return -1;
    }
    for(int i=size ; i >=index ;i--)
    {
        arr[i+1]=arr[i];
    }
    arr[index]=element;
    return 1;
}
int main()
{
    int arr[20]={12,5,8,3,78};
    int size=4;
    int element=45;
    int index=3;
    display(arr,size);
    indexinsertion(arr, size, element, index, 20);
    size=size+1;
    display(arr,size);
}
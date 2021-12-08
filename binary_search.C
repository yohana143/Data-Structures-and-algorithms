#include<stdio.h>
#include<stdlib.h>
//void display(int arr[],int size)
//{
//    for (int i=0;i<=size;i++)
//    {
//        if(arr[i]==x);
//    }
//    printf("\n");
//}
int binarysearch(int arr[],int x,int low,int high)
{
    int mid=low+(high-low)/2;
    while(low<=high)
    {
    if(arr[mid]==x)
        return mid;
    if(arr[mid]<x)
        low=mid+1;
    else
        high=mid-1;
    }
    return -1;
}
int main()
{
    int arr[30]={3,5,6,7,9,15,23,31,54,60,65,67,70,72,75,77,80,91,94,95,99};
    int size=sizeof(arr)/sizeof(arr[0]);
    int x=7;
   // display(arr,size);
    int index=binarysearch(arr,x,0,size-1);
    if(index== -1)
    {
    printf("Element is not found in the array\n");
    }
    else
    {
    printf("The element %d was found at index %d",x,index);
    }
    return 0;
}
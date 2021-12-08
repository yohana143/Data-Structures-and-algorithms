#include<stdio.h>
#include<stdlib.h>
//void display(int arr[],int size)
//{
//    for (int i=0;i<size;i++)
//    {
//        printf("%d ",arr[i]);
//    }
//    printf("\n");
//}
int linearsearch(int arr[],int size,int x)
{
    for (int i=0;i<size;i++)
    {
        if(arr[i]==x)
        {
            return i;
        }
    }
    
    return -1;
}
int main()
{
    int arr[20]={3,2,7,5,9,4,2,5,8,6};
    int size=sizeof(arr)/sizeof(int);
   // display(arr,size);
    int x=4;
    int index=linearsearch(arr,size,x);
    printf("The element %d was found at index %d\n",x,index);
    return 0;
}
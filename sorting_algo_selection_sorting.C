#include<stdio.h>
void printArray(int A[],int size)
{
    for (int i=0 ; i<=size-1 ; i++)
    {
        printf("%d\n",A[i]);
    }
    printf("\n");
}
void selectionsort(int A[],int size)
{
    for (int i=0 ; i<=size-1 ; i++)
    {
        int indexofmin=i;
        for(int j=i+1 ; j<=size-1 ;j++)
        {
            if(A[j] <= A[indexofmin])
            {
             indexofmin=j;   
            }
        }
        int temp=A[i];
        A[i]=A[indexofmin];
        A[indexofmin]=temp;
    }
}
int  main()
{
    int A[]={23,1,4,5,2,7,5};
    int size=sizeof(A)/sizeof(int);
    printArray(A,size);
    selectionsort(A,size);
    printArray(A,size);
}
#include<stdio.h>
void printArray(int A[],int size)
{
    for (int i=0 ; i<=size-1 ; i++)
    {
        printf("%d\n",A[i]);
    }
    printf("\n");
}
void insertionsort(int A[],int size)
{
    for(int i=1 ; i<=size-1 ; i++)
    {
        int key=A[i];
        int j=i-1;
        while(j>=0 && A[j] > key)
        {
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=key;
    }
}
int main()
{
    int A[]={1,5,65,37,90,21};
    int size=sizeof(A)/sizeof(int);
    printArray(A,size);
    insertionsort(A,size);
    printArray(A,size);
}

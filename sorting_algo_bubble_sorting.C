#include<stdio.h>
void printArray(int A[],int size)
{
    for(int i=0 ; i<=size-1 ; i++)
    {
        printf("%d\n",A[i]);
    }
    printf("\n");
}
void bubble_sort(int A[],int size)
{
    int temp;
    int isSorted=0;
    for(int i=0 ; i<size-1 ;i++)
    {
        printf("This is pass number %d\n",i+1);
        isSorted=1;//for every pass we make isSorted=1
        for(int j=0 ; j<size-1-i ; j++)
        {
            if(A[j]>A[j+1])
            {
                temp= A[j];
                A[j]=A[j+1];
                A[j+1]=temp;
               isSorted=0;
            }
        }
       if(isSorted)//if array is sorted then we return the array
       {
       return;
       }
    }
}
int main()
{
   int A[]={12,54,65,7,23,9};
    //  int A[]={1,2,3,4,5,6}; //requires only 1 pass 
    int size=sizeof(A)/sizeof(int);
    printf("Array Before sorting\n");
    printArray(A,size); 
    bubble_sort(A,size);
    printf("Array after sorting\n");
    printArray(A,size);
}
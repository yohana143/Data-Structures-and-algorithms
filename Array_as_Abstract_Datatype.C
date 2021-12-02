#include<stdio.h>
#include<stdlib.h>
struct myarray
{
 int total_size;
 int used_size;
 int *ptr;   
};
int createarray(struct myarray * a, int tsize,int usize)
{
    //(*a).total_size=tsize;
    //(*a).used_size=usize;
    //(*a).ptr=(int *)malloc(tsize*sizeof(int));
    
    //or

    a->total_size=tsize;
    a->used_size=usize;
    a->ptr=(int *)malloc(tsize*sizeof(int));
}
int show(struct myarray *a)
{
    for(int i=0 ; i< a->used_size ; i++)
    {
        printf("%d\n",(a->ptr)[i]);
    }
}
int setval(struct myarray * a)
{
    int n;
    for (int i=0;i< a->used_size;i++)
    {
        printf("Enter the marks of student %d:",i+1);
        scanf("%d",&n);
        (a->ptr)[i]=n;
    }
}
int main()
{
    struct myarray marks;
    createarray(&marks,10,2);
    setval(&marks);
    show(&marks);
    return 0;
}
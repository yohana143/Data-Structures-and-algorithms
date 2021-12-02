#include<stdio.h>
#include<stdlib.h>
struct website
{
    int no_users;
    int no_logins;
    int *ptr;
};
void arrayforusers(struct website *a, int tusers ,int logusers)
{
    a->no_users=tusers;
    a->no_logins=logusers;
    a->ptr=(int *)malloc(logusers*sizeof(int));
}
void setusers(struct website *a)
{
    int n,i;
    for (int i=0;i<a->no_logins; i++)
    {
        printf("Enter number of user logins in day %d:", i+1);
        scanf("%d",&n);
        (a->ptr)[i]=n;
    }
}
int show(struct website *a)
{
    for (int i=0; i< a->no_logins ;i++)
    {
        printf("Enter number of logins in day %d are:",i+1);
        printf("  %d\n", (a->ptr[i]));
    }
}
int main()
{
    struct website userscount;
    arrayforusers(&userscount ,20 ,3);
    setusers(&userscount);
    show(&userscount);
    return 0;
}

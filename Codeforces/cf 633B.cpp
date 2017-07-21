#include<stdio.h>
#include<math.h>
int main(void)
{
    int m,k,status=0;
    scanf("%d",&m);
    for(k=1;k<=100000;k++)
    {
        if(k+(k/5)==m)
        {
            status=1;
            break;
        }
    }
    if(status==0)
        printf("0");
    else
    {
        printf("5\n");
        for(int i=0;i<5;i++)
            printf("%d ",5*k+i);
    }


    return 0;
}

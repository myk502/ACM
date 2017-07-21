#include<stdio.h>
#include<ctype.h>
#include<string.h>
char a[90];

int main(void)
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%s",a);
        int length;
        length=strlen(a);
        int i,j,status;

        for(i=0;i<length;i++)
        {
            status=1;
            if(length%(i+1)!=0)
                continue;
            for(j=0;j<length;j++)
            {
                if(a[j]!=a[j%(i+1)])
                    status=0;
            }
            if(status==1)
            {
                if(n==0)
                    printf("%d\n",i+1);
                else printf("%d\n\n",i+1);

                break;
            }

        }
    }
    return 0;
}

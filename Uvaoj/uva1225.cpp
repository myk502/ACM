#include<stdio.h>
#include<ctype.h>
#include<string.h>

char a[40000];
char temp[10];

int main(void)
{
    int t,i,n;
    int num[10];
    scanf("%d",&t);
    while(t--)
    {
        a[0]='\0';
        scanf("%d",&n);
        for( i=1;i<=n;i++)
        {
            sprintf(temp,"%d",i);
            strcat(a,temp);
        }

        int length;
        length=strlen(a);
        for(i=0;i<10;i++)
            num[i]=0;
        for(i=0;i<length;i++)
            num[(a[i]-'0')]++;
        for(i=0;i<9;i++)
            printf("%d ",num[i]);
        printf("%d",num[9]);
        printf("\n");

    }
    return 0;
}

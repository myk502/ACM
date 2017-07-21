#include<stdio.h>
#include<ctype.h>
#include<string.h>
char s[90];
int main(void)
{
    int length,n,sum,num;
    scanf("%d",&n);
    while(n--)
    {
        sum=num=0;
        scanf("%s",s);
        length=strlen(s);
        for(int i=0;i<length;i++)
        {
            if(s[i]=='X')
            {
                num=0;
                continue;
            }
            num++;
            sum+=num;
        }
        printf("%d\n",sum);


    }
    return 0;
}

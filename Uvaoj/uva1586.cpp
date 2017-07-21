#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define tan 12.01
#define qing 1.008
#define yang 16.00
#define dan 14.01
char s[90];
int main(void)
{
    int i,length,n,temp;
    double sum;
    scanf("%d",&n);
    while(n--)
    {
        sum=0;

        scanf("%s",s);
        length=strlen(s);
        if(isupper(s[length-1]))
        {
            s[length]='1';
            s[length+1]='\0';
        }
        length=strlen(s);
        for(i=0;i<length-1;i++)
        {
            if(isupper(s[i]) &&isupper(s[i+1]))
            {
                switch(s[i])
                {
                    case 'C':sum+=tan;
                             break;
                    case 'H':sum+=qing;
                             break;
                    case 'O':sum+=yang;
                             break;
                    case 'N':sum+=dan;
                             break;

                }
            }
            if(isupper(s[i]) &&!(isupper(s[i+1])))
            {
                int j=i+1;
                while(!(isupper(s[j]))&&(j<length))
                    j++;
                int myk,weishu=1;
                temp=0;
                for(myk=j-1;myk>=i+1;myk--)
                {
                    temp+=weishu*(s[myk]-'0');
                    weishu*=10;
                }
                switch(s[i])
                {
                    case 'C':sum+=tan*temp;
                             break;
                    case 'H':sum+=qing*temp;
                             break;
                    case 'O':sum+=yang*temp;
                             break;
                    case 'N':sum+=dan*temp;
                             break;

                }
            }


        }
        printf("%.3lf\n",sum);
    }
    return 0;
}

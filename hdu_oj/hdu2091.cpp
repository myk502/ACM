#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;

int main(void)
{

    char x;
    int n,countt=0;
    while(scanf("%c",&x))
    {
        if(x=='\n')
            continue;
        if(x=='@')
            break;
        scanf("%d",&n);
        if(countt!=0)
            printf("\n");
        countt++;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=2*n-1;j++)
            {
                if(i==1)
                {
                    if(j==n)
                    {
                        printf("%c\n",x);
                        break;
                    }
                    else
                        printf(" ");

                }
                if(i==n)
                {
                    printf("%c",x);
                    if(j==2*n-1)
                    {
                        printf("\n");
                        break;
                    }
                }
                if((i>1)&&(i<n))
                {
                    if(j==n+1-i)
                        putchar(x);
                    else
                    {
                        if(j==i+n-1)
                        {
                            printf("%c\n",x);
                            break;
                        }
                        else
                            printf(" ");
                    }
                }
            }
            //printf("\n");
        }

    }
    return 0;
}

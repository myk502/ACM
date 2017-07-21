#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<limits.h>
#include<ctype.h>
using namespace std;
#define zuida 1000000000
int a[1010],n,b[2020],index;//b是结果数组
int gcd(int a,int b)
{
    if(a<b)
        return(gcd(b,a));
    if(b==0)
        return a;
    else
        return(gcd(b,a%b));
}

int main(void)
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    memset(b,-1,sizeof(b));
    index=-1;//index是b的索引
    //printf("gcd(2,7)=%d\n",gcd(2,7));
    for(int i=0;i<n-1;i++)
    {
        if(gcd(a[i],a[i+1])==1)//互素
        {
            //printf("%d and %d huzhi\n",a[i],a[i+1]);
            b[++index]=a[i];
            //b[++index]=a[i+1];
        }
        else
        {
            for(int j=2;j<zuida;j++)
            {
                if((gcd(a[i],j)==1)&&(gcd(a[i+1],j)==1))
                {
                    b[++index]=a[i];
                    b[++index]=j;
                    //b[++index]=a[i+1];
                    break;
                }
            }
        }
    }
    b[++index]=a[n-1];
    printf("%d\n",index+1-n);
    for(int i=0;i<=index;i++)
        printf("%d ",b[i]);

    return 0;
}

#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<limits.h>
#define zuida 100000
int s[zuida+10],n,k,maxn,minn;
using namespace std;
int ceshi(int input)
{
    int i,j,temp;
    if(k>=n)
        maxn=minn;
    else
    {
        maxn=minn;
        i=0;
        j=2*n-2*k-1;
        while(i<=j)
        {
            temp=s[i++]+s[j--];
            maxn=(maxn>temp)?maxn:temp;
        }
    }
    printf("%d",maxn);
    return 0;
}

int main(void)
{
    int i,temp;
    scanf("%d%d",&n,&k);
    for(i=0;i<n;i++)
        scanf("%d",&s[i]);

    minn=0;


    for(i=0;i<n;i++)
        minn=(s[i]>minn?s[i]:minn);

    ceshi(1);
    return 0;
}

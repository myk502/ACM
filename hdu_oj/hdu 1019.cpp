#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int gcd(int x,int y)
{
    if(y==0)
        return x;
    else
        return(gcd(y,x%y));
}
int lcm(int x,int y)
{
    long long chengji;
    chengji=(long long)x*(long long)y;
    return(int)(chengji/gcd(x,y));
}
int main(void)
{
    int m,n,x,ans=1;
    scanf("%d",&m);
    for(int i=0;i<m;i++)
    {
        ans=1;
        scanf("%d",&n);
        if(n==0)
            continue;
        while(n--)
        {
            scanf("%d",&x);
            ans=lcm(ans,x);
        }
        if(i!=0)
            printf("%d\n",ans);
        else
            printf("%d\n",ans);
    }
    return 0;
}

#include<cstdio>
#include<climits>
#include<cstring>
#include<iostream>
#include<cmath>
#include<string>
#include<sstream>
#include<set>
#include<algorithm>
using namespace std;
int m,n,c[10],v[10],dp[120000],a[10];
void ZeroOnePack(int value,int cost)
{
    for(int j=m;j>=cost;j--)
        dp[j]=max(dp[j],dp[j-cost]+value);
}
void CompletePack(int value,int cost)
{
    for(int j=cost;j<=m;j++)
        dp[j]=max(dp[j],dp[j-cost]+value);
}
void MutiplePack(int value,int cost,int amount)
{
    if(amount*cost>=m)
    {
        CompletePack(value,cost);
        return ;
    }
    int k=1;
    while(k<amount)
    {
        ZeroOnePack(k*value,k*cost);
        amount-=k;
        k*=2;
    }
    ZeroOnePack(amount*value,amount*cost);
    return ;
}
int main(void)
{
    int ans,sum,tt=0;
    while(scanf("%d%d%d%d%d%d",&a[1],&a[2],&a[3],&a[4],&a[5],&a[6]))
    {
        //ans=0;
        tt++;
        if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]==0)
            break;
        dp[0]=0;

        for(int i=1;i<120000;i++)
            dp[i]=INT_MIN;
        sum=0;
        for(int i=1;i<=6;i++)
        {
            sum+=a[i]*i;
        }
        if(sum%2==1)
            ans=0;
        else
        {
            m=sum/2;
            for(int i=1;i<=6;i++)
            {
                MutiplePack(i,i,a[i]);
            }
            if(dp[m]>0)
                ans=1;
            else
                ans=0;
        }
        printf("Collection #%d:\n",tt);
        if(ans==0)
            printf("Can't be divided.\n\n");
        else
            printf("Can be divided.\n\n");

    }
    return 0;
}

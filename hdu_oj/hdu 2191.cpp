#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<string>
#include<sstream>
#include<set>
#include<algorithm>
using namespace std;

int m,n,t,v[2010],c[2010],dp[2010],a[2010];
void OneZeroPack(int cost,int value)
{
    for(int j=m;j>=cost;j--)
        dp[j]=max(dp[j],dp[j-cost]+value);
}
void CompletePack(int cost,int value)
{
    for(int j=cost;j<=m;j++)
        dp[j]=max(dp[j],dp[j-cost]+value);
}
void MutiplePack(int cost,int value,int amount)
{
    //int num=amount;
    if(amount*cost>=m)
    {
        CompletePack(cost,value);
        return ;
    }
    int k=1;
    while(k<amount)
    {
        OneZeroPack(cost*k,value*k);
        amount-=k;
        k*=2;
    }
    OneZeroPack(cost*amount,value*amount);
    return ;
}
int main(void)
{
    int ans=-1;
    cin>>t;
    while(t--)
    {
        cin>>m>>n;
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++)
        {
            cin>>c[i]>>v[i]>>a[i];
        }
        for(int i=1;i<=n;i++)
        {
            MutiplePack(c[i],v[i],a[i]);
        }
        printf("%d\n",dp[m]);
    }
    return 0;
}

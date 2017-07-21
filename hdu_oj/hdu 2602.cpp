#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<string>
#include<sstream>
#include<set>
#include<algorithm>
using namespace std;
int t,n,v[1010],w[1010],weight;
int dp[1010];
int ZeroOnePack(int value,int cost)
{
    for(int j=weight;j>=cost;j--)
        dp[j]=max(dp[j],dp[j-cost]+value);
}
int main(void)
{
    cin>>t;
    int ans;
    while(t--)
    {
        cin>>n>>weight;
        for(int i=1;i<=n;i++)
            cin>>v[i];
        for(int i=1;i<=n;i++)
            cin>>w[i];
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++)
        ZeroOnePack(v[i],w[i]);
        cout<<dp[weight]<<endl;
    }
    return 0;
}

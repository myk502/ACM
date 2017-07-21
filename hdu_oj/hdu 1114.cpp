#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<string>
#include<sstream>
#include<set>
#include<algorithm>
using namespace std;
int t,c[510],v[510],dp[20000],e,f,m,n;

int main(void)
{
    cin>>t;
    while(t--)
    {
        cin>>e>>f;
        m=f-e;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>v[i]>>c[i];
        }
        for(int i=1;i<20000;i++)
            dp[i]=1000000;
        dp[0]=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=c[i];j<=m;j++)
            {
                dp[j]=min(dp[j],dp[j-c[i]]+v[i]);
            }
        }
        if(dp[m]==1000000)
        {
            cout<<"This is impossible."<<endl;
        }
        else
        {
            printf("The minimum amount of money in the piggy-bank is %d.\n",dp[m]);
        }
    }
    return 0;
}

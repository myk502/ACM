#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<climits>
#include<iostream>
#include<queue>
#include<set>
#include<map>
using namespace std;
int dp[1010][3][35],n,w;
int a[1010];
int main(void)
{
    cin>>n>>w;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    memset(dp,0,sizeof(dp));
    dp[0][1][w]=0;
    for(int i=1;i<=n;i++)
    {
        for(int x=1;x<=2;x++)
        {
            for(int k=0;k<=w;k++)
            {
                if(k+1<=w)
                {
                    dp[i][x][k]=max(dp[i-1][x][k],dp[i-1][3-x][k+1])+(x==a[i]);
                }
                else
                {
                    dp[i][x][k]=dp[i-1][x][k]+(x==a[i]);
                }
                //printf("dp[%d][%d][%d]=%d\n",i,x,k,dp[i][x][k]);


            }
        }

    }
    int ans=-1;
    for(int x=1;x<=2;x++)
        for(int k=0;k<=w;k++)
            ans=max(ans,dp[n][x][k]);
    cout<<ans;
    return 0;
}

#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<string>
#include<sstream>
#include<set>
#include<algorithm>
using namespace std;
int a[110][110],dp[110][110],n;

int main(void)
{
    int t,ans;
    cin>>t;
    while(t--)
    {
        ans=-1;
        cin>>n;
        memset(a,0,sizeof(a));
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=i;j++)
            {
                scanf("%d",&a[i][j]);
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=i;j++)
            {
                dp[i][j]=max(dp[i-1][j-1],dp[i-1][j])+a[i][j];
            }
        }
        for(int j=1;j<=n;j++)
            ans=max(ans,dp[n][j]);
        cout<<ans<<endl;
    }
    return 0;
}

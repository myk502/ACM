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
const int MOD=1000000007;
int dp[1010][1010],sum[1010][1010],n,m,a[1010],b[1010],sum_temp;
int main(void)
{
    int total;
    while(cin>>n>>m)
    {
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for(int i=1;i<=m;i++)
            scanf("%d",&b[i]);
        memset(dp,0,sizeof(dp));
        memset(sum,0,sizeof(sum));
        for(int i=1;i<=n;i++)
        {
            sum[i][0]=0;
            for(int j=1;j<=m;j++)
            {
                sum[i][j]=sum[i][j-1];
                if(a[i]==b[j])
                {
                    dp[i][j]=(sum[i][j]+1)%MOD;
                }
                else
                    dp[i][j]=0;
                sum[i][j]=(dp[i][j]+sum[i][j])%MOD;
            }
        }
        total=0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
            total=(dp[i][j]+total)%MOD;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
            printf("dp[%d][%d]=%d\n",i,j,dp[i][j]);
        cout<<total<<endl;
    }
    return 0;
}

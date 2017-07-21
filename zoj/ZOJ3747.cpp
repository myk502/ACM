#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define zuida 1000000
int n,m,k;
long long a[zuida+10][3],dp[zuida+10][3];
void chushihua(void)
{
    a[1][0]=a[1][1]=a[1][2]=dp[1][1]=dp[1][2]=1;
    if(m>=2)
        a[1][0]=1;
    else
        a[1][0]=0;
}
int main(void)
{
    long long ans;
    while((scanf("%d%d%d",&n,&m,&k)!=EOF))
    {
        chushihua();
        for(int i=2;i<=n;i++)
        {
            if(i<=m-1)
                a[i][0]=a[i-1][0]+a[i-1][1]+a[i-1][2];
            if(i==m)
                a[i][0]=a[i-1][0]+a[i-1][1]+a[i-1][2]-1;
            if(i>m)
                a[i][0]=a[i-1][0]+a[i-1][1]+a[i-1][2]-a[i-m][1]-a[i-m][2];
            if(i<=k)
                a[i][1]=a[i-1][0]+a[i-1][1]+a[i-1][2];
            if(i==k+1)
                a[i][1]=a[i-1][0]+a[i-1][1]+a[i-1][2]-1;
            if(i>k+1)
                a[i][1]=a[i-1][0]+a[i-1][1]+a[i-1][2]-a[i-k-1][0]-a[i-k-1][2];
            a[i][2]=a[i-1][0]+a[i-1][1]+a[i-1][2];

        }
        for(int i=2;i<=n;i++)
        {
            dp[i][0]=dp[i-1][0]+dp[i-1][1]+dp[i-1][2];
            if(i<=k)
                dp[i][1]=dp[i-1][0]+dp[i-1][1]+dp[i-1][2];
            if(i==k+1)
                dp[i][1]=dp[i-1][0]+dp[i-1][1]+dp[i-1][2]-1;
            if(i>k+1)
                dp[i][1]=dp[i-1][0]+dp[i-1][1]+dp[i-1][2]-dp[i-k-1][0]-dp[i-k-1][2];
            dp[i][2]=dp[i-1][0]+dp[i-1][1]+dp[i-1][2];
        }
        ans=dp[n][0]+dp[n][1]+dp[n][2]-a[n][0]-a[n][1]-a[n][2];
        printf("%lld\n",ans);

    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
char a[maxn];
int n;
int dp[maxn][6];//dp[i][j] means the ans for an substring ended with a[i] and mod 6 equals to j
int b[maxn][6];//b[i][j] means the max value for all dp[k][j] having k<i
int main(void)
{

    int x,k,ans=0,cnt=0;
    scanf("%s",a);
    n=strlen(a);
    memset(dp,0,sizeof(dp));
    memset(b,0,sizeof(b));
    for(int i=0;i<n;i++)
    {
        x=a[i]-'0';
        for(int j=0;j<3;j++)
        {
            if(x%3==j)
                dp[i][j]=1;//if x itself mod 6 equals to j,then itself could possibly be ans
            if(x==0)//single 0 should not be resolved as ans(to avoid leading 0)
            {
                dp[i][j]=0;
                cnt++;
            }
            k=((j-x)%3+3)%3;
            if(b[i][k]!=0)
                dp[i][j]=max(dp[i][j],b[i][k]+1);
            b[i+1][j]=max(b[i][j],dp[i][j]);
            //printf("dp[%d][%d]=%d\n",i,j,dp[i][j]);
        }
    }
    for(int i=0;i<n;i++)
    {
        x=a[i]-'0';
        if(x%2==0)
            ans=max(ans,dp[i][0]);
    }
    if((ans==0)&&(cnt!=0))
        ans=1;
    if(ans!=0)
        cout<<ans;
    else
        cout<<"-1s";
    return 0;
}

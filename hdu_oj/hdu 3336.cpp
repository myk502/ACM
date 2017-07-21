#include<bits/stdc++.h>
using namespace std;
const int maxn=200000+10;
int t;
char b[maxn];
int n,N[maxn],dp[maxn];
void build_next(void)
{
    int j=0;
    int t=N[0]=-1;
    while(j<=n-1)
        if(0>t||b[j]==b[t])
        {
            j++;
            t++;
            N[j]=t;
        }
        else
            t=N[t];
}
int main(void)
{
    int sum;
    cin>>t;
    while(t--)
    {
        scanf("%d",&n);
        scanf("%s",b);
        sum=0;
        build_next();
        dp[0]=0;
        for(int i=1;i<=n;i++)
        {
            dp[i]=(dp[N[i]]+1)%10007;
            sum=(sum+dp[i])%10007;
        }
        printf("%d\n",sum);
    }
    return 0;
}

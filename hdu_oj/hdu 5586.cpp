#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
long long a[maxn],b[maxn],c[maxn],n;//c[i]=b[i]-a[i]
long long dp[maxn];
int main(void)
{
    long long sum,ans;
    while(cin>>n)
    {
        sum=0;
        for(int i=0;i<n;i++)
        {
            scanf("%I64d",&a[i]);
            sum+=a[i];
            b[i]=(1890*a[i]+143)%10007;
            c[i]=b[i]-a[i];
        }
        dp[0]=c[0];
        for(int i=1;i<n;i++)
            dp[i]=max(c[i],dp[i-1]+c[i]);
        ans=dp[0];
        for(int i=0;i<n;i++)
        {
            ans=max(ans,dp[i]);
        }
        if(ans>0LL)
            cout<<ans+sum<<endl;
        else
            cout<<sum<<endl;
    }
    return 0;
}

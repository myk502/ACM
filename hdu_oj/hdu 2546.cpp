#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<string>
#include<sstream>
#include<set>
#include<algorithm>
using namespace std;
int n,v,dp[1010],a[1010],m,ans;
bool cmp(int x,int y)
{
    return (x>y);
}
int main(void)
{
    while(cin>>n)
    {
        if(n==0)
            break;

        for(int i=1;i<=n;i++)
            cin>>a[i];
        cin>>m;
        sort(a+1,a+n+1,cmp);
        if(m<5)
        {
            cout<<m<<endl;
            continue;
        }
        if(n==1)
        {
            cout<<m-a[1]<<endl;
            continue;
        }
        memset(dp,0,sizeof(dp));
        for(int i=2;i<=n;i++)
        {
            for(int j=m-5;j>=a[i];j--)
            {
                dp[j]=max(dp[j],dp[j-a[i]]+a[i]);
            }
        }

        ans=m-dp[m-5]-a[1];
        cout<<ans<<endl;
    }
    return 0;
}

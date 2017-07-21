#include<bits/stdc++.h>
using namespace std;
const long long Mod=100000007;
const long long maxn=10000+10;
long long ans,num[maxn],dp[maxn];//第i列的数字，第i列的总数
char temp[maxn];
int n,t;
bool check(void)
{
    if(n==1)
    {
        return(dp[1]==num[1]);
    }
    else
    {
        return(num[n]==dp[n]+dp[n-1]);
    }
}
int main(void)
{
    long long ans_temp;
    cin>>t;
    while(t--)
    {
        ans=0;//初始化为0
        scanf("%s",temp);
        n=strlen(temp);
        memset(num,0,sizeof(num));
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++)
            num[i+1]=temp[i]-'0';
        for(int ii=0;ii<=2;ii++)//枚举第一列的总数
        {
            if(ii>num[1])
                break;
            dp[1]=ii;
            dp[0]=0;//哨兵
            int i;
            for(i=2;i<=n;i++)
            {
                dp[i]=num[i-1]-dp[i-2]-dp[i-1];
                if((dp[i]<0)||(dp[i]>2))
                    break;
            }
            if(i<=n)
                continue;
            if(check())//说明这种枚举（第一列的总数）是一个可行的方案
            {
                ans_temp=1;//一开始就有一种方案
                for(int i=1;i<=n;i++)
                {
                    if(dp[i]==1)
                    {
                        ans_temp*=2;
                        ans_temp%=Mod;
                    }
                }
                ans+=ans_temp;
                ans%=Mod;
            }

        }
        cout<<ans<<endl;
    }
    return 0;
}

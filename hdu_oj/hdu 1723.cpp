#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<string>
#include<sstream>
#include<set>
#include<queue>
#include<algorithm>
using namespace std;
int n,m,dp[50];
int main(void)
{
    while(cin>>n>>m)
    {
        if((n==0)&&(m==0))
            break;
        memset(dp,0,sizeof(dp));
        dp[1]=1;
        for(int i=2;i<=n;i++)
        {

            for(int j=i-m;j<i;j++)
            {
                if(j<1)
                    continue;
                dp[i]+=dp[j];
            }
        }
        cout<<dp[n]<<endl;
    }
    return 0;
}

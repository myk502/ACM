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
long long dp[60];
int main(void)
{
    int x;
    memset(dp,0,sizeof(dp));
    dp[1]=3;
    dp[2]=6;
    dp[3]=6;
    for(int i=4;i<=50;i++)
        dp[i]=dp[i-1]+dp[i-2]*2;
    while(cin>>x)
    {
        cout<<dp[x]<<endl;
    }
    return 0;
}

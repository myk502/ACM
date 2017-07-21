#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<string>
#include<sstream>
#include<set>
#include<algorithm>
using namespace std;
char a[1000],b[1000];
int dp[1000][1000];
int main(void)
{
    int length_a,length_b,ans;
    while(scanf("%s%s",a,b)!=EOF)
    {
        length_a=strlen(a);
        length_b=strlen(b);
        //printf("Test1\n");
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=length_a;i++)
        {
            for(int j=1;j<=length_b;j++)
            {
                if(a[i-1]==b[j-1])
                {
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else
                {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        ans=-1;
        for(int i=1;i<=length_a;i++)
            for(int j=1;j<=length_b;j++)
        {
            if(ans<dp[i][j])
                ans=dp[i][j];
        }
        cout<<ans<<endl;
    }
    return 0;
}

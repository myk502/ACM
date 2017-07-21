#include<cstring>
#include<iostream>
#include<vector>
#include<cstdio>
#include<string>
#include<cmath>
using namespace std;
int dp[1010][1010];
int n;
char str[1010];

void init(void)
{
    for(int i=0;i<1010;i++)
        for(int j=0;j<1010;j++)
            dp[i][j]=100000;
    for(int i=0;i<1010;i++)
        dp[i][i]=0;
}

int solve(int x,int y)
{
    if(dp[x][y]!=100000)
        return dp[x][y];
    if(x==y)
        return 0;
    if(str[x]==str[y])
    {
        if(y==x+1)
        {
            dp[x][y]=0;
            return 0;
        }
        else
            return (dp[x][y]=solve(x+1,y-1));
    }
    if(dp[x][y-1]==100000)
        dp[x][y-1]=solve(x,y-1);
    if(dp[x+1][y]==100000)
        dp[x+1][y]=solve(x+1,y);
    dp[x][y]=min(dp[x][y-1],dp[x+1][y])+1;
    return dp[x][y];
}



int main(void)
{
    scanf("%s",str);
    n=strlen(str);
    init();
    int ans=solve(0,n-1);
    cout<<ans<<endl;
    return 0;
}

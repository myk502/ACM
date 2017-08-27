#include<bits/stdc++.h>
using namespace std;

int dp[100][100];
int f[10];
int main(void)
{
	for(int i=0;i<100;i++)
		for(int j=0;j<100;j++)
			dp[i][j]=-10000000;
	dp[0][0]=0;
	f[1]=2;
	f[2]=1;
	f[3]=4;
	int n=3;
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=2*n-2;j++)
		{
			for(int x=1;x<=j-i+1;x++)
			{
				if(dp[i][j]<dp[i-1][j-x]+f[x])
				{
					dp[i][j]=dp[i-1][j-x]+f[x];
					printf("x=%d dp[%d][%d]=%d\n",x,i,j,dp[i][j]);
				}
				dp[i][j]=max(dp[i-1][j-x]+f[x],dp[i][j]);
			}
		}
	}
	cout<<dp[3][4]<<endl;
	return 0;
}

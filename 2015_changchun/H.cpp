#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<string>
#include<climits>
#include<algorithm>
using namespace std;
int n,dp[2][4030],f[2030];
int maxx[4030];
int main(void)
{
	int xx,T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=1;i<n;i++)
			scanf("%d",&f[i]);
		for(int i=0;i<=n;i++)
			for(int j=0;j<=2*n+2;j++)
				dp[i][j]=INT_MIN;
		dp[0][0]=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=2*n-2;j>=1;j--)
			{
				//dp[i][j]=maxx[j-i+1];
				for(int x=1;x<=j-i+1;x++)
				{
					dp[i][j]=max(dp[i][j],dp[i-1][j-x]+f[x]);
				}
			}
		}
		printf("%d\n",dp[n][2*n-2]);
	}
	return 0;
}

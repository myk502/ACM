#include<bits/stdc++.h>
using namespace std;
int t,n,m,k;
int dp[35][35],a[55];
void solve(int i,int j)
{
	for(int k=1;k<i;k++)
	{
		dp[i-k][j]=min(dp[i-k][j],j*j+dp[i][j]);
		dp[k][j]=min(dp[k][j],j*j+dp[i][j]);
	}
	for(int k=1;k<=j;j++)
	{
		dp[i][k]=min(dp[i][k],i*i+dp[i][j]);
		dp[i][j-k]=min(dp[i][j-k],dp[i][j]+i*i);
	}
}

int main(void)
{
	cin>>t;
	while(t--)
	{
		scanf("%d%d%d",&n,&m,&k);
		for(int i=0;i<35;i++)
			for(int j=0;j<35;j++)
				dp[i][j]=INT_MAX;
		for(int i=0;i<55;i++)
			a[i]=INT_MAX;
		dp[n][m]=0;
		a[0]=0;
		for(int i=n;i>=1;i--)
			for(int j=m;j>=1;j--)
			{
				for(int k=)
				dp[i][j]=min(dp[i][j],)
			}
		for(int i=1;i<=k;i++)
		{
			a[i]=min(dp[1][i],dp[i][1]);
			for(int j=2;j<sqrt(i);j++)
				if(i%j==0)
					a[i]=min(a[i],min(dp[j][i/j],dp[i/j][j]));
			for(int kk=1;kk<i;kk++)
				a[i]=min(a[i],a[kk]+a[k-kk]);
		}
		printf("%d\n",a[k]);
	}
	return 0;
}

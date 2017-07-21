#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int n,a[110],dp[110][5050],sum;
int main(void)
{
	cin>>n;
	sum=0;
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	for(int i=1;i<=n;i++)
		for(int j=0;j<=sum/2;j++)
		{
			if(j<a[i])//This number can not be chosen
				dp[i][j]=dp[i-1][j];
			else
				dp[i][j]=max(dp[i-1][j],dp[i-1][j-a[i]]+a[i]);
		}
	int ans=sum-2*dp[n][sum/2];
	printf("%d\n",ans);
	return 0;
}

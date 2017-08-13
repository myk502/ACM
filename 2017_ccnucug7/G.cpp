#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int n,k;
int num_2[210],num_5[210];
int dp[205][5400];
long long a[210];
int sum=0;
void init(int i)
{
	long long x=a[i];
	num_5[i]=num_2[i]=0;
	while((x!=0LL)&& (x%2LL==0LL))
	{
		num_2[i]++;
		x/=2LL;
	}
	while((x!=0LL) && (x%5LL==0LL) )
	{
		num_5[i]++;
		x/=5LL;
		sum++;
	}
}
int main(void)
{
	int ans=0;
	ios::sync_with_stdio(false);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		init(i);
	}
	memset(dp,-1,sizeof(dp));
	dp[k][0]=0;
	for(int i=1;i<=n;i++)
		for(int j=0;j<=k;j++)
			for(int m=sum+5;m>=0;m--)
			{
				int mm=m-num_5[i];
				if(mm<0)
					continue;
				if(dp[j+1][mm]!=-1)
					dp[j][m]=max(dp[j][m],dp[j+1][mm]+num_2[i]);
				if(j==0)
					ans=max(ans,min(dp[j][m],m));
			}
	cout<<ans<<endl;
	return 0;
}

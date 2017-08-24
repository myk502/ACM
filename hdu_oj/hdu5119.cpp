#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
long long dp[41][1<<20];
int n,m,k[1000000+10];
int main(void)
{
	int T;
	scanf("%d",&T);
	for(int ii=1;ii<=T;ii++)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			scanf("%d",&k[i]);
		memset(dp,0,sizeof(dp));
		dp[0][0]=1LL;
		for(int i=1;i<=n;i++)
		{
			int x=k[i];
			for(int mask=0;mask<(1<<20);mask++)
				dp[i][mask]=dp[i-1][mask]+dp[i-1][mask^x];
		}
		long long ans=0;
		for(int i=m;i<(1<<20);i++)
			ans+=dp[n][i];
		printf("Case #%d: ",ii);
		cout<<ans<<endl;
	}
	return 0;
}

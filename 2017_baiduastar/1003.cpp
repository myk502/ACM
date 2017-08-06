#include<cstdio>
#include<iostream>
#include<cmath>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;
const int maxn=100000+10;
int n,a[maxn],b[maxn],m,k[1010],p[1010];
int dp[1010][15];
const int maxx=INT_MAX/2;
int main(void)
{
	long long ans;
	bool flag;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		ans=0;
		flag=true;
		for(int i=1;i<=n;i++)
			scanf("%d%d",&a[i],&b[i]);
		for(int i=1;i<=m;i++)
			scanf("%d%d",&k[i],&p[i]);
		for(int i=0;i<1010;i++)
			for(int j=0;j<15;j++)
				dp[i][j]=maxx;
		for(int j=0;j<15;j++)
			dp[0][j]=0;
		for(int i=1;i<=1000;i++)
			for(int j=0;j<=10;j++)
			{
				for(int ii=1;ii<=m;ii++)
				{
					int x=p[ii],y=k[ii];
					if(x<=j)
						continue;
					if(i+j-x>=0)
						dp[i][j]=min(dp[i+j-x][j]+y,dp[i][j]);
					else
						dp[i][j]=min(y,dp[i][j]);
				}
			}
		for(int i=1;i<=n;i++)
		{
			int x=a[i],y=b[i];
			if(dp[x][y]==maxx)
				flag=false;
			ans+=dp[x][y];
		}
		if(!flag)
			printf("-1\n");
		else
			cout<<ans<<endl;
	}
	return 0;
}

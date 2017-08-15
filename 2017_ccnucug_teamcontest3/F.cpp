#include<cstdio>
#include<iostream>
#include<vector>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=100000+10;
int m,n,q,fa[maxn],dp[maxn];
vector<int> G[maxn];
vector<int> bad;
bool isgood[maxn];
bool visit[maxn];
void dfs_init(int x,int father)
{
	fa[x]=father;
	visit[x]=true;
	for(auto it:G[x])
	{
		if(!visit[it])
			dfs_init(it,x);
	}
}
int dfs(int x)
{
	if(dp[x]!=-1)
		return dp[x];
	if(isgood[x])
		return dp[x]=-1;
	int cnt=0;
	for(auto it:G[x])
	{
		if(cnt==2)
			break;
		if(it==fa[x])
			continue;
		if(isgood[it])
			cnt++;
		else
		{
			if(dp[it]==-1)
				cnt+=(dfs(it)!=0);
			else
				cnt+=(dp[it]!=0);
		}
	}
	return dp[x]=cnt;

}
int main(void)
{
	int T,u,v,ans;
	scanf("%d",&T);
	for(int i=0;i<maxn;i++)
		isgood[i]=true;
	memset(dp,-1,sizeof(dp));
	for(int ii=1;ii<=T;ii++)
	{
		printf("Case #%d:\n",ii);
		for(int i=0;i<maxn;i++)
		{
			G[i].clear();
		}
		scanf("%d%d",&n,&q);
		for(int i=0;i<n-1;i++)
		{
			scanf("%d%d",&u,&v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		memset(visit,0,sizeof(visit));
		dfs_init(1,-1);
		for(int i=0;i<q;i++)
		{
			bad.clear();
			scanf("%d",&m);
			for(int j=0;j<m;j++)
			{
				scanf("%d",&u);
				bad.push_back(u);
				isgood[u]=false;
			}
			ans=n-m;
			for(auto j:bad)
			{
				if(dp[j]==-1)
					dfs(j);
				//printf("dp[%d]=%d\n",j,dp[j]);
				if(dp[j]>=2)
					ans++;
			}
			for(auto j:bad)
			{
				isgood[j]=true;
				dp[j]=-1;
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}

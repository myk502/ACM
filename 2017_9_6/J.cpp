#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
const int maxn=6000+10;
int n,dp[maxn][2],val[maxn],fa[maxn];
vector<int> G[maxn];
bool visit[maxn];

void init(int x)
{
	visit[x]=true;
	for(auto to:G[x])
	{
		if(!visit[to])
		{
			fa[to]=x;
			init(to);
		}
	}
}

void dfs(int x)
{
	if(G[x].size()==1 && G[x][0]==fa[x])//This Node is leaf
	{
		dp[x][0]=0;
		dp[x][1]=val[x];
		return ;
	}
	for(auto to:G[x])
	{
		if(to==fa[x])
			continue;
		if(dp[to][0]==-1 || dp[to][1]==-1)
			dfs(to);
	}
	dp[x][0]=0;
	dp[x][1]=val[x];
	for(auto to:G[x])
	{
		if(to==fa[x])
			continue;
		dp[x][1]+=dp[to][0];
		dp[x][0]+=max(dp[to][0],dp[to][1]);
	}
}

int main(void)
{
	int aa,bb;
	while(scanf("%d",&n)!=EOF)
	{
		memset(dp,-1,sizeof(dp));
		for(int i=1;i<=n;i++)
			scanf("%d",&val[i]);
		memset(visit,0,sizeof(visit));
		memset(fa,-1,sizeof(fa));
		for(int i=0;i<maxn;i++)
			G[i].clear();
		while(scanf("%d%d",&aa,&bb))
		{
			if(aa==0 && bb==0)
				break;
			G[aa].push_back(bb);
			G[bb].push_back(aa);
		}
		init(1);
		dfs(1);
		int ans=max(dp[1][0],dp[1][1]);
		printf("%d\n",ans);
	}
	return 0;
}

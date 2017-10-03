#include<vector>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#include<climits>
#include<iostream>
#include<queue>
#include<stack>
#include<cstdio>
using namespace std;
const int maxn = 1000 + 10;
int n,m,cnt_dfn,cnt_scc,sccno[maxn],dfn[maxn],low[maxn],indegree[maxn],dp[maxn],sccnum[maxn];
vector<int> G[maxn];
int a[maxn][maxn];
stack<int> s;

struct Edge
{
	int from,to;
	Edge(int from = -1,int to = -1):from(from),to(to)
	{
	}
};
vector<Edge> edges;
queue<int> q;
void dfs(int x)
{
	s.push(x);
	low[x] = dfn[x] = ++cnt_dfn;
	for(auto it:G[x])
	{
		if(!dfn[it])
		{
			dfs(it);
			low[x] = min(low[x],low[it]);
		}
		else if(!sccno[it])
			low[x] = min(low[x],dfn[it]);
	}
	if(low[x] == dfn[x])
	{
		int temp;
		cnt_scc++;
		do
		{
			temp = s.top();
			s.pop();
			sccno[temp] = cnt_scc;
		}
		while(temp != x);
	}
}
			


void init(void)
{
	while(!s.empty())
		s.pop();
	while(!q.empty())
		q.pop();
	cnt_dfn = cnt_scc = 0;
	for(int i = 0; i < maxn;i++)
		G[i].clear();
	memset(sccnum,0,sizeof(sccnum));
	memset(dp,-1,sizeof(dp));
	memset(sccno,0,sizeof(sccno));
	memset(dfn,0,sizeof(dfn));
	memset(low,0,sizeof(low));
	memset(indegree,0,sizeof(indegree));
	edges.clear();
	memset(a,0,sizeof(a));
}

int main(void)
{
	int T,aa,bb;
	scanf("%d",&T);
	while(T--)
	{
		init();
		scanf("%d%d",&n,&m);
		for(int i = 0; i < m;i++)
		{
			scanf("%d%d",&aa,&bb);
			G[aa].push_back(bb);
			edges.push_back(Edge(aa,bb));
		}
		for(int i = 1;i <= n;i++)
			if(!dfn[i])
				dfs(i);
		for(auto it:edges)
		{
			int from = sccno[it.from];
			int to = sccno[it.to];
			if(from == to)
				continue;
			a[from][to] = 1;
			indegree[to]++;
		}
		for(int i = 1; i <= n;i++)
			sccnum[sccno[i]]++;
		for(int i = 1; i <= cnt_scc;i++)
			dp[i] = sccnum[i];
		for(int i = 1; i <= cnt_scc;i++)
			if(indegree[i] == 0)
				q.push(i);
		while(!q.empty())
		{
			int temp = q.front();
			q.pop();
			for(int to = 1; to <= cnt_scc;to++)
			{
				if(a[temp][to] == 0)
					continue;
				indegree[to]--;
				dp[to] = max(dp[to],dp[temp] + sccnum[to]);
				if(indegree[to] == 0)
					q.push(to);
			}
		}
		int ans = -1;
		for(int i = 1; i <= cnt_scc;i++)
			ans = max(ans,dp[i]);
		printf("%d\n",ans);
	}
	return 0;
}

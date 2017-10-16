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
vector<int> a[maxn];
stack<int> s;
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
			low[x] = min(low[x],low[it]);
	}
	if(low[x] == dfn[x])
	{
		cnt_scc++;
		while(true)
		{
			int v = s.top();
			s.pop();
			sccno[v] = cnt_scc;
			if(v == x)
				break;
		}
	}
}
			


void init(void)
{
	cnt_dfn = cnt_scc = 0;
	for(int i = 0; i < maxn;i++)
		G[i].clear();
	memset(sccno,0,sizeof(sccno));
	memset(dfn,0,sizeof(dfn));
}
int dfss(int x)
{
	if(dp[x])
		return dp[x];
	int ans = sccnum[x];
	for(auto to:a[x])
		ans = max(ans,sccnum[x] + dfss(to));
	return dp[x] = ans;
}
int main(void)
{
	ios::sync_with_stdio(false);
	int T,aa,bb;
	cin>>T;
	while(T--)
	{
		init();
		cin>>n>>m;
		for(int i = 0; i < m;i++)
		{
			cin>>aa>>bb;
			G[aa].push_back(bb);
		}
		for(int i = 1;i <= n;i++)
			if(!dfn[i])
				dfs(i);
		memset(dp,0,sizeof(dp));
		memset(sccnum,0,sizeof(sccnum));
		for(int i = 1; i <= cnt_scc;i++)
			a[i].clear();
		for(int i = 1; i <= n;i++)
			for(auto it:G[i])
			{
				int from = sccno[i];
				int to = sccno[it];
				if(from == to)
					continue;
				a[from].push_back(to);
			}
		for(int i = 1; i <= n;i++)
			sccnum[sccno[i]]++;
		for(int i = 1; i<= cnt_scc;i++)
			if(!dp[i])
				dfss(i);
		int ans = -1;
		for(int i = 1; i <= cnt_scc;i++)
			ans = max(ans,dp[i]);
		cout<<ans<<"\n";
	}
	return 0;
}

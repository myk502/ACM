#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<cmath>
#include<stack>
#include<algorithm>
using namespace std;
const int maxn = 20000 + 10;
vector<int> G[maxn];
stack<int> s;
int n,m,cnt_scc,cnt_dfs,dfn[maxn],low[maxn],sccno[maxn];
int indegree[maxn],outdegree[maxn];
void dfs(int x)
{
	s.push(x);
	dfn[x] = low[x] = ++cnt_dfs;
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
		cnt_scc++;
		while(s.top() != x)
		{
			int temp = s.top();
			s.pop();
			sccno[temp] = cnt_scc;
		}
		s.pop();
		sccno[x] = cnt_scc;
	}
}
struct Edge
{
	int from,to;
	Edge(int from = -1,int to = -1):from(from),to(to)
	{
	}
};
vector<Edge> edges;
int main(void)
{
	int cnt_indegree_0,cnt_outdegree_0;
	int T,aa,bb;
	scanf("%d",&T);
	while(T--)
	{
		for(int i = 0; i < maxn;i++)
			G[i].clear();
		edges.clear();
		scanf("%d%d",&n,&m);
		for(int i = 0; i < m;i++)
		{
			scanf("%d%d",&aa,&bb);
			G[aa].push_back(bb);
			edges.push_back(Edge(aa,bb));
		}
		while(!s.empty())
			s.pop();
		cnt_scc = cnt_dfs = 0;
		memset(dfn,0,sizeof(dfn));
		memset(low,0,sizeof(low));
		memset(indegree,0,sizeof(indegree));
		memset(outdegree,0,sizeof(outdegree));
		memset(sccno,0,sizeof(sccno));
		for(int i = 1; i <= n;i++)
			if(!dfn[i])
				dfs(i);
		for(auto it:edges)
		{
			int from = sccno[it.from];
			int to = sccno[it.to];
			if(from == to)
				continue;
			outdegree[from]++;
			indegree[to]++;
		}
		cnt_indegree_0 = cnt_outdegree_0 = 0;
		for(int i = 1; i <= cnt_scc; i++)
		{
			if(indegree[i] == 0)
				cnt_indegree_0++;
			if(outdegree[i] == 0)
				cnt_outdegree_0++;
		}
		if(cnt_scc == 1)
			cnt_indegree_0 = cnt_outdegree_0 = 0;
		printf("%d\n",max(cnt_indegree_0,cnt_outdegree_0));
	}
	return 0;
}

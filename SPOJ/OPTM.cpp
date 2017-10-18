#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<climits>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn = 500 + 10;
vector<int> GG[maxn];
int n, m, k,bits[32],num[maxn],numm[maxn];
long long ans;
const int INF = INT_MAX >> 2;
bool iszero[maxn];
struct Edge
{
	int from,to,cap,flow;
	Edge(int from = -1,int to = -1,int cap = 0,int flow = 0):from(from),to(to),cap(cap),flow(flow)
	{
	}
};

struct Dinic
{
	int n,m,s,t,d[maxn],cur[maxn];
	vector<int> G[maxn];
	vector<Edge> edges;
	bool visit[maxn];
	void init(int n)
	{
		this -> n = n;
		edges.clear();
		for(int i = 0; i < maxn; i++)
			G[i].clear();
	}
	void add_edge(int from,int to,int cap)
	{
		edges.push_back(Edge(from,to,cap,0));
		edges.push_back(Edge(to,from,cap,0));
		m = edges.size();
		G[from].push_back(m - 2);
		G[to].push_back(m - 1);
	}

	bool BFS(void)
	{
		memset(visit,0,sizeof(visit));
		queue<int> Q;
		Q.push(s);
		d[s] = 0;
		visit[s] = true;
		while(!Q.empty())
		{
			int x = Q.front();
			Q.pop();
			for(auto it:G[x])
			{
				Edge& e = edges[it];
				if(!visit[e.to] && e.cap > e.flow)
				{
					visit[e.to] = 1;
					d[e.to] = d[x] + 1;
					Q.push(e.to);
				}
			}
		}
		return visit[t];
	}

	int DFS(int x,int a)
	{
		if(x == t || a == 0)
			return a;
		int flow = 0, f;
		for(int& i = cur[x]; i < (int)G[x].size(); i++)
		{
			Edge& e = edges[G[x][i]];
			if(d[x] + 1 == d[e.to] && (f = DFS(e.to, min(a, e.cap - e.flow))) > 0)
			{
				e.flow += f;
				edges[G[x][i] ^ 1].flow -= f;
				flow += f;
				a -= f;
				if(a == 0)
					break;
			}
		}
		return flow;
	}
	void dfs(int u)
	{
		iszero[u] = true;
		for(auto it:G[u])
		{
			Edge& e = edges[it];
			if(e.cap - e.flow > 0)
				if(!iszero[e.to])
					dfs(e.to);
		}
	}
	int max_flow(int s,int t)
	{
		this -> s = s;
		this -> t = t;
		int flow = 0;
		while(BFS())
		{
			memset(cur,0,sizeof(cur));
			flow += DFS(s, INF);
		}
		memset(iszero, 0, sizeof(iszero));
		dfs(s);
		return flow;
	}
};
Dinic dinic;

int main(void)
{
	int T,u,v;
	bits[0] = 1;
	for(int i = 1; i < 32; i++)
		bits[i] = bits[i - 1] << 1;

	scanf("%d",&T);
	while(T--)
	{
		memset(numm, 0, sizeof(numm));
		for(int i = 0; i < maxn; i++)
			GG[i].clear();
		memset(num, -1, sizeof(num));
		scanf("%d%d",&n,&m);
		for(int i = 0; i < m; i++)
		{
			scanf("%d%d",&u,&v);
			GG[u].push_back(v);
			GG[v].push_back(u);
		}
		scanf("%d",&k);
		for(int i = 0; i < k; i++)
		{
			scanf("%d%d",&u,&v);
			num[u] = v;
		}
		ans = 0;
		for(int i = 0; i < 31; i++)
		{
			dinic.init(n + 2);
			for(int j = 1; j <= n; j++)
			{
				if(num[j] == -1)
					continue;
				if(num[j] & bits[i])//the num[j] has 1 at i-th bit
					dinic.add_edge(n + 1, j, INF >> 1);
				else
					dinic.add_edge(j, n + 2, INF >> 1);
			}
			for(int j = 1; j <= n; j++)
				for(auto it:GG[j])
					dinic.add_edge(j,it,1);
			dinic.max_flow(n + 1, n + 2);
			for(int j = 1; j <= n; j++)
				if(iszero[j])
					numm[j] += bits[i];
		}

		for(int i = 1; i <= n; i++)
			printf("%d\n",numm[i]);
	}
	return 0;
}

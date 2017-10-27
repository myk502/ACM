#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int maxn = 1000 + 10;
const long long INF = 1e12;
struct Edge
{
	int from,to;
	long long cap,flow;
	Edge(int from = 0,int to = 0,long long cap = 0,long long flow = 0):from(from),to(to),cap(cap),flow(flow)
	{
	}
};
struct Dinic
{
	int n,m,s,t;
	vector<Edge> edges;
	vector<int> G[maxn];
	bool visit[maxn];
	long long d[maxn];
	int cur[maxn];
	void init(int n)
	{
		this -> n = n;
		edges.clear();
		for(int i = 0; i < maxn; i++)
			G[i].clear();
	}
	void add_edge(int from,int to,long long cap)
	{
		edges.push_back(Edge(from,to,cap,0));
		edges.push_back(Edge(to,from,0,0));
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
					visit[e.to] = true;
					d[e.to] = d[x] + 1;
					Q.push(e.to);
				}
			}
		}
		return visit[t];
	}
	long long DFS(int x,long long a)
	{
		if(x == t || a == 0)
			return a;
		long long flow = 0, f;
		for(int& i = cur[x]; i < G[x].size(); i++)
		{
			Edge& e = edges[G[x][i]];
			if(d[x] + 1 == d[e.to] && (f = DFS(e.to,min(a,e.cap - e.flow))) > 0)
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
	long long max_flow(int s,int t)
	{
		this -> s = s;
		this -> t = t;
		long long flow = 0;
		while(BFS())
		{
			memset(cur,0,sizeof(cur));
			flow += DFS(s, INF);
		}
		return flow;
	}

};
Dinic dinic;

int main(void)
{
	int n,m,s,T;
	int u,v,w;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&m,&s);
		dinic.init(2 * n + 2);
		for(int i = 0; i < m; i++)
		{
			scanf("%d%d%d",&u,&v,&w);
			dinic.add_edge(u + n, v, w);
		}
		for(int i = 1; i <= n;i++)
		{
			scanf("%d",&u);
			dinic.add_edge(2 * n + 1, i, u);
		}
		for(int i = 1; i <= n;i++)
		{
			scanf("%d",&u);
			dinic.add_edge(i, i + n, u);
		}
		dinic.add_edge(s, 2 * n + 2,INF);
		printf("%lld\n",dinic.max_flow(2 * n + 1, 2 * n + 2));
	}
	return 0;
}


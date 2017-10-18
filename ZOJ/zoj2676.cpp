#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn = 100 + 10;
int n,m;
typedef pair<int,int> pii;
vector<pii> GG[maxn];
struct Edge
{
	int from,to;
	long long cap,flow;
	Edge(int from = -1,int to = -1,long long cap = 0,long long flow = 0):from(from),to(to),cap(cap),flow(flow)
	{
	}
};
struct Dinic
{
	int n, m, s, t;
	vector<Edge> edges;
	vector<int> G[maxn];
	bool visit[maxn];
	long long d[maxn];
	int cur[maxn];
	void Init(int n)
	{
		this -> n = n;
		edges.clear();
		for(int i = 0; i < maxn; i++)
			G[i].clear();

	}
	void Addedge(int from,int to,int cap)
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
		visit[s] = 1;
		while(!Q.empty())
		{
			int x = Q.front();
			Q.pop();
			for(int i = 0; i < G[x].size(); i++)
			{
				Edge& e = edges[G[x][i]];
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
	long long DFS(int x,long long a)
	{
		if(x == t || a == 0)
			return a;
		long long flow = 0, f;
		for(int& i = cur[x]; i < G[x].size(); i++)
		{
			Edge& e = edges[G[x][i]];
			if(d[x] + 1 == d[e.to] && (f = DFS(e.to, min(a, e.cap - e.flow))) > 0LL)
			{
				e.flow += f;
				edges[G[x][i]^1].flow -= f;
				flow += f;
				a -= f;
				if(a == 0)
					break;
			}
		}
		return flow;
	}

	int Maxflow(int s,int t)
	{
		this -> s = s;
		this -> t = t;
		long long flow = 0;
		while(BFS())
		{
			memset(cur, 0, sizeof(cur));
			flow += DFS(s,INF);
		}
		return flow;
	}
};
Dinic dinic;
double solve(double x)
{
	for(int i = 1; i <= n; i++)
	{
		
	}
}
int main(void)
{
	int u,v,w;
	double ll,rr,mid;
	while(scanf("%d%d",&n,&m) != EOF)
	{
		for(int i = 0; i < maxn; i++)
			GG[i].clear();
		ll = 1e7 + 10;
		rr = -1;
		for(int i = 0; i < m; i++)
		{
			scanf("%d%d%d",&u,&v,&w);
			ll = min(ll,w);
			rr = max(rr,w);
			GG[u].push_back(make_pair(v,w));
			GG[v].push_back(make_pair(u,w));
		}
		while(rr - ll > 1e-6)
		{
			mid = (ll + rr) / 2;

		}

	}
	return 0;
}

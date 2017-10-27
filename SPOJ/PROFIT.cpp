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
struct Edge
{
	int from,to;
	long long cap,flow;
	Edge(int from = -1,int to = -1,long long cap = 0,long long flow = 0):from(from),to(to),cap(cap),flow(flow)
	{
	}
};
int n, m;
const int maxn = 5000 + 100;
const long long INF = 1e11;
typedef pair<int,long long> pii;
vector<pii> GG[maxn];
long long p[maxn],sum[maxn],U;
struct Dinic
{
	int n,m,s,t,cur[maxn];
	long long d[maxn];
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
	void dfs(int x)
	{
		visit[x] = true;
		for(auto it:G[x])
		{
			Edge &e = edges[it];
			if(e.cap - e.flow > 0 && !visit[e.to])
				dfs(e.to);
		}
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
		/*
		memset(visit,0,sizeof(visit));
		dfs(s);
		long long tempans = 0;
		for(int i = 1; i <= n; i++)
		{
			if(i == s || i == t)
				continue;
			if(visit[i])
			{
				//tempans -= p[i];
				for(auto it:GG[i])
				{
					if(visit[it.first])
						tempans += it.second;
				}
			}
		}
		tempans /= 2;
		for(int i = 1; i <= n; i++)
		{
			if(i ==s || i == t)
				continue;
			if(visit[i])
				tempans -= p[i];
		}
		return tempans;
		*/
		return flow;

	}
};
Dinic dinic;

int main(void)
{
	int u, v,T;
	long long w;
	scanf("%d",&T);
	U = 500000LL * 200LL + 10LL;
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(int i = 1; i <= n; i++)
			scanf("%lld",&p[i]);
		for(int i = 0; i < maxn; i++)
			GG[i].clear();
		memset(sum, 0, sizeof(sum));
		for(int i = 0; i < m; i++)
		{
			scanf("%d%d%lld",&u,&v,&w);
			GG[u].push_back(make_pair(v,w));
			GG[v].push_back(make_pair(u,w));
			sum[u] += w;
			sum[v] += w;
		}
		dinic.init(n + 2);
		/*
		for(int i = 1; i <= n; i++)
			printf("sum[%d] = %lld, p[%d] = %lld\n",i,sum[i],i,p[i]);
		*/
		for(int i = 1; i <= n ; i++)
		{
			int to;
			long long cost;
			for(auto it:GG[i])
			{
				to = it.first;
				cost = it.second;
				dinic.add_edge(i, to, cost);
			}
			dinic.add_edge(n + 1, i, U);
			dinic.add_edge(i, n + 2, U + 2 * p[i] - sum[i]);
		}
		long long ans = dinic.max_flow(n + 1, n + 2);
		ans = (ans - U * n) / -2;
		printf("%lld\n",ans);
	}
	return 0;
}

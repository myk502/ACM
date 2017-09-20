#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<vector>
#include<queue>
#include<climits>
#include<algorithm>
using namespace std;
int n,m;
const int maxn = 2000 + 10;
struct Edge
{
	int from,to,cap,flow,cost;
	Edge(int from = -1,int to = -1,int cap = 0,int flow = 0,int cost = 0):from(from),to(to),cap(cap),flow(flow),cost(cost)
	{

	}
};

struct MCMF
{
	int n,m,s,t;
	vector<Edge> edges;
	vector<int> G[maxn];
	int inq[maxn],d[maxn],p[maxn],a[maxn];

	void init(int n)
	{
		this->n = n;
		for(int i = 1; i <= n; i++)
			G[i].clear();
		edges.clear();
	}

	void add_edge(int from,int to,int cap,int cost)
	{
		edges.push_back(Edge(from,to,cap,0,cost));
		edges.push_back(Edge(to,from,0,0,-cost));
		m = edges.size();
		G[from].push_back(m - 2);
		G[to].push_back(m - 1);
	}

	bool bellmanFord(int s,int t,int &flow,int &cost)
	{
		for(int i = 1;i <= n;i++)
			d[i] = INT_MAX;
		memset(inq,0,sizeof(inq));
		d[s] = 0;
		inq[s] = 1;
		p[s] = -1;//???
		a[s] = INT_MAX;
		queue<int> Q;
		Q.push(s);
		while(!Q.empty())
		{
			int u = Q.front();
			Q.pop();
			inq[u] = 0;
			for(auto it:G[u])
			{
				Edge &e = edges[it];
				if(e.cap > e.flow && d[e.to] > d[u] + e.cost)
				{
					d[e.to] = d[u] + e.cost;
					p[e.to] = it;
					a[e.to] = min(a[u],e.cap - e.flow);
					if(!inq[e.to])
					{
						Q.push(e.to);
						inq[e.to] = 1;
					}
				}
			}
		}
		if(d[t] == INT_MAX)
			return false;
		flow += a[t];
		cost += d[t] * a[t];
		int u = t;
		while(u != s)
		{
			edges[p[u]].flow += a[t];
			edges[p[u] ^ 1].flow -= a[t];
			u = edges[p[u]].from;
		}
		return true;
	}

	int min_cost(int s,int t)
	{
		int flow = 0,cost = 0;
		while(bellmanFord(s,t,flow,cost));
		return cost;
	}
};
MCMF mcmf;

int main(void)
{
	int u,v,w,s,t;
	while(scanf("%d%d",&n,&m) != EOF)
	{
		mcmf.init((n + 1) << 1);
		for(int i = 2;i <= n - 1; i++)
			mcmf.add_edge((i << 1) | 1 , (i << 1) , 1 , 0);
		mcmf.add_edge(3,2,2,0);
		mcmf.add_edge((n << 1) | 1 , (n << 1) , 2, 0);
		s = 1;
		t = (n + 1) << 1;
		mcmf.add_edge(s,3,2,0);
		mcmf.add_edge((n << 1),t,2,0);
		for(int i = 0; i < m; i++)
		{
			scanf("%d%d%d",&u,&v,&w);
			u = (u << 1);
			v = v << 1 | 1;
			mcmf.add_edge(u,v,1,w);
		}
		int ans = mcmf.min_cost(s,t);
		printf("%d\n",ans);
	}
	return 0;
}

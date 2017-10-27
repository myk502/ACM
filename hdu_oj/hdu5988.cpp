#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<vector>
#include<string>
#include<map>
#include<queue>
#include<algorithm>
#include<climits>
using namespace std;
const int maxn = 150;
const int INF = INT_MAX / 4;
struct Edge
{
	int from,to,cap,flow;
	float cost;
	Edge(int from = 0,int to = 0,int cap = 0, int flow = 0,float cost = 0):from(from),to(to),cap(cap),flow(flow),cost(cost)
	{
	}
};
struct MCMF
{
	int n, m, s, t;
	vector<Edge> edges;
	vector<int> G[maxn];
	int inq[maxn],p[maxn],a[maxn];
	float d[maxn];
	void init(int n)
	{
		this -> n = n;
		for(int i = 0; i < maxn; i++)
			G[i].clear();
		edges.clear();
	}
	void add_edge(int from, int to, int cap, float cost)
	{
		edges.push_back(Edge(from, to, cap, 0, cost));
		edges.push_back(Edge(to, from, 0, 0, -cost));
		m = edges.size();
		G[from].push_back(m - 2);
		G[to].push_back(m - 1);
	}
	bool BellmanFord(int s, int t, int &flow, float &cost)
	{
		for(int i = 0; i < maxn; i++)
			d[i] = INF;
		memset(inq,0,sizeof(inq));
		d[s] = 0;
		inq[s] = 1;	
		p[s] = 0;
		a[s] = INF;
		queue<int> Q;
		Q.push(s);
		while(!Q.empty())
		{
			int u = Q.front();
			Q.pop();
			inq[u] = 0;
			for(int i = 0; i < G[u].size(); i++)
			{
				Edge& e = edges[G[u][i]];
				if(e.cap > e.flow && d[e.to] > d[u] + e.cost)
				{
					d[e.to] = d[u] + e.cost;
					p[e.to] = G[u][i];
					a[e.to] = min(a[u], e.cap - e.flow);
					if(!inq[e.to])
					{
						Q.push(e.to);
						inq[e.to] = 1;
					}
				}
			}
		}
		if(fabs(d[t] - INF) < 0.001)
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
	float min_cost(int s,int t)
	{
		int flow = 0;
		float  cost = 0;
		while(BellmanFord(s, t, flow, cost));
		return cost;
	}
};
MCMF mcmf;
int main(void)
{
	int T,n,m,s[maxn],b[maxn];
	int u,v,c;
	float p;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		mcmf.init(n + 2);
		for(int i = 1; i <= n; i++)
		{
			scanf("%d%d",&s[i],&b[i]);
			if(b[i] - s[i] > 0)
				mcmf.add_edge(i, n + 2,b[i] - s[i],0);
			if(b[i] - s[i] < 0)
				mcmf.add_edge(n + 1, i ,s[i] - b[i],0);
		}
		for(int i = 0 ; i < m; i++)
		{
			scanf("%d%d%d%f",&u,&v,&c,&p);
			p = -log2(1 - p);
			if(c > 0)
				mcmf.add_edge(u, v, 1, 0);
			if(c > 1)
				mcmf.add_edge(u, v, c - 1, p);
		}
		float temp = mcmf.min_cost(n + 1, n + 2);
		temp = pow(2,-temp);
		printf("%.2f\n",1.0 - temp);
	}
	return 0;
}

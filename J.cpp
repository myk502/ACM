#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
int n, m;
long long x;
const int maxn = 2000 + 100;
struct Edge
{
	int from,to,cost;
	Edge(int from = -1, int to = -1, long long cost = 0):from(from), to(to), cost(cost)
	{
	}
};
const long long INF = 1000000000000000;
struct BellmanFord
{
	int m, n;
	vector<Edge> edges;
	vector<int> G[maxn];
	bool inq[maxn];
	int p[maxn], cnt[maxn];
	long long d[maxn];
	void init(int n)
	{
		this -> n = n;
		for(int i = 0; i < n; i++)
			G[i].clear();
		edges.clear();
	}
	void AddEdge(int from, int to, int cost)
	{
		edges.push_back(Edge(from, to, cost));
		m = edges.size();
		G[from].push_back(m - 1);
	}

	bool negativeCycle(int s)
	{
		queue<int> Q;
		memset(inq, 0, sizeof(inq));
		memset(cnt, 0, sizeof(cnt));
		for(int i = 0; i < n; i++)
			d[i] = INF;
		d[s] = 0;
		inq[s] = true;
		Q.push(s);
		while(!Q.empty())
		{
			int u = Q.front();
			Q.pop();
			inq[u] = false;
			for(int i = 0; i < G[u].size(); i++)
			{
				Edge& e = edges[G[u][i]];
				if(d[u] < INF && d[e.to] > d[u] + e.cost)
				{
					d[e.to] = d[u] + e.cost;
					p[e.to] = G[u][i];
					if(!inq[e.to])
					{
						Q.push(e.to);
						inq[e.to] = true;
						if(++cnt[e.to] > n)
							return false;
					}
				}
			}
		}
		return true;
	}
};
BellmanFord bf;
void add_edge(int from, int to, long long val)
{
	bf.AddEdge(from, to, val);
}
int main(void)
{
	int T;
	int a, b, c, d;
	scanf("%d", &T);
	for(int ii = 1; ii <= T; ii++)
	{
		scanf("%d%d", &n, &m);
		bf.init(n + 1);
		cin >> x;
		for(int i = 0; i < m; i++)
		{
			scanf("%d%d%d%d", &a, &b, &c, &d);
			if((a != b) && (c != d))
			{
				add_edge(d, a, -x - 1);
				add_edge(b, c, x - 1);
				add_edge(b, a, -1);
				add_edge(d, c, -1);
			}
			if((a == b) && (c != d))
			{
				add_edge(a, c, x - 1);
				add_edge(d, a, -x - 1);
			}
			if((a != b) && (c == d))
			{
				add_edge(c, a, -x - 1);
				add_edge(b, c, x - 1);
			}
			if((a == b) && (c == d))
			{
				add_edge(a, c, x);
				add_edge(c, a, -x);
			}
		}
		for(int i = 1; i <= n; i++)
			add_edge(0, i, 0);
		for(int i = 2; i <= n; i++)
		{
			add_edge(i, i - 1, -1);
			add_edge(i - 1, i, 2000000000);
		}
		if(!bf.negativeCycle(0))
		{
			printf("Case #%d: IMPOSSIBLE\n", ii);
			continue;
		}
		printf("Case #%d: ", ii);
		for(int i = 1; i < n; i++)
			printf("%lld ", bf.d[i + 1] - bf.d[i]);
		printf("\n");

	}
	return 0;
}

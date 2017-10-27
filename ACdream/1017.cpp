#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<climits>
#include<algorithm>
#include<queue>
#include<map>
using namespace std;
const int maxn = 50000;
const int inf = INT_MAX / 2;
struct edge
{
	int from,to,cap,flow;
	edge(int from = 0, int to = 0, int cap = 0,int flow = 0):from(from),to(to),cap(cap),flow(flow)
	{
	}
};
struct dinic
{
	int n,m,s,t;
	vector<edge> edges;
	vector<int> g[maxn];
	bool visit[maxn];
	int d[maxn];
	int cur[maxn];
	void init(int n)
	{
		this -> n = n;
		edges.clear();
		for(int i = 0; i < maxn; i++)
			g[i].clear();
	}

	void add_edge(int from,int to,int cap)
	{
		edges.push_back(edge(from,to,cap,0));
		edges.push_back(edge(to,from,0,0));
		m = edges.size();
		g[from].push_back(m - 2);
		g[to].push_back(m - 1);
	}

	bool bfs(void)
	{
		memset(visit,0,sizeof(visit));
		queue<int> q;
		q.push(s);
		d[s] = 0;
		visit[s] = true;
		while(!q.empty())
		{
			int x = q.front();
			q.pop();
			for(int i = 0; i < g[x].size(); i++)
			{
				edge& e = edges[g[x][i]];
				if(!visit[e.to] && e.cap > e.flow)
				{
					visit[e.to] = true;
					d[e.to] = d[x] + 1;
					q.push(e.to);
				}
			}
		}
		return visit[t];
	}
	int dfs(int x,int a)
	{
		if(x == t || a == 0)
			return a;
		int flow = 0, f;
		for(int& i = cur[x]; i < g[x].size(); i++)
		{
			edge& e = edges[g[x][i]];
			if(d[x] + 1 == d[e.to] && ( f = dfs(e.to, min(a, e.cap - e.flow))) > 0)
			{
				e.flow += f;
				edges[g[x][i] ^ 1].flow -= f;
				flow += f;
				a -= f;
				if(a == 0)
					break;
			}
		}
		return flow;
	}
	int max_flow(int s,int t)
	{
		this -> s = s;
		this -> t = t;
		int flow = 0;
		while(bfs())
		{
			memset(cur, 0, sizeof(cur));
			flow += dfs(s, inf);
		}
		return flow;
	}
};
dinic dinic;
int n,m,s,k,t;
int a[15][15];
bool judge(int x)//to justify whether we can deliver all goods within x days
{
	dinic.init((x + 1) * n + 2);
	int ss = (x + 1) * n + 1;
	int tt = (x + 1) * n + 2;
	dinic.add_edge(ss, s, k);
	for(int lv = 1; lv <= x + 1; lv++)
	{	
		int temp = (lv - 1) * n;
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
			{
				if(lv == x + 1)
					continue;
				if(a[i][j] == 0)
					continue;
				if(i != j)
					dinic.add_edge(temp + i, temp + j + n, 1);
				else
					dinic.add_edge(temp + i, temp + j + n, inf / 30);

			}
		dinic.add_edge(temp + t, tt,inf);
	}
	int ans = dinic.max_flow(ss,tt);
	return ans == k;
}
int main(void)
{
	int u,v;
	while(scanf("%d%d%d%d%d",&n,&m,&k,&s,&t) != EOF)
	{
		memset(a,0,sizeof(a));
		for(int i = 0; i < m; i++)
		{
			scanf("%d%d",&u,&v);
			a[u][v] = a[v][u] = 1;
		}
		for(int i = 1; i <= n; i++)
			a[i][i] = 1;
		int ll = 0, rr = 70, mid;
		while(rr - ll > 1)
		{
			mid = (ll + rr) / 2;
			if(judge(mid))
				rr = mid;
			else
				ll = mid;
		}
		printf("%d\n",rr);
		/*
		int ll = 0, rr = n * k;
		while(rr > ll)
		{
			int mid = (ll + rr) / 2;
			if(judge(mid))
				rr = mid;
			else
				ll = mid + 1;
		}
		printf("%d\n",ll);
		*/
	}
	return 0;
}

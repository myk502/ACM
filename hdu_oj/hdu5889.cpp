#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
const int maxn = 2000;
const int INF = 1e9 / 2;
struct Edge
{
	int from,to,cap,flow;
	Edge(int from = 0,int to = 0,int cap = 0,int flow = 0):from(from),to(to),cap(cap),flow(flow)
	{
	}
};
struct Dinic
{
	int n,m,s,t;
	vector<Edge> edges;
	vector<int> G[maxn];
	bool visit[maxn];
	int d[maxn],cur[maxn];
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

	int DFS(int x,int a)
	{
		if(x == t || a == 0)
			return a;
		int flow = 0, f;
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
	int max_flow(int s,int t)
	{
		this -> s = s;
		this -> t = t;
		int flow = 0;
		while(BFS())
		{
			memset(cur,0,sizeof(cur));
			flow += DFS(s,INF);
		}
		return flow;
	}
};
Dinic dinic;
vector<int> GG[maxn];
int dis[maxn];
int a[1010][1010];
bool visit[maxn];
int main(void)
{
	int T,n,m;
	int u,v,w;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		dinic.init(n);
		dis[n] = 0;
		for(int i = 0 ; i < maxn;i++)
			GG[i].clear();
		for(int i = 0; i < m; i++)
		{
			scanf("%d%d%d",&u,&v,&w);
			GG[u].push_back(v);
			GG[v].push_back(u);
			a[u][v] = a[v][u] = w;
		}
		for(int i = 1; i < n; i++)
			dis[i] = INF;
		for(auto it:GG[n])
			dis[it] = 1;
		memset(visit,0,sizeof(visit));
		visit[n] = true;
		for(int ii = 1; ii < n; ii++)
		{
			int minn = INF,min_id;
			for(int i = 1; i <= n; i++)
			{
				if(visit[i])
					continue;
				if(dis[i] < minn)
				{
					minn = dis[i];
					min_id = i;
				}
			}
			visit[min_id] = true;
			for(auto to:GG[min_id])
				dis[to] = min(dis[to],dis[min_id] + 1);
		}
		for(int i = 1; i <= n; i++)
		{
			for(auto it:GG[i])
			{
				if(dis[it] - dis[i] == 1)
					dinic.add_edge(i,it,a[i][it]);
			}
		}
		printf("%d\n",dinic.max_flow(n,1));
	}
	return 0;
}

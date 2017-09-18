#include<cstdio>
#include<vector>
#include<cstring>
#include<string>
#include<climits>
#include<queue>
#include<iostream>
#include<algorithm>
using namespace std;

const int maxn = 200+10;
const int maxm = 2000 + 10;

struct Edge
{
	int from,to,cap,flow;
	Edge()
	{

	}
	Edge(int from,int to,int cap,int flow)
	{
		this->flow = flow;
		this->from = from;
		this->to = to;
		this->cap = cap;
	}
};

struct Dinic
{
	int n,m,s,t;
	vector<Edge> edges;
	vector<int> G[maxn];
	bool vis[maxn];
	int d[maxn];
	int cur[maxn];

	void init(int n)
	{
		this->n = n;
		for(int i = 1;i<=n;i++)
			G[i].clear();
		edges.clear();
	}
	
	void add_edge(int from,int to,int cap)
	{
		edges.push_back(Edge(from,to,cap,0));
		edges.push_back(Edge(to,from,0,0));
		m = edges.size();
		G[from].push_back(m-2);
		G[to].push_back(m-1);
	}

	bool BFS(void)
	{
		memset(vis,0,sizeof(vis));
		queue<int> Q;
		Q.push(s);
		d[s] = 0;
		vis[s] = 1;
		while(!Q.empty())
		{
			int x = Q.front();
			Q.pop();
			for(int i = 0;i < G[x].size();i++)
			{
				Edge& e = edges[G[x][i]];
				if(!vis[e.to] && e.cap>e.flow)
				{
					vis[e.to] =1;
					d[e.to] = d[x]+1;
					Q.push(e.to);
				}
			}
		}
		return vis[t];
	}

	int DFS(int x,int a)
	{
		if(x == t || a == 0)
			return a;
		int flow = 0, f;
		for(int& i=cur[x];i<G[x].size();i++)
		{
			Edge& e = edges[G[x][i]];
			if(d[x] + 1 == d[e.to] && (f = DFS(e.to,min(a,e.cap - e.flow))) > 0)
			{
				e.flow += f;
				edges[G[x][i]^1].flow -= f;
				flow += f;
				a -= f;
				if(a==0)
					break;
			}
		}
		return flow;
	}
	int Maxflow(int s,int t)
	{
		this->s = s;
		this->t = t;
		int flow = 0;
		while(BFS())
		{
			memset(cur,0,sizeof(cur));
			flow += DFS(s,INT_MAX);
		}
		return flow;
	}
	
	int getmincut(int s,int t)
	{
		int cutedge = 0;
		for(int i=1;i<=n;i++)
			vis[i] = 0;
		queue<int> q;
		q.push(s);
		vis[s] = 1;
		while(!q.empty())
		{
			int cur = q.front();
			q.pop();
			for(auto it:G[cur])
			{
				int v = edges[it].to;
				if(it%2==0 && edges[it].flow==0)
				{
					edges[it].flow = 1;
					edges[it^1].flow=0;
				}
				else if(it%2==0 && edges[it].flow>0)
				{
 
				edges[it].flow = 0;
				edges[it^1].flow = edges[it].cap;
				}
			}
		}
		return Maxflow(s,t);
	}
};
Dinic dinic;
int main(void)
{
	int T,n,m,s,w,t,u,v;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		dinic.init(n);
		scanf("%d%d",&s,&t);
		for(int i = 0; i < m;i++)
		{
			scanf("%d%d%d",&u,&v,&w);
			dinic.add_edge(u,v,w);
		}
		dinic.Maxflow(s,t);
		//cout<<dinic.Maxflow(s,t)<<endl;
		int ans = dinic.getmincut(s,t);
		printf("%d\n",ans);

	}
	return 0;
}

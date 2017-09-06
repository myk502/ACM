#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cmath>
#include<queue>
#include<climits>
#include<vector>
#include<string>
#include<cstring>
using namespace std;
const int maxn=20;
struct Edge
{
	int from,to,cap,flow;
	Edge(int u,int v,int c,int f):from(u),to(v),cap(c),flow(f)
	{

	}
};
struct EdmondsKarp
{
	int n,m;
	vector<Edge> edges;
	int G[20][20],a[maxn],p[maxn];

	void init(int n)
	{
		this->n=n;
		memset(G,-1,sizeof(G));
		edges.clear();
	}
	void add_edge(int from,int to,int cap)
	{
		if(G[from][to]!=-1)
		{
			edges[G[from][to]].cap+=cap;
			return;
		}
		edges.push_back(Edge(from,to,cap,0));
		edges.push_back(Edge(to,from,0,0));
		m=edges.size();
		G[from][to]=m-2;
		G[to][from]=m-1;
	}

	int max_flow(int s,int t)
	{
		int flow=0;
		while(1)
		{
			memset(a,0,sizeof(a));
			queue<int> Q;
			Q.push(s);
			a[s]=INT_MAX;
			while(!Q.empty())
			{
				int x=Q.front();
				Q.pop();
				for(int to=1;to<=n;to++)
				{
					if(G[x][to]==-1)
						continue;
					Edge& e=edges[G[x][to]];
					if(!a[e.to] && e.cap>e.flow)
					{
						p[e.to]=G[x][to];
						a[e.to]=min(a[x],e.cap-e.flow);
						Q.push(e.to);
					}

				}
				if(a[t])
					break;
			}
			if(!a[t])
				break;
			for(int u=t;u!=s;u=edges[p[u]].from)
			{
				edges[p[u]].flow+=a[t];
				edges[p[u]^1].flow-=a[t];
			}
			flow+=a[t];
		}
		return flow;
	}
	
};
EdmondsKarp ek;
int main(void)
{
	int T,n,m;
	int u,v,capacity;
	scanf("%d",&T);
	for(int ii=1;ii<=T;ii++)
	{
		scanf("%d%d",&n,&m);
		ek.init(n);
		for(int i=0;i<m;i++)
		{
			scanf("%d%d%d",&u,&v,&capacity);
			ek.add_edge(u,v,capacity);
		}
		printf("Case %d: %d\n",ii,ek.max_flow(1,n));
	}
	return 0;
}

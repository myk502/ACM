#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<climits>
#include<queue>
#include<vector>
using namespace std;
const int maxn = 25;
int r,c,x[maxn],y[maxn],a[maxn],b[maxn];
int ANS[25][25];
struct Edge
{
	int from,to,cap,flow;
	Edge(int from = -1,int to = -1,int cap = -1,int flow = -1):from(from),to(to),cap(cap),flow(flow)
	{

	}
};

struct EdmondsKarp
{
	int n,m,G[45][45],a[45],p[45];
	vector<Edge> edges;
	void init(int n)
	{
		this->n = n;
		edges.clear();
		memset(G,-1,sizeof(G));
	}

	void add_edge(int from,int to,int cap)
	{
		edges.push_back(Edge(from,to,cap,0));
		edges.push_back(Edge(to,from,0,0));
		int m = edges.size();
		G[from][to] = m - 2;
		G[to][from] = m - 1;
	}

	int max_flow(int s,int t)
	{
		int flow = 0;
		while(1)
		{
			memset(a,0,sizeof(a));
			a[s] = INT_MAX;
			queue<int> Q;
			Q.push(s);
			while(!Q.empty())
			{
				int x = Q.front();
				Q.pop();
				for(int i = 0;i<n;i++)
				{
					if(G[x][i]==-1)
						continue;
					Edge &e = edges[G[x][i]];
					if(a[e.to]!=0 || e.cap - e.flow <=0)
						continue;
					p[i] = G[x][i];
					a[i] = min(a[x],e.cap - e.flow);
					Q.push(i);
				}
				if(a[t])
					break;
			}
			if(!a[t])
				break;
			for(int u = t;u != s;u = edges[p[u]].from)
			{
				edges[p[u]].flow += a[t];
				edges[p[u]^1].flow -= a[t];
			}
			flow += a[t];
		}
		return flow;
	}
	void solve(void)
	{
		for(int i = 1;i <= r;i++)
			for(int j = r + 1;j <= r + c;j++)
			{
				Edge &e = edges[G[i][j]];
				ANS[i][j - r] = e.flow + 1;
			}
	}
};
EdmondsKarp ek;

int main(void)
{
	int T,s,t;
	scanf("%d",&T);
	for(int ii = 1; ii<=T;ii++)
	{
		scanf("%d%d",&r,&c);
		for(int i=1;i<=r;i++)
			scanf("%d",&a[i]);
		for(int i=1;i<=c;i++)
			scanf("%d",&b[i]);
		x[1] = a[1];
		for(int i=2;i<=r;i++)
			x[i] = a[i] - a[i-1];
		y[1] = b[1];
		for(int i=2;i<=c;i++)
			y[i] = b[i] - b[i-1];
		ek.init(r + c + 2);
		s = 0;
		t = r + c + 1;
		for(int i = 1; i <= r;i++)
		{
			ek.add_edge(s,i,x[i]-c);
		}
		for(int j = r + 1;j <= r + c;j++)
		{
			ek.add_edge(j,t,y[j-r]-r);
		}
		for(int i = 1;i<= r;i++)
		{
			for(int j = r + 1;j <= r+c;j++)
				ek.add_edge(i,j,19);
		}
		int ans = ek.max_flow(s,t);
		ek.solve();
		if(ii!=1)
			printf("\n");
		printf("Matrix %d\n",ii);
		for(int i = 1;i <= r; i++)
		{
			printf("%d",ANS[i][1]);
			for(int j = 2;j <= c;j++)
			{
				printf(" %d",ANS[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}

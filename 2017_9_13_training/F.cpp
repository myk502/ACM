#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
struct Edge
{
	int from,to,cost;
	Edge(int from=-1,int to=-1,int cost=0):from(from),to(to),cost(cost)
	{

	}
	bool operator <(const Edge& X)const
	{
		return this->cost < X.cost;
	}
};
vector<int> G;
Edge e[50000+10];
int n,m,fa[510],cnt_edge,cost;
int find_ancestor(int x)
{
	int r=x;
	while(fa[r]!=r)
		r=fa[r];
	int i=x,j;
	while(i!=r)
	{
		j=fa[i];
		fa[i]=r;
		i=j;
	}
	return r;
}

bool join(int x,int y)
{
	int fx=find_ancestor(x);
	int fy=find_ancestor(y);
	if(fx!=fy)
	{
		fa[fx]=fy;
		return true;
	}
	return false;
}
int main(void)
{
	int u,v,w;
	int ans=0,ans_cost=0;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)
	{
		scanf("%d%d%d",&u,&v,&w);
		e[i]=Edge(u,v,w);
	}
	for(int i=1;i<=n;i++)
		fa[i]=i;
	sort(e,e+m);
	cost=0;
	for(int i=0;i<m;i++)
	{
		int from=e[i].from;
		int to=e[i].to;
		if(join(from,to))
		{
			cost += e[i].cost;
			cnt_edge++;
			G.push_back(i);
		}
		if(cnt_edge == n-1)
			break;
	}
	for(auto it:G)
	{
		for(int i=1;i<=n;i++)
			fa[i] = i;
		int temp_cost=0;
		cnt_edge = 0;
		for(int i=0;i<m;i++)
		{
			if(i == it)
				continue;
			int from=e[i].from;
			int to=e[i].to;
			if(join(from,to))
			{
				temp_cost += e[i].cost;
				cnt_edge++;
			}
			if(cnt_edge == n-1)
				break;
		}
		if(cnt_edge != n-1)
		{
			ans++;
			ans_cost += e[it].cost;
		}
		else if(temp_cost > cost)
		{
			ans++;
			ans_cost += e[it].cost;
		}
	}
	printf("%d %d\n",ans,ans_cost);
	return 0;
}

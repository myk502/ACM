#include<cstdio>
#include<string>
#include<iostream>
#include<cstring>
#include<cmath>
#include<set>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
using namespace std;
int n,m;
const int INF = 500000000 + 10;
double d[55];

struct Edge
{
	int from,to;
	double cost;
	Edge(int from = -1,int to= -1,double cost = 0):from(from),to(to),cost(cost)
	{

	}
};
Edge e[2500 + 10];

bool judge(double x)
{
	bool flag = false;
	for(int i = 1;i <= n;i++)
		d[i] = INF;
	for(int i = 0;i <= n;i++)
	{
		for(int j = 0;j < m;j++)
		{
			int from = e[j].from;
			int to = e[j].to;
			double cost = e[j].cost - x;
			if(d[from] + cost < d[to])
			{
				d[to] = d[from] + cost;
				if(i == n)
					flag = true;
			}
		}
	}
	return flag;
}

int main(void)
{
	int u,v,w,T,minn,maxx;
	double mid;
	scanf("%d",&T);
	for(int ii = 1;ii <= T;ii++)
	{
		scanf("%d%d",&n,&m);
		for(int i = 0;i < m;i++)
		{
			scanf("%d%d%d",&u,&v,&w);
			e[i] = Edge(u,v,w);
			minn = min(minn,w);
			maxx = max(maxx,w);
		}
		double ll = minn - 1;
		double rr = maxx + 1;
		if(!judge(rr))
		{
			printf("Case #%d: No cycle found.\n",ii);
			continue;
		}
		while(rr - ll > 0.00001)
		{
			mid = (ll + rr) / 2;
			if(judge(mid))
				rr = mid;
			else
				ll = mid;
		}
		printf("Case #%d: %.2lf\n",ii,mid);

	}
	
	
	return 0;
}

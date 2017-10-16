#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn = 1000 + 10;
struct Point
{
	int x,y;
	Point(int x = 0,int y = 0):x(x),y(y)
	{
	}
};

Point P[maxn];
int a[maxn],n,pre[maxn];
double dis[maxn][maxn],maxcost[maxn][maxn],b[maxn],cost_MST;
vector<int> G[maxn];//to store the MST
bool visit[maxn];

double cal_dis(Point X,Point Y)
{
	double temp = (X.x - Y.x) * (X.x - Y.x);
	temp += (X.y - Y.y) * (X.y - Y.y);
	return sqrt(temp);
}

void prim(void)
{
	memset(visit,0,sizeof(visit));
	visit[1] = true;
	for(int i = 1; i <= n;i++)
	{
		pre[i] = 1;
		b[i] = dis[1][i];
	}
	pre[1] = -1;
	int min_id;
	double minn = 1000000;
	for(int ii = 1; ii < n; ii++)
	{
		minn = 100000000;
		for(int i = 1; i <= n;i++)
			if(!visit[i] && b[i] < minn)
			{
				minn = b[i];
				min_id = i;
			}
		visit[min_id] = true;
		cost_MST += minn;
		for(int j = 1; j <= n;j++)
			if(!visit[j] && dis[min_id][j] < b[j])
			{
				b[j] = dis[min_id][j];
				pre[j] = min_id;
			}
	}
	for(int i = 2; i <= n; i++)
	{
		int to = pre[i];
		G[to].push_back(i);
		G[i].push_back(to);
	}
}
void dfs(int root,int x,int fa)
{
	if(fa == -1)
		maxcost[root][root] = 0;
	else
		maxcost[root][x] = max(maxcost[root][fa],dis[fa][x]);
	for(auto to:G[x])
		if(to != fa)
			dfs(root,to,x);
}
int main(void)
{
	int T;
	double aa,bb,ans;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		cost_MST = 0;
		ans = -1;
		for(int i = 0 ; i < maxn; i++)
			G[i].clear();
		for(int i = 1; i <= n; i++)
			scanf("%d%d%d",&P[i].x,&P[i].y,&a[i]);
		for(int i = 1; i <= n; i++)
			for(int j = i + 1; j <= n; j++)
				dis[i][j] = dis[j][i] = cal_dis(P[i],P[j]);
		for(int i = 1; i <= n;i++)
			dis[i][i] = 0;
		prim();
		for(int i = 1; i <= n; i++)
			dfs(i,i,-1);
		for(int i = 1; i <= n; i++)
			for(int j = i + 1; j <= n; j++)//For every edge in this graph
			{
				aa = a[i] + a[j];
				bb = cost_MST - maxcost[i][j];
				ans = max(ans,aa/bb);
			}
		printf("%.2f\n",ans);
	}
	return 0;
}

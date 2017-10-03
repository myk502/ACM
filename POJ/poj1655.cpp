#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn = 20000 + 10;
int sum[maxn],n,anss[maxn];
vector<int> G[maxn];
void dfs(int x,int fa)
{
	sum[x] = 1;
	for(int j = 0; j < G[x].size();j++)
	{
		int to = G[x][j];
		if(to == fa)
			continue;
		if(sum[to] == -1)
			dfs(to,x);
		sum[x] += sum[to];
	}
	anss[x] = n - sum[x];
	for(int j = 0; j < G[x].size();j++)
	{
		int to = G[x][j];
		if(to == fa)
			continue;
		anss[x] = max(anss[x],sum[to]);
	}
}
int main(void)
{
	int T,aa,bb;
	int minn,min_id;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i = 0 ; i < maxn;i++)
			G[i].clear();
		for(int i = 1; i < n;i++)
		{
			scanf("%d%d",&aa,&bb);
			G[aa].push_back(bb);
			G[bb].push_back(aa);
		}
		memset(sum,-1,sizeof(sum));
		dfs(1,-1);
		minn = maxn << 1;
		min_id = -1;
		for(int i = 1;i <= n; i++)
		{
			if(anss[i] < minn)
			{
				minn = anss[i];
				min_id = i;
			}
		}
		printf("%d %d\n",min_id,minn);
	}
	return 0;
}

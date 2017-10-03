#include<cstdio>
#include<iostream>
#include<cmath>
#include<map>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 100000 + 10;
map<int,int> cnt[maxn];
map<int,long long> sum[maxn];
int n,color[maxn];
vector<int> G[maxn];
long long ans[maxn];

void dfs(int x,int fa)
{
	//printf("We are now visting %d\n",x);
	int c = color[x];
	cnt[x][c]++;
	sum[x][1] = c;
	for(auto it:G[x])
	{
		if(it == fa)
			continue;
		dfs(it,x);
		if(cnt[x].size() < cnt[it].size())
		{
			swap(sum[x],sum[it]);
			swap(cnt[x],cnt[it]);
		}
		for(auto j:cnt[it])
		{
			int color = j.first;
			int cnt_color = j.second;
			if(cnt[x][color] == 0)//The color does not exist in x
			{
				cnt[x][color] = cnt_color;
				sum[x][cnt_color] += color;
			}
			else
			{
				sum[x][cnt[x][color]] -= color;
				cnt[x][color] += cnt_color;
				sum[x][cnt[x][color]] += color;
			}

		}
	}
	auto it = sum[x].end();
	it--;
	ans[x] = it->second;
}

int main(void)
{
	int xx,yy;
	scanf("%d",&n);
	for(int i = 1;i <= n;i++)
		scanf("%d",&color[i]);
	for(int i = 1;i < n;i++)
	{
		scanf("%d%d",&xx,&yy);
		G[xx].push_back(yy);
		G[yy].push_back(xx);
		memset(ans,0,sizeof(ans));
	}
	dfs(1,-1);
	for(int i = 1;i <= n;i++)
		printf("%I64d ",ans[i]);
	printf("\n");
	return 0;
}

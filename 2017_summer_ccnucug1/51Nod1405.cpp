#include<cstdio>
#include<iostream>
#include<cstring>
#include<set>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=100000+10;
int n,num[maxn],depth[maxn];
bool visit[maxn];
long long dp[maxn];
vector<int> G[maxn];
int dfs1(int x,int dep)
{
	//calculate the dpeth of each Node and number of its subtree(including itself)
	int sum=1;//the number of its subtree including itself
	depth[x]=dep;
	visit[x]=true;
	for(auto it:G[x])
	{
		if(!visit[it])
			sum+=dfs1(it,dep+1);
	}
	return num[x]=sum;
}
void dfs2(int x)
{
	for(auto it:G[x])
	{
		if(dp[it]==-1)
		{
			dp[it]=dp[x]+(n-num[it])-num[it];
			dfs2(it);
		}
	}

}
void init(void)
{
	memset(num,-1,sizeof(num));
	memset(depth,-1,sizeof(depth));
	memset(dp,-1,sizeof(dp));
	memset(visit,0,sizeof(visit));
	int aa,bb;
	cin>>n;
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&aa,&bb);
		G[aa].push_back(bb);
		G[bb].push_back(aa);
	}
	//take Node 1 as root
	dfs1(1,0);
	//calculate dp[1] which is the sum of all node's depth
	dp[1]=0;
	for(int i=1;i<=n;i++)
		dp[1]+=depth[i];
	dfs2(1);
}
int main(void)
{
	init();
	for(int i=1;i<=n;i++)
		printf("%lld\n",dp[i]);
	return 0;
}

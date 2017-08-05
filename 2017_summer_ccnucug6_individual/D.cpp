#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<cstring>
#include<climits>
using namespace std;
int n,k,level,cnt,ans;
const int maxn=200000+10;
vector<int> G[maxn];
int max_depth=-1,min_depth=INT_MAX;
int cnt_min=0,cnt_max=0;
bool visit[maxn];
void dfs(int x,int depth)
{
	bool flag=false;
	visit[x]=true;
	for(auto it:G[x])
	{
		if(!visit[it])
		{
			flag=true;
			dfs(it,depth+1);
		}
	}
	if(!flag)
	{
		if(depth==min_depth)
			cnt_min++;
		if(depth<min_depth)
		{
			cnt_min=1;
			min_depth=depth;
		}
		if(depth==max_depth)
			cnt_max++;
		if(depth>max_depth)
		{
			cnt_max=1;
			max_depth=depth;
		}
		//min_depth=min(min_depth,depth);
		//max_depth=max(max_depth,depth);
	}
}
int main(void)
{
	cin>>n>>k;
	for(int i=1;i<=k;i++)
	{
		G[n].push_back(i);
		G[i].push_back(n);
	}
	for(int i=1;i<n;i++)
	{
		if(i+k>=n)
			break;
		G[i].push_back(i+k);
		G[i+k].push_back(i);
	}
	memset(visit,0,sizeof(visit));
	dfs(n,0);
	if(cnt_max>1)
		ans=2*max_depth;
	else
		ans=max_depth+max_depth-1;
	cout<<ans<<endl;
	for(int i=1;i<=k;i++)
		printf("%d %d\n",n,i);
	for(int i=1;i<n;i++)
	{
		if(i+k>=n)
			break;
		printf("%d %d\n",i,i+k);
	}
	return 0;
}

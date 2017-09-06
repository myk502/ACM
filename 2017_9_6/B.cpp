#include<cstdio>
#include<iostream>
#include<cmath>
#include<climits>
#include<algorithm>
#include<cstring>
#include<string>
#include<stack>
#include<vector>
#include<map>
using namespace std;
const int maxn=100000+10;
map<int,int> id;
int temp[maxn],a[maxn],n;
int cnt,dfn[maxn],sccno[maxn],low[maxn],scc_cnt;
long long cnt_inversion=0;
vector<int> G[maxn];
stack<int> s;
void merge(int l,int m,int r)
{
	int i=l;
	int j=m+1;
	int k=l;
	while(i<=m && j<=r)
	{
		if(a[i]>a[j])
		{
			temp[k++]=a[j++];
			cnt_inversion+= m - i + 1;
		}
		else
			temp[k++]=a[i++];
	}
	while(i<=m)
		temp[k++]=a[i++];
	while(j<=r)
		temp[k++]=a[j++];
	for(int i=l;i<=r;i++)
		a[i]=temp[i];
}

void merge_sort(int l,int r)
{
	if(l < r)
	{
		int m = (l + r) >> 1;
		merge_sort(l,m);
		merge_sort(m+1,r);
		merge(l,m,r);
	}
}

void dfs(int x)
{
	dfn[x]=low[x]=++cnt;
	s.push(x);
	for(auto to:G[x])
	{
		if(!dfn[to])
		{
			dfs(to);
			low[x]=min(low[x],low[to]);
		}
		else if(!sccno[to])
			low[x]=min(low[x],dfn[to]);
	}
	if(dfn[x]==low[x])
	{
		scc_cnt++;
		while(s.top()!=x)
		{
			sccno[s.top()]=scc_cnt;
			s.pop();
		}
		s.pop();
		sccno[x]=scc_cnt;
	}
}

int main(void)
{
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		cnt_inversion=0;
		id.clear();
		for(int i=0;i<maxn;i++)
			G[i].clear();
		while(!s.empty())
			s.pop();
		for(int i=0;i<n;i++)
		{
			id[a[i]]=i;
		}
		merge_sort(0,n-1);
		for(int i=0;i<n;i++)
		{
			int val=a[i];
			int old_id=id[val];
			int new_id=i;
			G[old_id].push_back(new_id);
		}
		cnt=scc_cnt=0;
		for(int i=0;i<n;i++)
			if(!dfn[i])
				dfs(i);
		printf("%d\n%lld\n",n-scc_cnt,cnt_inversion);
	}
	return 0;
}

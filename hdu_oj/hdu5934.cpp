#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<stack>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;
const int maxn=1000+10;
int x[maxn],y[maxn],r[maxn],c[maxn],n;
int a[maxn][maxn],ans[maxn];
int cnt,scc_cnt,dfn[maxn],low[maxn],sccno[maxn];
bool flag[maxn];
stack<int> s;
bool judge(int i,int j)
{
	long long ll,rr;
	ll=(long long)(x[i]-x[j])*(long long)(x[i]-x[j]);
	ll+=(long long)(y[i]-y[j])*(long long)(y[i]-y[j]);
	rr=(long long)r[i]*(long long)r[i];
	return ll<=rr;
}

void dfs(int x)
{
	dfn[x]=low[x]=++cnt;
	s.push(x);
	for(int to=0;to<n;to++)
	{
		if(a[x][to]==0)
			continue;
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
		int minn=c[x];
		while(s.top()!=x)
		{
			sccno[s.top()]=scc_cnt;
			minn=min(minn,c[s.top()]);
			s.pop();
		}
		s.pop();
		sccno[x]=scc_cnt;
		ans[scc_cnt]=minn;
	}

}

int main(void)
{
	int T;
	scanf("%d",&T);
	for(int ii=1;ii<=T;ii++)
	{
		memset(a,0,sizeof(a));
		memset(dfn,0,sizeof(dfn));
		memset(low,0,sizeof(low));
		memset(sccno,0,sizeof(sccno));
		cnt=scc_cnt=0;
		while(!s.empty())
			s.pop();
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%d%d%d%d",&x[i],&y[i],&r[i],&c[i]);
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(judge(i,j))
					a[i][j]=1;
			}
		}
		for(int i=0;i<n;i++)
		{
			if(!dfn[i])
				dfs(i);
		}
		int ANS=0;
		memset(flag,0,sizeof(flag));
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
			{
				if(a[i][j]==1)
				{
					if(sccno[i]!=sccno[j])
						flag[sccno[j]]=true;
				}
			}
		for(int i=1;i<=scc_cnt;i++)
			if(!flag[i])
				ANS+=ans[i];
		printf("Case #%d: %d\n",ii,ANS);

	}
	return 0;
}

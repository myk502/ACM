#include<cstdio>
#include<vector>
#include<cstring>
#include<string>
#include<stack>
#include<iostream>
#include<cmath>
using namespace std;
const int maxn=50000+10;
int n,m,head[10000+10],cnt,sccno[10000+10],cnt_scc,cnt_dfs;
int dfn[10000+10],low[10000+10],num[10000+10];
stack<int> s;
struct Edge
{
	int to,next;
	Edge(int to=-1,int next=-1):to(to),next(next)
	{

	}
};
Edge e[maxn];
void add_edge(int from,int to)
{
	e[cnt].to=to;
	e[cnt].next=head[from];
	head[from]=cnt++;
}

void dfs(int x)
{
	dfn[x]=low[x]=++cnt_dfs;
	s.push(x);
	for(int j=head[x];j!=-1;j=e[j].next)
	{
		int to=e[j].to;
		if(!dfn[to])
		{
			dfs(to);
			low[x]=min(low[x],low[to]);
		}
		else if(!sccno[to])
			low[x]=min(low[x],dfn[to]);
	}
	if(low[x]==dfn[x])
	{
		int tempcnt=0;
		cnt_scc++;
		while(s.top()!=x)
		{
			sccno[s.top()]=cnt_scc;
			tempcnt++;
			s.pop();
		}
		s.pop();
		sccno[x]=cnt_scc;
		num[cnt_scc]=tempcnt+1;
	}
}

int main(void)
{
	int aa,bb;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		memset(head,-1,sizeof(head));
		memset(sccno,0,sizeof(sccno));
		memset(dfn,0,sizeof(dfn));
		memset(low,0,sizeof(low));
		memset(num,0,sizeof(num));
		while(!s.empty())
			s.pop();
		cnt_scc=cnt_dfs=cnt=0;
		for(int ii=0;ii<m;ii++)
		{
			scanf("%d%d",&aa,&bb);
			add_edge(aa,bb);
		}
		for(int i=1;i<=n;i++)
		{
			if(!dfn[i])
				dfs(i);
		}
		int ans=0;
		for(int i=0;i<n;i++)
		{
			if(num[i]>2)
				ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}

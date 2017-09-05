#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
#include<stack>
#include<vector>
using namespace std;
const int maxn=5000+10;
int n,m;
stack<int> s;
vector<int> G[maxn];
vector<int> ANS;
int low[maxn],dfn[maxn],scccno[maxn],cnt,scc_cnt,outdegree[maxn];
void init(void)
{
	while(!s.empty())
		s.pop();
	for(int i=0;i<maxn;i++)
	{
		G[i].clear();
	}
	ANS.clear();
	memset(low,0,sizeof(low));
	memset(dfn,0,sizeof(dfn));
	memset(outdegree,0,sizeof(outdegree));
	memset(scccno,0,sizeof(scccno));
	scc_cnt=cnt=0;
}

void dfs(int x)
{
	dfn[x]=low[x]=++cnt;
	s.push(x);
	for(int j=0;j<G[x].size();j++)
	{
		int to=G[x][j];
		if(!dfn[to])
		{
			dfs(to);
			low[x]=min(low[x],low[to]);
		}
		else if(!scccno[to])
			low[x]=min(low[x],low[to]);
	}
	if(dfn[x]==low[x])
	{
		scc_cnt++;
		while(s.top()!=x)
		{
			scccno[s.top()]=scc_cnt;
			s.pop();
		}
		s.pop();
		scccno[x]=scc_cnt;
	}
}

int main(void)
{
	int aa,bb;
	while(scanf("%d",&n)!=EOF)
	{
		init();
		if(n==0)
			break;
		scanf("%d",&m);
		for(int i=0;i<m;i++)
		{
			scanf("%d%d",&aa,&bb);
			G[aa].push_back(bb);
		}
		for(int i=1;i<=n;i++)
			if(!dfn[i])
				dfs(i);
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<G[i].size();j++)
			{
				int to=G[i][j];
				if(scccno[i]!=scccno[to])
					outdegree[scccno[i]]++;
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(outdegree[scccno[i]]==0)
				ANS.push_back(i);
		}
		sort(ANS.begin(),ANS.end());
		printf("%d",ANS[0]);
		for(int i=1;i<ANS.size();i++)
			printf(" %d",ANS[i]);
		printf("\n");

	}
	return 0;
}

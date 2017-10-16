#include<bits/stdc++.h>
using namespace std;
const int maxn = 2000 + 10;
int low[maxn],dfn[maxn],scc_cnt,dfn_cnt,sccno[maxn];
stack<int> s;
int n,a[2010][2010];
void dfs(int u)
{
	s.push(u);
	dfn[u] = low[u] = ++dfn_cnt;
	for(int i = 1; i <= n;i++)
	{
		if(a[u][i] == 0)
			continue;
		if(!dfn[i])
		{
			dfs(i);
			low[u] = min(low[u],low[i]);
		}
		else if(!sccno[i])
			low[u] = min(low[u],dfn[i]);
	}
	if(low[u] == dfn[u])
	{
		scc_cnt++;
		while(true)
		{
			int temp = s.top();
			s.pop();
			sccno[temp] = scc_cnt;
			if(temp == u)
				break;
		}
	}
}
int main(void)
{
	scanf("%d",&n);
	for(int i = 1; i <= n;i++)
		for(int j = 1;j <= n; j++)
			scanf("%d",&a[i][j]);
	memset(low,0,sizeof(low));
	memset(dfn,0,sizeof(dfn));
	memset(sccno,0,sizeof(sccno));
	scc_cnt = dfn_cnt = 0;
	while(!s.empty())
		s.pop();
	for(int i = 1; i <= n;i++)
		if(!dfn[i])
			dfs(i);
	if(scc_cnt == 1)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}

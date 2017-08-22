#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> G[110];
int n,m;
int c[110],topo[110];
int cnt;
bool flag;

bool dfs(int x)
{
	c[x]=-1;
	for(auto it:G[x])
	{
		if(c[it]==-1)
			return false;
		if((!c[it]) && !dfs(it))
			return false;
	}
	c[x]=1;
	topo[--cnt]=x;
	return true;
}

int main(void)
{
	int aa,bb;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		if(n==0)
			break;
		for(int i=1;i<=n;i++)
			G[i].clear();
		for(int i=0;i<m;i++)
		{
			scanf("%d%d",&aa,&bb);
			G[aa].push_back(bb);
		}
		cnt=n;
		memset(c,0,sizeof(c));
		for(int i=1;i<=n;i++)
		{
			if(!c[i])
				if(!dfs(i))
					flag=false;
		}
		for(int i=0;i<n;i++)
			printf("%d ",topo[i]);
		printf("\n");
	}
	return 0;
}

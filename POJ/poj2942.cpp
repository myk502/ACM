#include<cstdio>
#include<stack>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn = 1000 + 10;
int pre[maxn],iscut[maxn],bccno[maxn],color[maxn],dfs_clock,bcc_cnt;
vector<int> bcc[maxn];
int a[1010][1010],n,m;
bool ans[maxn];
struct Edge
{
	int from,to;
	Edge(int from = -1,int to = -1):from(from),to(to)
	{

	}
};
stack<Edge> S;

int dfs(int u ,int fa)
{
	int lowu = pre[u] = ++dfs_clock;
	int child = 0;
	for(int v = 1; v <= n;v++)
	{
		if(a[u][v] == 0)
			continue;
		Edge e = Edge(u,v);
		if(!pre[v])
		{
			S.push(e);
			child++;
			int lowv = dfs(v,u);
			lowu = min(lowu,lowv);
			if(lowv >= pre[u])
			{
				iscut[u] = true;
				bcc_cnt++;
				bcc[bcc_cnt].clear();
				while(1)
				{
					Edge x = S.top();
					S.pop();
					if(bccno[x.from] != bcc_cnt)
					{
						bccno[x.from] = bcc_cnt;
						bcc[bcc_cnt].push_back(x.from);
					}
					if(bccno[x.to] != bcc_cnt)
					{
						bccno[x.to] = bcc_cnt;
						bcc[bcc_cnt].push_back(x.to);
					}
					if((x.from == u) && (x.to == v))
						break;
				}
			}
		}
		else if(v != fa && pre[v] < pre[u])
		{
			S.push(e);
			lowu = min(lowu,pre[v]);
		}
	}
	if(fa < 0 && child == 1)
		iscut[u] = 0;
	return lowu;
}


void find_bcc(int n)
{
	memset(pre,0,sizeof(pre));
	memset(iscut,0,sizeof(iscut));
	memset(bccno,0,sizeof(bccno));
	dfs_clock = bcc_cnt = 0;
	for(int i = 1;i <= n;i++)
		if(!pre[i])
			dfs(i,-1);
}

bool bipartiate(int u,int fa)
{
	for(int v = 1; v <= n;v++)
	{
		if(a[u][v] == 0 || bccno[u] != bccno[v] )
			continue;
		if(!color[v])
		{
			color[v] = 3 - color[u];
			if(!bipartiate(v,u))
				return false;
		}
		else if(color[v] == color[u])
		{
			return false;
		}
	}
	return true;
}

int main(void)
{
	int aa,bb;
	while(scanf("%d%d",&n,&m) != EOF)
	{
		if(n == 0 && m == 0)
			break;
		memset(ans,0,sizeof(ans));
		for(int i = 1; i <= n;i++)
			for(int j = 1;j <= n;j++)
			{
				if(i != j)
					a[i][j] = 1;
				else
					a[i][j] = 0;
			}
		for(int i = 0 ; i < m; i++)
		{
			scanf("%d%d",&aa,&bb);
			a[aa][bb] = a[bb][aa] = 0;
		}
		/*
		for(int i = 1; i <= n;i++)
			for(int j = 1;j <= n;j++)
				printf("a[%d][%d]= %d\n",i,j,a[i][j]);
		*/
		find_bcc(n);
		for(int i = 1; i <= bcc_cnt;i++)
		{
			int start_point = bcc[i][0];
			for(int j = 0; j < bcc[i].size();j++)
			{
				int it = bcc[i][j];
				color[it] = 0;
				bccno[it] = i;
			}
			color[start_point] = 1;
			if(!bipartiate(start_point,-1) )
				for(int j = 0; j < bcc[i].size();j++)
				{
					int it = bcc[i][j];
					ans[it] = true;
				}
		}
		int ans_cnt = 0;
		for(int i = 1; i <= n;i++)
			ans_cnt += (!ans[i]);
		printf("%d\n",ans_cnt);
	}
	return 0;
}

#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<map>
#include<string>
#include<algorithm>
#include<stack>
#include<cmath>
using namespace std;
const int maxn = 100000 + 10;
struct Edge
{
	int from,to;
	Edge(int from = -1,int to = -1):from(from),to(to)
	{
	}
};
map<int,int> a;
vector<Edge> edges;
int m,n;
int pre[maxn],iscut[maxn],bccno[maxn],dfs_clock,bcc_cnt;
vector<int> bcc[maxn],G[maxn];
stack<Edge> S;
long long ans;
int dfs(int u,int fa)
{
	int lowu = pre[u] = ++dfs_clock;
	int child = 0;
	for(int i = 0; i < (int)G[u].size(); i++)
	{
		int v= G[u][i];
		Edge e = (Edge){u,v};
		if(!pre[v])
		{
			S.push(e);
			child++;
			int lowv = dfs(v,u);
			lowu = min(lowu, lowv);
			if(lowv >= pre[u])
			{
				iscut[u] = true;
				bcc_cnt++;
				bcc[bcc_cnt].clear();
				while(true)
				{
					Edge x = S.top();
					S.pop();
					if(bccno[x.from] != bcc_cnt)
					{
						bcc[bcc_cnt].push_back(x.from);
						bccno[x.from] = bcc_cnt;
					}
					if(bccno[x.to] != bcc_cnt)
					{
						bcc[bcc_cnt].push_back(x.to);
						bccno[x.to] = bcc_cnt;
					}
					if(x.from == u && x.to == v)
						break;
					}
			}
		}
		else if(pre[v] < pre[u] && v != fa)
		{
			S.push(e);
			lowu = min(lowu, pre[v]);
		}
	}
	if(fa < 0 && child == 1)
		iscut[u] = 0;
	return lowu;
}

void find_bcc(int n)
{
	memset(pre, 0, sizeof(pre));
	memset(iscut, 0, sizeof(iscut));
	memset(bccno, 0, sizeof(bccno));
	dfs_clock = bcc_cnt = 0;
	for(int i = 1; i <= n;i++)
		if(!pre[i])
			dfs(i, -1);
}

int main(void)
{
	int T = 0,s,t,anss;
	while(scanf("%d",&m) != EOF)
	{
		if( m == 0 )
			break;
		T++;
		printf("Case %d: ",T);
		for(int i = 0 ; i < maxn;i++)
			G[i].clear();
		edges.clear();
		a.clear();
		anss = n = 0;
		ans = 1;
		for(int i = 0 ; i < m ;i++)
		{
			scanf("%d%d",&s,&t);
			edges.push_back(Edge(s,t));
			if(a[s] == 0)
				a[s] = ++n;
			if(a[t] == 0)
				a[t] = ++n;
		}
		for(int i = 0 ; i < m;i++)
		{
			s = edges[i].from;
			t = edges[i].to;
			G[a[s]].push_back(a[t]);
			G[a[t]].push_back(a[s]);
		}
		find_bcc(n);
		if(bcc_cnt == 1)
		{
			if( n % 2 == 0)
				ans = (n / 2) * (n - 1);
			else
				 ans = ((n - 1) / 2) * n;
			printf("%d %lld\n",2,ans);
			continue;
		}
		for(int i = 1; i <= bcc_cnt;i++)
		{
			int num_cut = 0;
			for(auto it:bcc[i])
				if(iscut[it])
					num_cut++;
			if(num_cut == 1)
			{
				anss++;
				ans *= bcc[i].size() - 1;
			}
		}
		printf("%d %lld\n",anss,ans);
	}
	return 0;
}

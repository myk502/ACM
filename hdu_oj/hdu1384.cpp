#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn = 50000 + 10;
int n,a[maxn],b[maxn],c[maxn];
typedef pair<int,int> pii;
vector<pii> G[maxn+10];
int d[maxn + 10];
queue<int> q;
bool inque[maxn + 10];
const int INF = maxn << 2;
void SPFA(int s)
{
	for(int i = 0;i < maxn + 10;i++)
		d[i] = INF;
	d[s] = 0;
	q.push(s);
	inque[s] = true;
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		inque[u] = false;
		for(auto it:G[u])
		{
			int to = it.first;
			int cost = it.second;
			if(d[u] + cost < d[to])
			{
				d[to] = d[u] + cost;
				if(!inque[to])
				{
					q.push(to);
					inque[to] = true;
				}
			}
		}
	}
}


int main(void)
{
	while(scanf("%d",&n)!=EOF)
	{
		for(int i = 1;i <= n;i++)
			scanf("%d%d%d",&a[i],&b[i],&c[i]);
		for(int i = 0;i < maxn + 10;i++)
			G[i].clear();
		for(int i = 1;i <= n;i++)
		{
			int to = a[i];
			int from = b[i] + 1;
			int cost = -c[i];
			G[from].push_back(make_pair(to,cost));
		}
		for(int i = 0; i <= maxn;i++)
		{
			G[i+1].push_back(make_pair(i , 0));
			G[i].push_back(make_pair(i + 1 , 1));
		}
		SPFA(maxn + 1);
		printf("%d\n",-d[0]);
	}
	return 0;
}

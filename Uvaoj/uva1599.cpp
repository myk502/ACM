#include<cstdio>
#include<queue>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<cmath>
#include<climits>
#include<algorithm>
using namespace std;
const int maxn=100000+10;
int n,m,d[maxn],ans[maxn];
typedef pair<int,int> pii;
vector<pii> G[maxn];
bool visit[maxn];
queue<int> q;
int main(void)
{
	int a,b,c;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(int i=0;i<maxn;i++)
			G[i].clear();
		for(int i=0;i<m;i++)
		{
			scanf("%d%d%d",&a,&b,&c);
			G[a].push_back(make_pair(b,c));
			G[b].push_back(make_pair(a,c));
		}
		d[n]=0;
		memset(visit,0,sizeof(visit));
		while(!q.empty())
			q.pop();
		q.push(n);
		visit[n]=true;
		while(!q.empty())
		{
			int temp=q.front();
			q.pop();
			if(temp==1)
				break;
			for(auto it:G[temp])
			{
				int next_node=it.first;
				if(!visit[next_node])
				{
					d[next_node]=d[temp]+1;
					q.push(next_node);
					visit[next_node]=true;
				}
			}
		}
		while(!q.empty())
			q.pop();
		for(int i=0;i<maxn;i++)
			ans[i]=INT_MAX;
		memset(visit,0,sizeof(visit));
		visit[1]=true;
		q.push(1);
		while(!q.empty())
		{
			int temp=q.front();
			q.pop();
			int minn=INT_MAX;
			for(auto it:G[temp])
			{
				int to=it.first;
				int cost=it.second;
				if(d[to]!=d[temp]-1)
					continue;
				if(cost<minn)
				{
					minn=cost;
				}
			}
			if(minn>ans[ d[temp] ])
				continue;
			else
			{
				ans[ d[temp] ]=minn;
				for(auto it:G[temp])
				{
					int to=it.first;
					int cost=it.second;
					if(d[to]!=d[temp]-1)
						continue;
					if(visit[to])
						continue;
					if(cost==minn)
					{
						visit[to]=true;
						q.push(to);
					}
				}
			}
		}
		printf("%d\n%d",d[1],ans[d[1]]);
		for(int i=d[1]-1;i>0;i--)
			printf(" %d",ans[i]);
		printf("\n");

		
	}
	return 0;
}

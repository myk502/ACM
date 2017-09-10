#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn=10000+10;
int n,m,indegree[maxn],d[maxn];
typedef pair<int,int> pii;
queue<int> q;
vector<pii> G[maxn];
int main(void)
{
	int T,s,t,l;
	scanf("%d",&T);
	while(T--)
	{
		for(int i=0;i<maxn;i++)
			G[i].clear();
		while(!q.empty())
			q.pop();
		memset(indegree,0,sizeof(indegree));
		memset(d,0,sizeof(d));
		scanf("%d%d",&n,&m);
		for(int i=0;i<m;i++)
		{
			scanf("%d%d%d",&s,&t,&l);
			G[s].push_back(make_pair(t,l));
			indegree[t]++;
		}
		for(int i=1;i<=n;i++)
			if(indegree[i]==0)
				q.push(i);
		while(!q.empty())
		{
			int temp=q.front();
			q.pop();
			for(auto it:G[temp])
			{
				int to=it.first;
				int val=it.second;
				d[to]=max(d[to],d[temp]+val);
				indegree[to]--;
				if(indegree[to]==0)
					q.push(to);
			}
		}
		int ans=-1;
		for(int i=1;i<=n;i++)
			ans=max(ans,d[i]);
		cout<<ans<<endl;
	}
	return 0;
}

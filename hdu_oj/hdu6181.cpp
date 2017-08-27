#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
const long long INF=1e16;
struct Node
{
	int id,flag;
	long long val;
	Node(int id=0,int flag=0,long long val=INF):id(id),flag(flag),val(val)
	{

	}
	bool operator <(const Node& X)const
	{
		return this->val>X.val;
	}
};
struct Edge
{
	int to;
	long long val;
	Edge(int to=-1,long long val=INF):to(to),val(val)
	{

	}
};
int n,m;
const int maxn=100000+10;
vector<Edge> G[100000+10];
bool visit[2][maxn];
long long dis[2][maxn];
priority_queue<Node> pq;
void init(void)
{
	for(int i=0;i<maxn;i++)
		G[i].clear();
	while(!pq.empty())
		pq.pop();
	memset(visit,0,sizeof(visit));
	for(int i=0;i<maxn;i++)
	{
		dis[0][i]=dis[1][i]=INF;
	}
}
int main(void)
{
	int T;
	int aa,bb,ww;
	scanf("%d",&T);
	while(T--)
	{
		init();
		scanf("%d%d",&n,&m);
		for(int i=0;i<m;i++)
		{
			scanf("%d%d%d",&aa,&bb,&ww);
			G[aa].push_back(Edge(bb,(long long)ww));
			G[bb].push_back(Edge(aa,(long long)ww));
		}
		dis[0][1]=0;
		pq.push(Node(1,0,0));
		while(!pq.empty())
		{
			Node TEMP=pq.top();
			pq.pop();
			int id_now=TEMP.id;
			long long dis_now=TEMP.val;
			int flag_now=TEMP.flag;
			visit[flag_now][id_now]=true;
			for(auto it:G[id_now])
			{
				int id_to=it.to;
				long long distance=it.val;
				if( (!visit[0][id_to]) && (dis_now+distance<dis[0][id_to])  )
				{
					dis[1][id_to]=dis[0][id_to];
					dis[0][id_to]=dis_now+distance;
					pq.push(Node(id_to,0,dis[0][id_to]));
				}
				else if((!visit[1][id_to]) && (dis_now+distance<dis[1][id_to]))
				{
					dis[1][id_to]=dis_now+distance;
					pq.push(Node(id_to,1,dis[1][id_to]));
				}
			}
		}
		printf("%lld\n",dis[1][n]);
	}
	return 0;
}

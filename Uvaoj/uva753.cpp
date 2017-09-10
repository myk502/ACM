#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<map>
#include<queue>
#include<climits>
#include<algorithm>
using namespace std;
const int maxn=110;
struct Edge
{
	int from,to,capacity,flow;
	Edge(int from=-1,int to=-1,int capacity=0,int flow=0):from(from),to(to),capacity(capacity),flow(flow)
	{

	}
};
map<string,int> type;
string device_name[maxn];
int a[maxn<<2][maxn<<2],s,t,device_type[maxn],receptacle_type[maxn];
int n,m,k,cnt_type;
void init(void)
{
	type.clear();
	cnt_type=0;
	memset(a,0,sizeof(a));
	for(int i=0;i<4*maxn;i++)
		a[i][i]=1;
}

void floyd(int N)
{
	for(int k=0;k<N;k++)
	{
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++)
			{
				if(a[i][k]&&a[k][j])
					a[i][j]=1;
			}
		}
	}
}

struct EdmondsKarp
{
	int n,m;
	vector<Edge> edges;
	vector<int> G[maxn<<1];
	int a[maxn<<1],p[maxn<<1];

	void init(int n)
	{
		this -> n = n;
		for(int i = 0; i < n; i++)
			G[i].clear();
		edges.clear();
	}
	void add_edge(int from, int to, int cap)
	{
		edges.push_back(Edge(from, to, cap, 0));
		edges.push_back(Edge(to, from, 0, 0));
		m=edges.size();
		G[from].push_back(m-2);
		G[to].push_back(m-1);
	}
	int maxflow(int s,int t)
	{
		int flow=0;
		while(1)
		{
			memset(a,0,sizeof(a));
			queue<int> q;
			q.push(s);
			a[s]=INT_MAX;
			while(!q.empty())
			{
				int temp=q.front();
				q.pop();
				for(auto it:G[temp])
				{
					Edge e=edges[it];
					if(!a[e.to] && e.capacity>e.flow)
					{
						p[e.to]=it;
						a[e.to]=min(a[e.from],e.capacity-e.flow);
						q.push(e.to);
					}
				}
				if(a[t])
					break;
			}
			if(!a[t])
				break;
			for(int u = t; u != s; u=edges[p[u]].from)
			{
				edges[p[u]].flow+=a[t];
				edges[p[u]^1].flow-=a[t];
			}
			flow+=a[t];
		}
		return flow;
	}
};
EdmondsKarp EK;
int main(void)
{
	string input;
	string name;
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	for(int ii=1;ii<=T;ii++)
	{
		if(ii!=1)
			cout<<endl;
		init();
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>input;
			auto it=type.find(input);
			if(it==type.end())
			{
				receptacle_type[i]=cnt_type;
				type.insert(make_pair(input,cnt_type++));
			}
			else
				receptacle_type[i]=it->second;

		}
		cin>>m;
		for(int i=0;i<m;i++)
		{
			cin>>name>>input;
			device_name[i]=name;
			auto it=type.find(input);
			if(it==type.end())
			{
				device_type[i]=cnt_type;
				type.insert(make_pair(input,cnt_type++));
			}
			else
				device_type[i]=it->second;
		}
		cin>>k;
		for(int i=0;i<k;i++)
		{
			cin>>input>>name;
			int id1,id2;
			auto it=type.find(input);
			if(it==type.end())
			{
				id1=cnt_type;
				type.insert(make_pair(input,cnt_type++));
			}
			else
				id1=it->second;
			it=type.find(name);
			if(it==type.end())
			{
				id2=cnt_type;
				type.insert(make_pair(name,cnt_type++));
			}
			else
				id2=it->second;
			a[id1][id2]=1;
		}
		floyd(cnt_type);
		EK.init(n+m+2);
		s=m+n;
		t=m+n+1;
		for(int i=0;i<m;i++)
		{
			for(int j=m;j<m+n;j++)
			{
				int ii=i,jj=j-m;
				int type_device=device_type[ii];
				int type_receptacle=receptacle_type[jj];
				if(a[type_device][type_receptacle])
				{
					EK.add_edge(i,j,1);
				}
			}
		}
		for(int i=0;i<m;i++)
			EK.add_edge(s,i,1);
		for(int j=m;j<m+n;j++)
			EK.add_edge(j,t,1);
		int ans=EK.maxflow(s,t);
		ans=m-ans;
		cout<<ans<<endl;

	}
	return 0;
}

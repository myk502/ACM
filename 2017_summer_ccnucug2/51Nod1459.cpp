#include<cstdio>
#include<iostream>
#include<cstring>
#include<queue>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m,start,endd,score[510];
const int INF=1000000;
int d[510],s[510];
typedef pair<int,int> pii;
bool done[510];
vector<pii> G[510];
struct Path
{
	int distance,score,id;
	Path(int xx,int yy,int zz):distance(xx),score(yy),id(zz)
	{}
	bool operator <(const Path& X)const
	{
		if(this->distance!=X.distance)
			return this->distance>X.distance;
		return this->score<X.score;
	}
};
priority_queue<Path> pq;
int main(void)
{
	int xx,yy,zz;
	ios::sync_with_stdio(false);
	cin>>n>>m>>start>>endd;
	for(int i=0;i<n;i++)
		cin>>score[i];
	for(int i=0;i<m;i++)
	{
		cin>>xx>>yy>>zz;
		G[xx].push_back(make_pair(yy,zz));
		G[yy].push_back(make_pair(xx,zz));
	}
	memset(s,0,sizeof(s));
	memset(done,0,sizeof(done));
	for(int i=0;i<n;i++)
		d[i]=INF;
	d[start]=0;
	s[start]=score[start];
	pq.push(Path(d[start],s[start],start));
	while(!pq.empty())
	{
		int id,dis,sc;
		Path Now=pq.top();
		id=Now.id;
		//dis=Now.distance;
		//sc=Now.score;
		pq.pop();
		if(done[id])
			continue;
		done[id]=true;
		for(auto it:G[id])
		{
			int next_id=it.first,next_dis=it.second;
			if(  (d[id]+next_dis<d[next_id]) ||( (d[id]+next_dis==d[next_id]) && (s[id]+score[next_id]>s[next_id]) )  )
			{
				d[next_id]=d[id]+next_dis;
				s[next_id]=s[id]+score[next_id];
				pq.push(Path(d[next_id],s[next_id],next_id));
			}
		}
		
	}
	cout<<d[endd]<<" "<<s[endd]<<endl;
	return 0;
}

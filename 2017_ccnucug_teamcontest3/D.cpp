#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
const int dx[]={-1,-1,0,1,1,1,0,-1};
const int dy[]={0,1,1,1,0,-1,-1,-1};
struct Point
{
	int x,y;
	Point(int x,int y):x(x),y(y)
	{
		
	}
	bool operator <(const Point& X)const
	{
		if(this->x!=X.x)
			return 
	}
};
int find_ancestor(int x)
{
	int r=x;
	while(father[r]!=r)
		r=father[r];
	int i=x,j;
	while(i!=r)
	{
		j=father[i];
		father[i]=r;
		i=j;
	}
	return r;
}
void add_edge(int x,int y)
{
	int fx=find_ancestor(x),fy=find_ancestor(y);
	if(fx!=fy)
		father[min(fx,fy)]=max(fx,fy);
}
vector<Point> G;
int n,m,k;
int main(void)
{
	int T,xx,yy;
	scanf("%d",&T);
	for(int ii=1;ii<=T;ii++)
	{
		G.clear();
		scanf("%d%d",&n,&m);
		scanf("%d",&k);
		for(int i=0;i<k;i++)
		{
			scanf("%d%d",&xx,&yy);
			G.push_back(Point(xx,yy));
		}
	}
	return 0;
}

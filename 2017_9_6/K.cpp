#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<stack>
#include<set>
using namespace std;
stack<int> ANS;
struct Edge
{
	int from,to;
	Edge(int from=-1,int to=-1):from(from),to(to)
	{

	}
};
const int maxn=100000+10;
int n,m,q,fa[maxn],cnt=0,deleted[maxn];
Edge e[maxn];
bool exist[maxn];
vector<int> G[maxn];
int find_ancestor(int x)
{
	int r=x;
	while(fa[r]!=r)
		r=fa[r];
	int i=x,j;
	while(i!=r)
	{
		j=fa[i];
		fa[i]=r;
		i=j;
	}
	return r;
}

void add_edge(int x,int y)
{
	int fx=find_ancestor(x),fy=find_ancestor(y);
	if(fx!=fy)
	{
		cnt--;
		fa[min(fx,fy)]=max(fx,fy);
	}
}

int main(void)
{
	int aa,bb;
	scanf("%d%d",&n,&m);
	cnt=n;
	for(int i=1;i<=n;i++)
		fa[i]=i;
	for(int i=0;i<m;i++)
	{
		scanf("%d%d",&aa,&bb);
		e[i]=Edge(aa,bb);
		exist[i]=true;
	}
	scanf("%d",&q);
	for(int i=0;i<q;i++)
	{
		scanf("%d",&aa);
		aa--;
		deleted[i]=aa;
		exist[aa]=false;
	}
	for(int i=0;i<m;i++)
		if(exist[i])
			add_edge(e[i].from,e[i].to);
	ANS.push(cnt);
	for(int i=q-1;i>0;i--)
	{
		int id=deleted[i];
		add_edge(e[id].from,e[id].to);
		ANS.push(cnt);
	}
	while(!ANS.empty())
	{
		printf("%d ",ANS.top());
		ANS.pop();
	}
	printf("\n");
	return 0;
}

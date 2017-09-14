#include<vector>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
#define lson l , m ,rt << 1
#define rson m + 1 , r , rt << 1 | 1
const int maxn=40000+10;
struct Poster
{
	int lend,rend;
	Poster(int aa = -1,int bb = -1):lend(aa),rend(bb)
	{

	}
};
Poster a[maxn],b[maxn];
typedef pair<int,int> pii;
vector<pii> G;
int n,tree[maxn << 2];
bool exist[maxn];
void Pushdown(int rt)
{
	if(tree[rt]==0)
		return ;
	tree[rt << 1] = tree[rt << 1 | 1] = tree[rt];
	tree[rt]=0;
}

void update(int val , int L , int R , int l , int r , int rt)
{
	if(L <= l && R >= r)
	{
		tree[rt] = val;
		return ;
	}
	int m = (l + r) >> 1;
	Pushdown(rt);
	if(L <= m)
		update(val,L,R,lson);
	if(R > m)
		update(val,L,R,rson);

}
void query(int l,int r,int rt)
{
	if(tree[rt])
	{
		exist[tree[rt]]=true;
		return ;
	}
	int m = (l + r) >> 1;
	if(l == r)
		return ;
	query(lson);
	query(rson);
}



int main(void)
{
	int T,aa,bb;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		G.clear();
		for(int i=0;i<n;i++)
		{
			scanf("%d%d",&aa,&bb);
			a[i]=Poster(aa,bb);
			G.push_back(make_pair( aa , i << 1 ));
			G.push_back(make_pair( bb , i << 1 | 1 ));
		}
		sort(G.begin(),G.end());
		vector<pii>::iterator it;
		int N = G.size();
		for(int i = 1; i < N; i++)
		{
			if(G[i].first - G[i-1].first > 1)
				G.push_back(make_pair(G[i-1].first+1,-1));
		}
		sort(G.begin(),G.end());
		int pre=-1,cnt=0;
		for( it = G.begin() ; it != G.end() ; it++)
		{
			int val = it->first, idx = it->second;
			if(val != pre)
			{
				pre = val;
				cnt++;
			}
			if(idx == -1)
				continue;
			if(idx & 1)
				b[idx >> 1].rend = cnt;
			else
				b[idx >> 1].lend = cnt;
			
		}
		memset(tree,0,sizeof(tree));
		for(int i = 0; i < n; i++)
		{
			update(i + 1,b[i].lend,b[i].rend,1,maxn,1);
		}
		int ans = 0;
		memset(exist,0,sizeof(exist));
		query(1,maxn,1);
		for(int i = 1; i <= n; i++)
		{
			ans += exist[i];
		}
		printf("%d\n",ans);
	}
	return 0;
}

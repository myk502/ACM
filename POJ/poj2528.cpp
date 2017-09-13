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
const int maxn=20000+10;
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
int n,tree[maxn << 2],lazy[maxn << 2];

void PushUp(int rt)
{
	if(tree[ rt << 1 ] == tree[ rt << 1 | 1])
		tree[rt] = tree[ rt << 1 ];
	else
		tree[rt]=-1;
}


void build(int l , int r, int rt)
{
	if(l == r)
	{
		tree[rt] = 0;
		return ;
	}
	build(lson);
	build(rson);
	PushUp(rt);
}

void update(int val , int L , int R , int l , int r , int rt)
{
	if(L <= l && R >= r && tree[rt] == 0)
	{
		lazy[rt] = val;
		tree[rt] = val;
		return ;
	}

}

int cmp(pii X , pii Y)
{
	if(X.first!=Y.first)
		return X.first < Y.first;

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
		sort(G.begin(),G.end(),cmp);
		vector<pii>::iterator it;
		int pre=-1,cnt=0;
		bool flag=false;
		for( it = G.begin() ; it != G.end() ; it++)
		{
			int val = it->first, idx = it->second;
			if(val == pre)
			{
				if(flag)
					cnt++;
			}
			if(val != pre)
			{
				pre = val;
				cnt++;
			}
			if(idx & 1)
				b[it - G.begin()].rend = cnt;
			else
				b[it - G.begin()].lend = cnt;
			
		}
		build(1 , maxn , 1);

	}
	return 0;
}

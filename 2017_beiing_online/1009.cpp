#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<climits>
#include<cmath>
#include<algorithm>
using namespace std;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
const int maxn = 600000;
int n,k;
int maxx[maxn],minn[maxn];
void PushUp(int);
void build(int l,int r,int rt)
{
	int m = (l + r)>>1;
	if(l == r)
	{
		scanf("%d",&maxx[rt]);
		minn[rt] = maxx[rt];
		return ;
	}
	build(lson);
	build(rson);
	PushUp(rt);
	
}
void PushUp(int rt)
{
	maxx[rt] = max(maxx[rt<<1],maxx[rt<<1|1]);
	minn[rt] = min(minn[rt<<1],minn[rt<<1|1]);
}

void update(int pos,int val,int l,int r,int rt)
{
	int m = (l + r)>>1;
	if(l == r)
	{
		minn[rt] = val;
		maxx[rt] = val;
		return ;
	}
	if(pos <= m)
		update(pos,val,lson);
	else
		update(pos,val,rson);
	PushUp(rt);
}
int query(int q,int L,int R,int l,int r,int rt)
{
	if(L<=l && r<=R)
	{
		if(q == 0)
			return minn[rt];
		else
			return maxx[rt];
	}
	int m = (l + r)>>1,ans;
	if(q==0)
		ans = INT_MAX;
	else
		ans = INT_MIN;
	if(L <= m)
	{
		if(q==0)
			ans = min(ans,query(q,L,R,lson));
		else
			ans = max(ans,query(q,L,R,lson));
	}
	if(R > m)
	{
		if(q==0)
			ans = min(ans,query(q,L,R,rson));
		else
			ans = max(ans,query(q,L,R,rson));
	}
	return ans;
}
int main(void)
{
	int T,q,aa,bb,order;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&k);
		n = 1 << k;
		build(1,n,1);
		scanf("%d",&q);
		while(q--)
		{
			scanf("%d%d%d",&order,&aa,&bb);
			if(order == 1)
			{
				aa++;
				bb++;
				long long xiao = query(0,aa,bb,1,n,1);
				long long da = query(1,aa,bb,1,n,1);
				long long ans = xiao * xiao;
				ans = min(ans,xiao * da);
				ans = min(ans,da * da);
				printf("%lld\n",ans);
			}
			else
				update(aa+1,bb,1,n,1);
		}
	}
	return 0;
}

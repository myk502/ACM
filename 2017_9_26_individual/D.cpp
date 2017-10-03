#include<bits/stdc++.h>
using namespace std;
const int maxn = 1000000 + 10;
int n,k;
struct Interval
{
	int lend,rend;
	Interval(long long ll= -1,int rr = -1)
	{
		lend = ll;
		rend = rr;
	}
};
vector<Interval> ANS;
Interval b[maxn];
int a[maxn],sum[maxn],bb[maxn];
struct Discrete
{
	int id,val;
	Discrete(int x = -1,int y = -1):id(x),val(y)
	{
	}
	bool operator < (const Discrete &X)const
	{
		return this -> val < X.val;
	}
};
vector<Discrete> cache;
int main(void)
{
	int ll,rr,idd;
	scanf("%d%d",&n,&k);
	for(int i = 0 ; i < n;i++)
	{
		scanf("%d%d",&ll,&rr);
		b[i] = Interval(ll,rr);
		cache.push_back(Discrete(i << 1,ll));
		cache.push_back(Discrete(i << 1 | 1,rr + 1));
	}
	memset(a,0,sizeof(a));
	sort(cache.begin(),cache.end());
	idd = 0;
	int lastval = -1;
	for(auto it:cache)
	{
		int val = it.val;
		if(val != lastval)
		{
			idd++;
			lastval = val;
			bb[idd] = val;
			printf("bb[%d] =%d\n",idd,val);
		}
		if(it.id & 1)//right end, -1
			a[idd]--;
		else
			a[idd]++; 

	}
	sum[0] = 0;
	for(int i = 1; i < idd + 1; i++)
	{
		sum[i] = sum[i-1] + a[i];
		printf("sum[%d] = %d\n",i,sum[i]);
	}
	ll = rr = -1;
	for(int i = 1; i < maxn;i++)
	{
		if(sum[i] >= k)
		{
			if(ll == -1)
				ll = rr = i;
			else
				rr = i;
		}
		else
		{
			if(ll != -1 && rr != -1)
			{
				ANS.push_back(Interval(ll,rr));
				ll = rr = -1;
			}
		}
	}
	cout<<ANS.size()<<endl;
	for(auto it :ANS)
	{
		int lid = it.lend;
		int rid = it.rend;
		printf("%d %d\n",bb[lid],bb[rid]);
	}
	return 0;
}

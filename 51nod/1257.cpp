#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<vector>
#include<queue>
#include<algorithm>
#include<stack>
using namespace std;
const int maxn = 50000 + 10;
int w[maxn],p[maxn],n,k;
struct Node
{
	double val;
	int id;
	Node(double val = 0,int id = 0):val(val),id(id)
	{
	}
	bool operator < (const Node& X)const
	{
		return this -> val > X.val;
	}
};
Node a[maxn];
double solve(double x)
{
	double ans = 0;
	for(int i = 0 ; i < n; i++)
	{
		a[i].val = p[i] - x * w[i];
		a[i].id = i;
	}
	sort(a,a+n);
	for(int i = 0 ; i < k; i++)
		ans += a[i].val;
	return ans;
}

long long gcd(long long x,long long y)
{
	if(y == 0LL)
		return x;
	return gcd(y,x%y);
}

int main(void)
{
	double ll,rr,mid;
	scanf("%d%d",&n,&k);
	for(int i = 0; i < n; i++)
		scanf("%d%d",&w[i],&p[i]);
	ll = rr = (double)p[0] / (double)w[0];	
	for(int i = 1; i < n; i++)
	{
		double temp = (double)p[i] / (double)w[i];
		ll = min(ll,temp);
		rr = max(rr,temp);
	}
	while(rr - ll > 1e-6)
	{
		mid = (ll + rr) / 2;
		if(solve(mid) > 0)
			ll = mid;
		else
			rr = mid;
	}
	long long up,down;
	up = down = 0;
	for(int i = 0; i < k; i++)
	{
		int id = a[i].id;
		up += p[id];
		down += w[id];
	}
	long long frac = gcd(up,down);
	cout<<up/frac<<"/"<<down/frac<<endl;
	return 0;
}

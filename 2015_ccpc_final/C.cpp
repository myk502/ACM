#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const long long Mod = 1000000000 + 7;
long long dp[1010][1010];
int a[1010], b[1010];
long long bits[1010];
int n, m, cnt;
struct discrete
{
	int id,val;
	bool operator < (const discrete& x)const
	{
		return (this -> val < x.val);
	}
};
discrete dis[1010];
void init(void)
{
	for(int i = 1; i <= n; i++)
	{
		dis[i].id = i;
		dis[i].val = a[i];
	}
	sort(dis + 1, dis + n + 1);
	cnt = 0;
	int oldval = -1;
	for(int i = 1; i <= n; i++)
	{
		if(dis[i].val != oldval)
		{
			b[dis[i].id] = ++cnt;
			oldval = dis[i].val;
		}
		else
			b[dis[i].id] = cnt;
	}
}
int lowbit(int x)
{
	return x & (-x);
}
void update(int i, long long x)
{
	//printf(" i = %d, n = %d\n", i, n);
	while(i <= cnt)
	{
		bits[i] = (bits[i] + x) % Mod;
		i += lowbit(i);
	}
}
long long query(int i)
{
	long long ret = 0;
	while(i > 0)
	{
		ret += bits[i];
		ret %= Mod;
		i -= lowbit(i);
	}
	return ret;
}
int main(void)
{
	int t;
	scanf("%d", &t);
	for(int ii = 1; ii <= t; ii++)
	{
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		init();
		for(int i = 0; i <= n + 5; i++)
			for(int j = 0; j <= m + 5; j++)
				dp[i][j] = 0;
		for(int i = 1; i <= n; i++)
			dp[i][1] = 1;
		for(int j = 2; j <= m; j++)
		{
			for(int kk = 0; kk <= cnt; kk++)
				bits[kk] = 0;
			for(int i = j; i <= n; i++)
			{
				update(b[i - 1], dp[i - 1][j - 1]);
				dp[i][j] = query(b[i] - 1);
			}
		}
		long long ans = 0;
		for(int i = 1; i <= n; i++)
		{
			ans = (ans + dp[i][m] ) % Mod;
		}
		printf("Case #%d: %lld\n", ii, ans);
	}
	return 0;
}

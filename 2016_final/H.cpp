#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
const long long Mod = 1e9 + 7;
int n, m, k;
long long cal_mod(long long x, long long n)
{
	long long ans = 1;
	while(n)
	{
		if(n & 1LL)
			ans = (ans * x) % Mod;
		x = (x * x) % Mod;
		n >>= 1;
	}
	return ans;
}
int main(void)
{
	int T;
	scanf("%d", &T);
	for(int ii = 1; ii <= T; ii++)
	{
		scanf("%d%d%d", &n, &m, &k);
		long long temp = cal_mod(k, (n - 1) * (m - 1));
		long long ans = 0;
		for(int i = 2; i <= k; i++)
		{
			long long tmp = cal_mod(i - 1, n + m - 2);
			tmp = (tmp * temp) % Mod;
			ans = (ans + tmp) % Mod;
		}
		ans *= n * m;
		ans %= Mod;
		ans += cal_mod(k, n * m);
		ans %= Mod;
		printf("Case #%d: %lld\n",ii,ans);
	}
	return 0;
}

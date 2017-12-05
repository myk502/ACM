#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn = 100 + 10;
int n;
double a[maxn],b[maxn],w[maxn];
int main(void)
{
	int T;
	int ANS;
	scanf("%d", &T);
	for(int ii = 1; ii <= T; ii++)
	{
		scanf("%d", &n);
		for(int i = 1; i <= n; i++)
		{
			scanf("%lf:%lf",&a[i],&b[i]);
			w[i] = a[i] / (a[i] + b[i]);
		}
		sort(w + 1, w + n + 1);
		int ans = 0;
		double sum = 0;
		while(1 - sum > 0.001 && ans < n)
		{
			ans++;
			sum += w[ans];
		}
		if(1 - sum > 0.001)
			ANS = ans;
		else
			ANS = ans - 1;
		printf("Case #%d: %d\n",ii, ANS);
	}
	return 0;
}

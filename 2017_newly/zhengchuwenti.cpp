#include<bits/stdc++.h>
using namespace std;
int gcd(int x, int y)
{
	if(y == 0)
		return x;
	return gcd(y, x % y);
}
const int maxn = 1000000 + 10;
int n;
int a[maxn];
int main(void)
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		for(int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		a[2] /= gcd(a[1], a[2]);
		int temp = a[2];
		for(int i = 3; i <= n; i++)
			temp /= gcd(temp, a[i]);
		if(temp == 1)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}

#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
int gcd(int x,int y)
{
	if(y == 0)
		return x;
	else
		return gcd(y, x % y);
}
int main(void)
{
	int T;
	int n, a, b, x;
	scanf("%d",&T);
	for(int ii = 1; ii <= T; ii++)
	{
		scanf("%d%d%d",&n, &a, &b);
		x = gcd(a, b);
		x = n / x;
		printf("Case #%d: ",ii);
		if(x % 2 == 0)
			printf("Iaka\n");
		else
			printf("Yuwgna\n");
	}

	return 0;
}

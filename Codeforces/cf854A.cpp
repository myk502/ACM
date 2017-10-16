#include<bits/stdc++.h>
using namespace std;
int gcd(int x,int y)
{
	if(y == 0)
		return x;
	else
		return gcd(y,x%y);
}
int main(void)
{
	int n,a,b,aa,bb;
	double ans = -1;
	scanf("%d",&n);
	for(int i = 1; i < n;i++)
	{
		a = i;
		b = n - a;
		if(a >= b)
			continue;
		if(gcd(a,b) != 1)
			continue;
		double temp = (double) a / (double) b;
		if(temp > ans)
		{
			aa = a;
			bb = b;
			ans = temp;
		}
	}
	printf("%d %d\n",aa,bb);
	return 0;
}

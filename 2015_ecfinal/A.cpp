#include<cstdio>
#include<iostream>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
long long ll,rr,n;
long long calsum(long long n)
{
	if(n % 2 == 0)
		return (n / 2) * (n + 1);
	else
		return ( (n + 1) / 2) * n;
}
int main(void)
{
	int T;
	scanf("%d",&T);
	for(int ii = 1; ii <= T;ii++)
	{
		cin>>n;
		ll = 1;
		rr = 2000000000 + 10;
		while(rr - ll > 1)
		{
			long long mid = (ll + rr) / 2;
			long long temp = calsum(mid);
			if(temp <= n)
				ll = mid;
			else
				rr = mid;
		}
		printf("Case #%d: ",ii);
		cout<<calsum(ll)<<endl;
	}
	return 0;
}

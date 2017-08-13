#include<bits/stdc++.h>
using namespace std;

long long gcd(long long x,long long y)
{
	if(y==0LL)
		return x;
	return gcd(y,x%y);
}
long long x,y,i,j;
long long f(long long i,long long j)
{
	if(j==0)
		return 0;
	if(j>=i)
		return (f(i,j%i)+j/i);
	printf("i=%lld,j=%lld\n",i,j);
	return 1LL+f(i,j-gcd(i,j));
}
int main(void)
{
	cin>>x>>y;
	cout<<f(x,y)<<endl;
	return 0;
}

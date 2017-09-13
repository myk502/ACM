#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const long long Mod=1000000007;
long long n,k;
int prime[1010],isprime[1010];
void init(void)
{
	prime[0]=0;
	for(int i=0;i<1010;i++)
		isprime[i]=1;
	isprime[1]=0;
	for(int i=2;i<=1000;i++)
	{
		if(isprime[i])
			prime[++prime[0]]=i;
		for(int j=1;j<=prime[0];j++)
		{
			if(i*prime[j]>1000)
				break;
			isprime[i*prime[j]]=0;
			if(i%prime[j]==0)
				break;
		}
	}
}

long long calc(long long n,long long p)
{
	if(n==0)
		return 0;
	return ( n / p + calc( n / p , p ) ) ;
}

int main(void)
{
	int T;
	scanf("%d",&T);
	init();
	long long ans1,ans2;
	for(int ii=1;ii<=T;ii++)
	{
		ans1=ans2=1LL;
		init();
		scanf("%lld%lld",&n,&k);
		for(int i=1;i<prime[0];i++)
		{
			long long cnt=calc(n,(long long)prime[i]);
			ans1*=(cnt/k+1LL);
			ans2*=(cnt/(k+1)+1LL);
			ans1%=Mod;
			ans2%=Mod;
		}
		long long ans=(ans1-ans2)%Mod;
		ans=(ans+Mod)%Mod;
		printf("Case %d: %lld\n",ii,ans);

	}
	return 0;
}

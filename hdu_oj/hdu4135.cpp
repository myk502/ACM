#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
const int maxn=100000;
int cnt_factors,n,prime[maxn],isprime[maxn],p[maxn],k[maxn],bits[32];

void init(void)
{
	for(int i=0;i<maxn;i++)
		isprime[i]=true;
	prime[0]=0;
	isprime[1]=false;
	for(int i=2;i<maxn;i++)
	{
		if(isprime[i])
			prime[++prime[0]]=i;
		for(int j=1;j<=prime[0];j++)
		{
			if(i*prime[j]>=maxn)
				break;
			isprime[i*prime[j]]=false;
			if(i%prime[j]==0)
				break;
		}
	}
	bits[0]=1;
	for(int i=1;i<32;i++)
		bits[i]=bits[i-1]<<1;
}

int divide_factor(int n)//the return value is the number of prime factors
{
	int cnt,ans=0;
	memset(k,0,sizeof(k));
	for(int i=1;i<=prime[0];i++)
	{
		int pp=prime[i];
		if((long long)pp*(long long)pp>(long long)n)
			break;
		if(n%pp==0)
		{
			cnt=0;
			p[ans]=pp;
			while(n%pp==0)
			{
				cnt++;
				n=n/pp;
			}
			k[ans]=cnt;
			ans++;
		}
	}
	if(n>1)
	{
		p[ans]=n;
		k[ans]=1;
		ans++;
	}
	return ans;
}
long long calc(long long x)//calculate the number of co-prime numbers in [1,x]
{
	if(x==0LL)
		return 0LL;
	int cnt,factor;//count the number of digit 1
	long long ans=0,temp;
	int maxx=(1<<(cnt_factors));
	for(int i=1;i<maxx;i++)
	{
		cnt=0;
		factor=1;
		for(int j=0;j<cnt_factors;j++)
		{
			if(!!(i&bits[j]))//The j-th bit of i is 1
			{
				cnt++;
				factor*=p[j];
			}
		}
		//printf("Now i=%d,x=%lld and factor=%d\n",i,x,factor);
		//if(factor==1)
			//continue;
		temp=x/factor;
		if(cnt&1)
			ans+=temp;
		else
			ans-=temp;
	}
	//printf("ans=%lld\n",ans);
	return x-ans;

}
int main(void)
{
	int T;
	long long L,R;
	cin>>T;
	init();
	for(int ii=1;ii<=T;ii++)
	{
		cin>>L>>R>>n;
		cnt_factors=divide_factor(n);
		printf("Case #%d: ",ii);
		cout<<calc(R)-calc(L-1)<<endl;
	}
	return 0;
}

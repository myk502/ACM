#include<bits/stdc++.h>
using namespace std;

const int maxn=100000;
bool isprime[maxn];
int prime[maxn];
int mobius[maxn];
void Prepare_prime(void)
{
	for(int i=0;i<maxn;i++)
		isprime[i]=true;
	isprime[1]=false;
	prime[0]=0;
	mobius[1]=1;
	for(int i=1;i<maxn;i++)
	{
		if(isprime[i])
		{
			prime[++prime[0]]=i;
			mobius[i]=1;
		}
		for(int j=1;j<=prime[0];j++)
		{
			if(i*prime[j]>=maxn)
				break;
			isprime[i*prime[j]]=false;
			if(i%prime[j]==0)
				break;
			mobius[i*prime[j]]=mobius[i]*mobius[prime[j]];
		}
	}
}
bool divide_factor(int x)
{
	bool ans=true;
	for(int i=1;i<=prime[0];i++)
	{
		int p=prime[i];
		if((long long)p*(long long)p>x)
			break;
		if(x%p==0)
		{
			x/=p;
			if(x%p==0)
				ans=false;
			while(x%p==0)
				x/=p;
		}
	}
	return ans;
}
int main(void)
{
	int cnt=0;
	int cnt2=0;
	Prepare_prime();
	for(int i=1;i<maxn;i++)
	{
		if(divide_factor(i))
		{
			cnt++;
		}
		if(mobius[i]!=0)
			cnt2++;
	}
	printf("The number of such number is:%d\n",cnt);
	printf("cnt2=%d\n",cnt2);
	return 0;
}

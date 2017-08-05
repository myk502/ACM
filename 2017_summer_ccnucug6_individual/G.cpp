#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=5000000+10;
int prime[maxn],cnt[maxn];
bool isprime[maxn];
long long sum[maxn];
void init(void)
{
	for(int i=0;i<maxn;i++)
		isprime[i]=true;
	isprime[1]=false;
	prime[0]=0;
	cnt[1]=0;
	for(int i=2;i<maxn;i++)
	{
		if(isprime[i])
		{
			prime[++prime[0]]=i;
			cnt[i]=1;
		}
		for(int j=1;j<=prime[0];j++)
		{
			if(i*prime[j]>=maxn)
				break;
			isprime[i*prime[j]]=0;
			cnt[i*prime[j]]=cnt[i]+1;
			if(i%prime[j]==0)
				break;
		}
	}

}
int main(void)
{
	int t,a,b;
	init();
	cin>>t;
	sum[0]=cnt[0];
	for(int i=1;i<maxn;i++)
		sum[i]=sum[i-1]+cnt[i];
	while(t--)
	{
		scanf("%d%d",&a,&b);
		printf("%lld\n",sum[a]-sum[b]);
	}
	return 0;
}

#include<cstdio>
#include<vector>
#include<iostream>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
const int maxn=100000+10;
const long long Mod=1000000000+7;
int isprime[maxn],mobius[maxn],prime[maxn];
int n,a[maxn];
vector<int> square_free;
void init(void)
{
	square_free.clear();
	for(int i=0;i<maxn;i++)
		isprime[i]=true;
	memset(mobius,0,sizeof(mobius));
	isprime[1]=false;
	prime[0]=0;
	mobius[1]=1;
	for(int i=2;i<maxn;i++)
	{
		if(isprime[i])
		{
			prime[++prime[0]]=i;
			mobius[i]=-1;
		}
		for(int j=1;j<=prime[0];j++)
		{
			if((long long)prime[j]*(long long)i>=(long long)maxn)
				break;
			isprime[i*prime[j]]=false;
			if(i%prime[j]==0)
				break;
			mobius[i*prime[j]]=mobius[i]*mobius[prime[j]];
		}
	}
	for(int i=2;i<maxn;i++)
	{
		if(mobius[i]!=0)
			square_free.push_back(i);
	}
}

long long FastMod(int x,int n)
{
	 long long pow=x,ans=1;
	 while(n)
	 {
		 if(n&1)
			ans=(ans*pow)%Mod;
		 n>>=1;
		 pow=(pow*pow)%Mod;
	 }
	 return ans%Mod;
}

int main(void)
{
	int T,minn,maxx,cnt;
	long long ans,temp;
	cin>>T;
	init();
	for(int ii=1;ii<=T;ii++)
	{
		ans=0;
		minn=maxn;
		maxx=-1;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			minn=min(a[i],minn);
			maxx=max(a[i],maxx);
		}
		sort(a,a+n);
		for(auto it:square_free)
		{
			cnt=0;
			temp=1;
			if(it>minn)
				break;
			for(int k=(minn/it);k<=(maxx/it);k++)
			{
				auto ll=lower_bound(a,a+n,k*it);
				auto rr=lower_bound(a,a+n,k*it+it);
				if(rr-ll==0)
					continue;
				cnt+=rr-ll;
				temp*=FastMod(k,rr-ll);
				//printf("ans=%lld,it=%d\n",ans,it);
				temp%=Mod;
			}
			if(cnt!=n)
				while(1);
			if(mobius[it]==-1)
				ans+=temp;
			else
				ans-=temp;
			ans=(ans+Mod)%Mod;

		}
		printf("Case #%d: %lld\n",ii,ans);
	}
	return 0;
}

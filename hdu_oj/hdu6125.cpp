#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn=500+10;
int prime[maxn],mobius[maxn],status[maxn],mask[maxn],bits[maxn],n,k;
bool isprime[maxn];
vector<int> G[maxn];
vector<int> a[maxn];
const long long Mod=1000000000+7;
long long dp[510][520];
bool iseligble(int x,int mask)
{
	for(int i=0;i<8;i++)
	{
		int bit_x=x&bits[i];
		int bit_mask=mask&bits[i];
		if(bit_x>bit_mask)
			return false;
	}
	return true;
}
void init(void)
{
	for(int i=0;i<maxn;i++)
		isprime[i]=true;
	memset(mobius,0,sizeof(mobius));
	isprime[1]=false;
	mobius[1]=1;
	for(int i=2;i<maxn;i++)
	{
		if(isprime[i])
		{
			mobius[i]=-1;
			prime[++prime[0]]=i;
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
	bits[0]=1;
	for(int i=1;i<32;i++)
		bits[i]=bits[i-1]<<1;
	for(int i=0;i<maxn;i++)
		G[i].clear();
	for(int i=1;i<maxn;i++)
	{
		int x=i;
		mask[i]=0;
		if(mobius[i]==0)
			continue;
		for(int j=1;j<=8;j++)
			while(x%prime[j]==0)
			{
				x/=prime[j];
				mask[i]|=bits[j-1];
			}
		if(x!=1)
			G[x].push_back(i);
		else
			G[0].push_back(i);
	}
}

int main(void)
{
	long long ans;
	ios::sync_with_stdio(false);
	int T;
	init();
	cin>>T;
	while(T--)
	{
		ans=0LL;
		memset(dp,0,sizeof(dp));
		for(int i=0;i<maxn;i++)
			a[i].clear();
		int cnt=0;
		cin>>n>>k;
		for(auto it:G[0])
			if(it<=n)
				a[cnt++].push_back(it);
		for(int j=9;j<=prime[0];j++)
		{
			int x=prime[j];
			if(x>n)
				break;
			if(!G[x].empty())
			{
				bool temp_flag=false;
				for(auto it:G[x])
					if(it<=n)
					{
						a[cnt].push_back(n);
						temp_flag=true;
					}
				if(temp_flag)
					cnt++;
			}

		}
		dp[0][0]=1LL;
		for(int i=0;i<cnt;i++)
		{
			for(int j=k;j>=1;j--)
			{
				for(int m=255;m>=0;m--)
				{
					for(auto x:a[i])
					{
						if(!iseligble(mask[x],m))
							continue;
						dp[j][m]+=dp[j-1][m^mask[x]];
						dp[j][m]%=Mod;
					}
				}
			}
		}
		for(int j=1;j<=k;j++)
			for(int m=0;m<256;m++)
			{
				ans=ans+dp[j][m];
				ans%=Mod;
			}
		cout<<ans<<endl;
	}
	return 0;
}

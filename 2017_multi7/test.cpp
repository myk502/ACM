#include<vector>
#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,k;
int prime[510];
bool isprime[510],isok[510];
bool isupdated[510][510];
int mobius[510];
long long dp[510][510][160];
vector<int> factor[510];
vector<int> b;
int cnt_b;
const long long Mod=1000000000+7;
void init(void)
{
	memset(isupdated,0,sizeof(isupdated));
	for(int i=0;i<=500;i++)
		isok[i]=true;
	for(int i=0;i<=500;i++)
		isprime[i]=true;
	memset(mobius,0,sizeof(mobius));
	isprime[1]=false;
	prime[0]=0;
	mobius[1]=1;
	for(int i=1;i<=500;i++)
	{
		if(isprime[i])
		{
			prime[++prime[0]]=i;
			mobius[i]=-1;
		}
		for(int j=1;j<=prime[0];j++)
		{
			if(i*prime[j]>500)
				break;
			isprime[i*prime[j]]=false;
			if(i%prime[j]==0)
				break;
			mobius[i*prime[j]]=mobius[i]*mobius[prime[j]];
		}
	}
	for(int i=1;i<=500;i++)
	{
		if(mobius[i]!=0)
		{
			b.push_back(i);
			cnt_b++;
		}
	}
	cout<<cnt_b<<endl;
	for(int i=2;i<=500;i++)
	{
		int cnt;
		int val=i;
		while(val>1)
		{
			for(int j=1;j<=prime[0];j++)
			{
				if(val==1)
					break;
				if(val%prime[j]==0)
				{
					cnt=0;
					factor[i].push_back(j);
					while(val%prime[j]==0)
					{
						val/=prime[j];
						cnt++;
					}
					if(cnt>1)
						isok[i]=false;
				}
			}
			break;
		}
	}
}
int main(void)
{
	long long ans;
	int T;
	scanf("%d",&T);
	init();
	//cout<<prime[0]<<endl;
	/*	
	while(T--)
	{
		scanf("%d%d",&n,&k);
		for(int i=0;i<=k;i++)
		{
			dp[0][i][0]=1LL;
			isupdated[0][i]=true;
		}
		//dp[1][1][0]=1LL;
		//dp[1][0][0]=1LL;
		//isupdated[1][1]==true;
		for(int i=1;i<=n;i++)
			for(int j=0;j<=k;j++)
			{
				if(j>i)
					continue;
				if(isupdated[i][j])
					continue;
				if(j==0)
				{
					dp[i][j][0]=1LL;
					isupdated[i][j]=true;
					continue;
				}
				if(i!=1)
					for(auto it:dp[i-1][j])
						dp[i][j].insert(it);
				if(isok[i])
				{
					for(auto it:dp[i-1][j-1])
					{
						long long mask=it.first,val=it.second;
						bool flag=true;
						for(auto k:factor[i])
						{
						 	if((mask>>k)&1LL)
							{
								flag=false;
								break;
							}
						}
						if(flag)
						{
							long long mask_new=mask;
							for(auto k:factor[i])
								mask_new|=(1LL<<k);
							dp[i][j][mask_new]=(dp[i][j][mask_new]+val)%Mod;

						}
					}
				}
				isupdated[i][j]=true;
				for(auto it:dp[i][j])
				{
					printf("dp[%d][%d][%lld]=%lld\n",i,j,it.first,it.second);
				}
			}
		ans=0;
		for(int j=1;j<=k;j++)
			for(auto it:dp[n][j])
				ans=(ans+it.second)%Mod;
		printf("%lld\n",ans);
	}
	*/
	return 0;
}

#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=100;
int x;
long long n,k,sum[maxn],particular[maxn],num[maxn],ans;
unsigned long long cal_level(int x)
{
	long long pow[100];
	pow[0]=1LL;
	for(int i=1;i<=x-2;i++)
		pow[i]=pow[i-1]*k;
	unsigned long long ans=0LL;
	for(int i=0;i<=x-2;i++)
		ans+=pow[i];
	return ans;
}
long long cal_val(long long l1,long long r1,long long l2,long long r2,long long val)
{
	long long ans=0;
	long long ll,rr;
	ll=max(l1,l2);
	rr=min(r1,r2);
	ans=(rr-ll+1)*val;
	if(ans<0LL)
		ans=0LL;
	//printf("[%lld,%lld] with [%lld,%lld],val:%lld,total:%lld\n",l1,r1,l2,r2,val,ans);
	return ans;
}
void dfs(int level,long long &id,long long &val,long long lend)
{
	long long rend=lend+num[level]-1;//This rend really exists
	if(level==x)
	{
		id=(rend-1)/k;
		val=cal_val(lend,rend,id*k+1,id*k+k,1);
		val++;
		if(num[x]%2LL==1LL)
			ans^=1;
		return ;
	}
	dfs(level+1,id,val,lend+num[level]);
	//cout<<"LEVEL"<<level<<" "<<"id:"<<id<<" "<<"value:"<<val<<"  "<<"lend:"<<lend<<endl;
	//The first step,calculate the contribution of this level
	if((id-lend)%2LL==1LL)
		ans^=sum[level];
	if((rend-id)%2LL==1LL)
		ans^=sum[level+1];
	ans^=val;
	long long new_id=(id-1)/k;
	val+=cal_val(new_id*k+1,new_id*k+k,lend,id-1,sum[level]);
	val+=cal_val(new_id*k+1,new_id*k+k,id+1,rend,sum[level+1]);
	val++;
	id=new_id;
	return ;
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		ans=0;
		cin>>n>>k;
		if(k==1)
		{
			if(n%4LL==0LL)
				cout<<n<<endl;
			if(n%4LL==1LL)
				cout<<1<<endl;
			if(n%4LL==2LL)
				cout<<n+1<<endl;
			if(n%4LL==3LL)
				cout<<0<<endl;
			continue;
		}
		for(int i=1;i<70;i++)
		{
			unsigned long long temp=cal_level(i);
			if(temp>=(unsigned long long)n)
			{
				x=i-1;
				break;
			}
		}
		sum[x]=1;
		for(int i=x-1;i>=1;i--)
			sum[i]=k*sum[i+1]+1LL;
		num[1]=1;
		for(int i=2;i<x;i++)
			num[i]=num[i-1]*k;
		num[x]=n-(long long)cal_level(x);
		long long tempa,tempb;
		dfs(1,tempa,tempb,0);
		cout<<ans<<endl;
	}
	return 0;
}

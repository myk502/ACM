#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=200000+10;
long long sum,w[maxn],n,pre[maxn];
long long cnt[maxn],d[maxn],ans;

void change(int L,int R,int r,int td)
{
	if(R<L)
		return ;
	d[L]+=td;
	d[R+1]-=td;
	cnt[L]+=r-td;
	cnt[R+1]-=(R-L)*td+r;
}

int main(void)
{
	ios::sync_with_stdio(false);
	int j;
	cin>>n;
	sum=0;
	pre[0]=0;
	ans=0LL;
	for(int i=1;i<=n;i++)
	{
		cin>>w[i];
		sum+=w[i];
		pre[i]=pre[i-1]+w[i];
	}
	memset(cnt,0,sizeof(cnt));
	memset(d,0,sizeof(d));
	for(int i=1;i<=n;i++)
	{
		j=upper_bound(pre+i,pre+n+1,sum/2+pre[i-1])-pre;
		if(j==n+1)
			j=n;
		if(j!=i)
			change(i,j-1,j-i,-1);
		if(j!=n)
		{
			ans+=(n-j)*sum;
			change(i,j-1,j-n,0);
			change(j,n-1,j-n,1);
		}
	}
	for(int i=1;i<=n;i++)
	{
		d[i]+=d[i-1];
		cnt[i]+=cnt[i-1]+d[i];
	}
	for(int i=1;i<=n;i++)
	{
		ans+=cnt[i]*w[i];
	}
	cout<<ans<<endl;
	return 0;
}

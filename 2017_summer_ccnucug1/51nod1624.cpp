#include<cstdio>
#include<cstring>
#include<iostream>
#include<set>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=100000+10;
long long sum[4][maxn],a[4][maxn],p;
long long sum_x[maxn],sum_y[maxn];
set<long long> s;
int n;
void init(void)
{
	cin>>n>>p;
	for(int i=1;i<=3;i++)
	{
		for(int j=1;j<=n;j++)
		{
			scanf("%lld",&a[i][j]);
		}
	}
	sum[1][0]=sum[2][0]=0;
	for(int i=1;i<=n;i++)
	{
		sum[1][i]=(sum[1][i-1]+a[1][i])%p;
		sum[2][i]=(sum[2][i-1]+a[2][i])%p;
	}
	sum[3][n]=a[3][n];
	for(int i=n-1;i>=1;i--)
		sum[3][i]=(sum[3][i+1]+a[3][i])%p;
	for(int i=1;i<=n;i++)
	{
		sum_x[i]=(sum[1][i]-sum[2][i-1]+p)%p;
		sum_y[i]=(sum[2][i]+sum[3][i])%p;
	}
	s.clear();
}
int main(void)
{
	//set<long long>::iterator it;
	long long ans=0;
	init();
	for(int x=n;x>=1;x--)
	{
		s.insert(sum_y[x]);
		auto it=s.lower_bound(p-sum_x[x]);
		//auto it=lower_bound(s.begin(),s.end(),p-sum_x[x]);
		if(it==s.begin())
			it=s.end();
		it--;
		long long temp=(*it+sum_x[x])%p;
		ans=max(ans,temp);
	}
	cout<<ans<<endl;
	return 0;
}

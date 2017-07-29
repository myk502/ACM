#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
cosnt int maxn=200000+10;
int n,w[maxn],pre[maxn],sum;
long long pre_sum[maxn];:
int main(void)
{
	long long ans=0;
	ios::sync_with_stdio(false);
	cin>>n;
	sum=0;
	pre[0]=pre[1]=0;
	for(int i=1;i<=n;i++)
	{
		cin>>w[i];
		sum+=w[i];
		pre[i+1]=pre[i]+w[i];
	}
	for(int i=1;i<n;i++)
	{
		int j;
		j=lower_bound(pre+i+1,pre+n+1,sum/2.0+pre[i])-pre;
		if(j>i+1)
		{
			int num=j-i-1;
			for(int kk=+)
		}

	}
	return 0;
}

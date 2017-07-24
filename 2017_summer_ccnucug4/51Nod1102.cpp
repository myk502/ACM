#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn=50000+20;
int n,a[maxn],l[maxn],r[maxn];
int main(void)
{
	long long ans=-1;
    ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	l[1]=1;
	a[0]=-1;
	for(int i=2;i<=n;i++)
	{
		if(a[i]>a[i-1])
			l[i]=i;
		else//a[i]<=a[i-1]
		{
			l[i]=l[i-1];
			while(a[i]<=a[l[i]-1])
				l[i]--;
		}

	}
	r[n]=n;
	a[n+1]=-1;
	for(int i=n-1;i>=1;i--)
	{
		if(a[i]>a[i+1])
			r[i]=i;
		else
		{
			r[i]=r[i+1];
			while(a[i]<=a[r[i]+1])
			{
				r[i]++;
			}
		}
	}
	
	for(int i=1;i<=n;i++)
	{
		long long len=r[i]-l[i]+1;
		ans=max(ans,len*a[i]);
	}
	cout<<ans<<endl;
	return 0;
}

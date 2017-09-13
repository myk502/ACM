#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn=1000000+10;
struct Interval
{
	int lend,rend;
	Interval(int lend=-1,int rend=-1):lend(lend),rend(rend)
	{

	}
};
Interval minn[maxn],maxx[maxn];
int a[maxn],n;
int main(void)
{
	long long ans_min=0,ans_max=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	minn[1].lend = 1;
	maxx[1].lend = 1;
	for(int i=2;i<=n;i++)
	{
		int j = i-1;
		while(j > 0 && a[j] >= a[i])
		{
			j = minn[j].lend;
			j--;
		}
		minn[i].lend = j + 1;
		j = i - 1;
		while(j > 0 && a[j] <= a[i])
		{
			j = maxx[j].lend;
			j--;
		}
		maxx[i].lend = j + 1;
	}
	minn[n].rend = maxx[n].rend = n;
	for(int i = n - 1; i >= 1; i--)
	{
		int j = i + 1;
		while(j <= n && a[j] > a[i])
		{
			j = minn[j].rend;
			j++;
		}
		minn[i].rend = j - 1;
		j = i + 1;
		while(j <= n && a[j] < a[i])
		{
			j = maxx[j].rend;
			j++;
		}
		maxx[i].rend = j - 1;

	}
	for(int i = 1; i <= n; i++)
	{
		int ll,rr;
		ll = minn[i].lend;
		rr = minn[i].rend;
		ans_min += (long long)(rr - i + 1) * (long long)(i - ll + 1) * (long long)a[i];
		ll = maxx[i].lend;
		rr = maxx[i].rend;
		ans_max += (long long)(rr - i + 1) * (long long)(i - ll + 1) * (long long)a[i];
	}
	cout<<ans_max-ans_min<<endl;
	return 0;
}

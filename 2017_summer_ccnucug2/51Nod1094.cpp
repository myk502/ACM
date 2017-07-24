#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<map>
#include<string>
#include<algorithm>
using namespace std;
int n;
const int maxn=10000+10;
long long a[maxn],k,sum[maxn];
map<long long,int> mymap;
int main(void)
{
	int ans_i=-1,ans_j=-1;
	cin>>n>>k;
	sum[0]=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=n;i>=1;i--)
	{
		mymap[sum[i]]=i;
		long long x=sum[i-1]+k;
		if(mymap.count(x)==1)
		{
			ans_i=i;
			ans_j=mymap[x];
		}
	}
	if(ans_i==-1)
		cout<<"No Solution"<<endl;
	else
		cout<<ans_i<<" "<<ans_j<<endl;
	return 0;
}

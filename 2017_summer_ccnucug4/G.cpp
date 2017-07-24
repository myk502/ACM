#include<cstdio>
#include<vector>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=1000000+10;
int n,a[maxn],cnt[maxn+200];
int main(void)
{
	ios::sync_with_stdio(false);
	int input,zuida=-1,ans=0;
	cin>>n;
	memset(cnt,0,sizeof(cnt));
	for(int i=0;i<n;i++)
	{
		cin>>input;
		cnt[input]++;
		zuida=max(zuida,input);
	}
	for(int i=0;i<=zuida;i++)
	{
		cnt[i+1]+=cnt[i]/2;
		cnt[i]%=2;
	}
	int j=zuida+1;
	while(cnt[j]!=0)
	{
		cnt[j+1]+=cnt[j]/2;
		cnt[j]%=2;
		j++;
	}
	for(int i=0;i<=j;i++)
	{
		ans+=cnt[i];
	}
	cout<<ans<<endl;

	return 0;
}

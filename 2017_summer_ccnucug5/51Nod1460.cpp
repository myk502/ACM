#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
int n,m;
const int maxn=200000+10;
struct Bridge
{
	long long lend,rend;
	Bridge(long long xx=0,long long yy=0):lend(xx),rend(yy)
	{

	}
};
Bridge bridge[maxn],interval[maxn];
map<long long,int> cnt;
long long a[maxn];
bool cmp(Bridge X,Bridge Y)
{
	if(X.rend!=Y.rend)
		return X.rend<Y.rend;
	return X.lend<Y.lend;
}
int main(void)
{
	bool flag=true;
	long long xx,yy;
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>xx>>yy;
		bridge[i].lend=xx;
		bridge[i].rend=yy;
	}
	for(int i=0;i<m;i++)
	{
		cin>>a[i];
		cnt[a[i]]++;
	}
	for(int i=1;i<n;i++)
	{
		interval[i].lend=bridge[i].lend-bridge[i-1].rend;
		interval[i].rend=bridge[i].rend-bridge[i-1].lend;
	}
	sort(interval+1,interval+n,cmp);
	/*
	for(int i=1;i<n;i++)
		cout<<interval[i].lend<<"  "<<interval[i].rend<<endl;
	*/
	for(int i=1;i<n;i++)
	{
		auto it=cnt.lower_bound(interval[i].lend);
		if(it==cnt.end())//There is no point in this interval
			flag=false;
		if(it->first<=interval[i].rend)
			it->second--;
		else
			flag=false;
		if(it->second==0)
			cnt.erase(it);
	}
	if(flag)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	return 0;
}

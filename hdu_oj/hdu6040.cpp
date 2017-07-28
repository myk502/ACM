#include<cstdio>
#include<string>
#include<iostream>
#include<cstring>
#include<cmath>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn=10000000+10;
int n,m,b[110],bb[110];
unsigned a[maxn],x,y,z,A,B,C;
map<int,unsigned> ans;
unsigned rng61(void)
{
	unsigned t;
	x ^= x << 16;
	x ^= x >> 5;
	x ^= x << 1;
	t = x;
	x = y;
	y = z;
	z=t ^ x ^ y;
	return z;
}
bool cmp(int x,int y)
{
	return x>y;
}
int main(void)
{
	int cas=0;
	ios::sync_with_stdio(false);
	while(cin>>n>>m>>A>>B>>C)
	{
		for(int i=0;i<m;i++)
		{
			cin>>b[i];
			bb[i]=b[i];
		}
		sort(bb,bb+m,cmp);
		x=A;
		y=B;
		z=C;
		for(int i=0;i<n;i++)
			a[i]=rng61();
		int rend=n;
		for(int i=0;i<m;i++)
		{
			nth_element(a,a+bb[i],a+rend);
			ans[bb[i]]=a[bb[i]];
			rend=bb[i];
		}
		cout<<"Case #"<<++cas<<":";
		for(int i=0;i<m;i++)
		{
			cout<<" "<<ans[b[i]];
		}
		cout<<endl;


	}
	return 0;
}

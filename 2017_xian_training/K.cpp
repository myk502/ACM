#include<set>
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
long long a,b,x,ans,c;
set<long long> s;
long long solve(long long a,long long b)
{
	if(a<b)
		swap(a,b);
	if(b==0)
		return 1;
	return a/b+solve(b,a%b);
}
int main(void)
{
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	for(int ii=1;ii<=T;ii++)
	{
		cin>>a>>b;
		ans=-1;
		if((a==0)||(b==0))
		{
			if(a==b)
				ans=1;
			else
				ans=2;
		}
		if(ans==-1)
			ans=solve(a,b);
		cout<<"Case #"<<ii<<": "<<ans<<endl;
	}
	return 0;
}

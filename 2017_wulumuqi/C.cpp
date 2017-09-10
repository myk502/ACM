#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=1000+10;
int n;
int b,c[maxn],d[maxn];

int main(void)
{
	bool ans;
	int T;
	int now;
	ios::sync_with_stdio(false);
	cin>>T;
	while(T--)
	{
		cin>>n>>b;
		ans=true;
		for(int i=1;i<=n;i++)
			cin>>c[i];
		for(int i=1;i<n;i++)
			cin>>d[i];
		now=0;
		for(int i=1;i<n;i++)
		{
			now+=c[i];
			now-=d[i]*b;
			if(now<0)
				ans=false;
		}
		if(ans)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;

	}
	return 0;
}


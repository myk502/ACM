#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=100+10;
int n,height,width;
int x[maxn],y[maxn];
bool isok(int x,int y)
{
	return ((x<=height) && (y<=width));
}
int main(void)
{
	int ans=0;
	ios::sync_with_stdio(false);
	cin>>n>>height>>width;
	for(int i=0;i<n;i++)
		cin>>x[i]>>y[i];
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
		{
			bool flag=false;
			int a,b,c,d;
			a=x[i];
			b=y[i];
			c=x[j];
			d=y[j];
			if(isok(a+c,b+d))
				flag=true;
			if(isok(a+d,b+c))
				flag=true;
			if(isok(b+c,a+d))
				flag=true;
			if(isok(b+d,a+c))
				flag=true;
			if(isok(a+c,max(b,d)))
				flag=true;
			if(isok(a+d,max(b,c)))
				flag=true;
			if(isok(b+c,max(a,d)))
				flag=true;
			if(isok(b+d,max(a,c)))
				flag=true;
			if(isok(max(b,d),a+c))
				flag=true;
			if(isok(max(b,c),a+d))
				flag=true;
			if(isok(max(a,d),b+c))
				flag=true;
			if(isok(max(a,c),b+d))
				flag=true;
			if(flag)
				ans=max(ans,a*b+c*d);
		}
	cout<<ans<<endl;
	return 0;
}

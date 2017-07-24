#include<set>
#include<iostream>
#include<stack>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=50000+10;
int a[maxn],l[maxn],r[maxn],n;
stack<int> s1,s2;
int main(void)
{
	long long ans=-1;
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	a[0]=a[n+1]=0;
	s1.push(0);
	s2.push(n+1);
	for(int i=1;i<=n;i++)
	{
		while(a[i]<=a[s1.top()])
			s1.pop();
		l[i]=s1.top()+1;
		s1.push(i);
	}
	for(int i=n;i>=1;i--)
	{
		while(a[i]<=a[s2.top()])
			s2.pop();
		r[i]=s2.top()-1;
		s2.push(i);
	}
	for(int i=1;i<=n;i++)
	{
		long long temp=(long long)a[i]*(r[i]-l[i]+1);
		ans=max(ans,temp);
	}
	cout<<ans<<endl;
	return 0;
}

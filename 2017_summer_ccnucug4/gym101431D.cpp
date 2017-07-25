#include<bits/stdc++.h>
using namespace std;
const int maxn=2020;
vector<int> primary[maxn],secondary[maxn];
int n,x;
int main(void)
{
	cin>>n>>x;
	if(n-1<x)
	{
		cout<<-1<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++)//The index of dog house
	{
		int secondaryhouse=i+1;
		for(int j=(i-1)*x+1;j<=i*x;j++)
		{
			primary[i].push_back(j);
			if(secondaryhouse>n)
				secondaryhouse-=n;
			secondary[secondaryhouse].push_back(j);
			secondaryhouse++;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(auto j:primary[i])
			printf("%d ",j);
		for(auto j:secondary[i])
			printf("%d ",j);
		cout<<endl;
	}
	return 0;
}

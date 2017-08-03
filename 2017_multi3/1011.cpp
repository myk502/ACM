#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int n;
int a[1010];
int main(void)
{
	int cnt=0;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]<=35)
			cnt++;

	}
	cout<<cnt<<endl;
	return 0;
}

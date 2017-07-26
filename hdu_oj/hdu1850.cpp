#include<iostream>
#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=110;
int n,a[maxn];
int main(void)
{
	ios::sync_with_stdio(false);
	int sg,cnt,k;
	while(cin>>n)
	{
		sg=0;
		cnt=0;
		if(n==0)
			break;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			sg^=a[i];
		}
		k=0;
		if(sg==0)
		{
			cout<<0<<endl;
			continue;
		}
		while(sg!=0)
		{
			sg>>=1;
			k++;
		}
		for(int i=0;i<n;i++)
		{
			int temp=a[i]>>(k-1);
			if(temp&0x1)
				cnt++;
		}
		cout<<cnt<<endl;
	}
	return 0;
}

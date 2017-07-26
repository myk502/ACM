#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
int k,s[110],m,n,a[110];
int nim[10000+10];
int main(void)
{
	int hash[105];
	ios::sync_with_stdio(false);
	while(cin>>k)
	{
		if(k==0)
			break;
		for(int i=0;i<k;i++)
			cin>>s[i];
		cin>>m;
		memset(nim,0,sizeof(nim));
		for(int i=1;i<=10000;i++)
		{
			memset(hash,0,sizeof(hash));
			for(int j=0;j<k;j++)
			{
				int id=i-s[j];
				if(id<0)
					continue;
				hash[nim[id]]=1;
			}
			for(int j=0;j<105;j++)
			{
				if(hash[j]==0)
				{
					nim[i]=j;
					break;
				}
			}
		}
		while(m--)
		{
			int sg=0;
			cin>>n;
			for(int i=0;i<n;i++)
			{
				cin>>a[i];
				sg^=nim[a[i]];
			}
			if(sg==0)
				cout<<"L";
			else
				cout<<"W";
		}
		cout<<endl;
	}
	return 0;
}

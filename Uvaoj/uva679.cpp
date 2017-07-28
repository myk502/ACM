#include<cstdio>
#include<vector>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int depth,n;
const int maxn=(1<<20)+10;
vector<int> G[maxn];
int  a[maxn],mod[maxn];
int main(void)
{
	int T;
	ios::sync_with_stdio(false);
	for(int i=1;i<=maxn;i++)
	{
		int temp=__builtin_clz(i);
		temp=31-temp;
		mod[i]=1<<temp;
	}
	a[1]=0;
	int maxx=-1;
	for(int i=2;i<=maxn;i+=2)
	{
		if(a[i>>1]==0)
			a[i]=(mod[i]>>1);
		else
			a[i]=a[i>>1];
		a[i+1]=(a[i]+(mod[i]>>1))%mod[i];
		maxx=max(maxx,a[i]);
		maxx=max(maxx,a[i+1]);
	}
	for(int i=1;i<=maxn;i++)
	{
		int temp=a[i];
		G[temp].push_back(i);
	}
	

	while(cin>>T)
	{
		if(T==-1)
			break;
		while(T--)
		{
			cin>>depth>>n;
			int Mod=1<<(depth-1);
			int nn=n%Mod;
			for(auto it:G[nn])
			{
				if(mod[it]==Mod)
				{
					cout<<it<<endl;
					break;
				}
			}
		}
	}
	
	return 0;
}

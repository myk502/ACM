#include<cstdio>
#include<iostream>
#include<set>
#include<vector>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
const int maxn=100000+10;
set<int> s;
vector<int> G[maxn];
int n,m,num[maxn],type[maxn];
int main(void)
{
	int xx,ll,kk,T,ans;
	cin>>T;
	while(T--)
	{
		ans=0;
		for(int i=0;i<maxn;i++)
			G[i].clear();
		s.clear();
		memset(num,0,sizeof(num));
		scanf("%d%d",&n,&m);
		for(int ii=1;ii<=m;ii++)
		{
			scanf("%d%d%d",&xx,&ll,&kk);
			type[ii]=ll;
			int lend=max(1,xx-kk);
			int rend=min(n,xx+kk);
			G[lend].push_back(ii);
			G[rend+1].push_back(-ii);
		}
		for(int i=1;i<=n;i++)
		{
			for(auto it:G[i])
			{
				if(it>0)//This is the begin position for a joke
				{
					s.insert(it);
					num[type[it]]++;
				}
				else
				{
					s.erase(-it);
					num[type[-it]]--;
				}
			}
			if(s.empty())
				ans++;//important! No jokes at all
			else
			{
				auto it=s.end();
				it--;
				if(num[type[*it]]>1)
					ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

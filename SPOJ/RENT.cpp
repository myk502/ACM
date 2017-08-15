#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
const int maxn=2000000+10;
typedef pair<int,int> pii;
vector<pii> begin_time[maxn];
int n;
int dp[maxn];
int main(void)
{
	int T,st,d,p,ans;
	scanf("%d",&T);
	while(T--)
	{
		ans=-1;
		for(int i=0;i<maxn;i++)
			begin_time[i].clear();
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%d%d%d",&st,&d,&p);
			begin_time[st+d].push_back(make_pair(st,p));
		}
		dp[0]=0;
		for(int i=1;i<maxn;i++)
		{
			dp[i]=dp[i-1];
			for(auto it:begin_time[i])
			{
				int bg=it.first,price=it.second;
				if(dp[bg]+price>dp[i])
					dp[i]=dp[bg]+price;
			}
		}
		cout<<dp[maxn-1]<<endl;
	}
	return 0;
}

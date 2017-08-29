#include<cstdio>
#include<cstring>
#include<string>
#include<map>
#include<vector>
#include<cmath>
#include<algorithm>
#include<iostream>
using namespace std;
const int maxn=100000+10;
int s[maxn],e[maxn],n,cnt,ans;
multimap<int,int> a;
typedef pair<int,int> pii;
vector<pii> Time;
bool cmp(pii X,pii Y)
{
	if(X.first!=Y.first)
		return X<Y;
	bool flag_x,flag_y;
	if(X.first==s[X.second])
		flag_x=true;
	else
		flag_x=false;
	if(Y.first==s[Y.second])
		flag_y=true;
	else
		flag_y=false;
	return (!flag_x) && flag_y;
}
int main(void)
{
	long long ans_true;
	int T;
	scanf("%d",&T);
	while(T--)
	{
		ans_true=0LL;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%d%d",&s[i],&e[i]);
		a.clear();
		Time.clear();
		ans=cnt=0;
		for(int i=0;i<n;i++)
		{
			Time.push_back(make_pair(s[i],i));
			Time.push_back(make_pair(e[i],i));
		}
		sort(Time.begin(),Time.end(),cmp);
		for(auto it:Time)
		{
			int val=it.first;
			int id=it.second;
			bool flag;
			if(val==s[id])
				flag=true;
			else
				flag=false;
			if(flag)//This a start time
			{
				if(cnt>0)//There is still machines remaining
				{
					cnt--;
					auto i=a.upper_bound(s[id]);
					i--;
					int temp_start=i->second;
					a.erase(i);
					a.insert(make_pair(e[id],temp_start));
				}
				else//There is no machine remaining
				{
					ans++;
					a.insert(make_pair(e[id],s[id]));
				}
			}
			else//This is an end time
			{
				cnt++;
			}
		}
		for(auto it:a)
			ans_true+=it.first-it.second;
		cout<<ans<<" "<<ans_true<<endl;	
	}
	return 0;
}

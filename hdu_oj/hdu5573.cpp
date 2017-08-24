#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
long long n,k;
long long b[70];
typedef pair<long long,bool> pii;
vector<pii> ANS;

void solve(long long x,int level)
{
	if(level==1LL)
	{
		ANS.push_back(make_pair(b[1],(x>0)));
		return ;
	}
	if(x<0LL)
	{
		ANS.push_back(make_pair(b[level],false));
		solve(x+b[level],level-1);
	}
	else
	{
		ANS.push_back(make_pair(b[level],true));
		solve(x-b[level],level-1);
	}
}

int main(void)
{
	int T;
	scanf("%d",&T);
	for(int ii=1;ii<=T;ii++)
	{
		ANS.clear();
		cin>>n>>k;
		b[1]=1;
		for(int i=2;i<=k;i++)
			b[i]=b[i-1]*2LL;
		if(n%2==0LL)
			b[k]+=1LL;
		solve(n,k);
		printf("Case #%d:\n",ii);
		for(int i=ANS.size()-1;i>=0;i--)
		{
			cout<<ANS[i].first<<" ";
			if(ANS[i].second)
				cout<<"+"<<endl;
			else
				cout<<"-"<<endl;
		}
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
vector<pair<long long,long long> > ANS;
int n,k;
map<long long,int> a;
int main(void)
{
	long long ll,rr;
	scanf("%d%d",&n,&k);
	for(int i = 0; i < n;i++)
	{
		scanf("%I64d%I64d",&ll,&rr);
		ll += ll;
		rr += rr;
		a[ll]++;
		a[rr + 1]--;
		a[rr] = a[rr];
	}
	ll = rr= -1;
	int num = 0;
	long long pos,val;
	for(auto it:a)
	{
		pos = it.first;
		val = it.second;
		num += val;
		if(num >= k)
		{
			if(ll == -1)
			{
				ll = rr = pos;
			}
			else 
				rr = pos;
		}
		else
		{
			if(ll != -1)
			{
				ANS.push_back(make_pair(ll,rr));
				ll = rr = -1;
			}
		}
	}
	cout<<ANS.size()<<endl;
	for(auto it:ANS)
		printf("%I64d %I64d\n",it.first/2,it.second/2);
	return 0;
}

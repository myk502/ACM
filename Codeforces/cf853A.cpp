#include<bits/stdc++.h>
using namespace std;
const int maxn = 300000 + 10;
int n, k, c[maxn],t[maxn];
long long sum = 0,ans = 0;
typedef pair<int,int> pii;
set<pii> s;
int main(void)
{
	scanf("%d%d",&n,&k);
	for(int i = 1; i <= n;i++)
		scanf("%d",&c[i]);
	for(int i = 1; i <= k;i++)
	{
		s.insert(make_pair(c[i],i));
		sum += c[i];
		ans += sum;
	}
	for(int i = k + 1;i <= k + n;i++)
	{
		if(i <= n)
		{
			s.insert(make_pair(c[i],i));
			sum += c[i];
		}
		auto it = s.end();
		it--;
		int ii = it -> second;
		int cc = it -> first;
		sum -= cc;
		ans += sum;
		t[ii] = i;
		s.erase(it);
	}
	cout<<ans<<endl;
	for(int i = 1; i <= n;i++)
		printf("%d ",t[i]);
	printf("\n");
	return 0;
}

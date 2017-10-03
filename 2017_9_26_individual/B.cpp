#include<bits/stdc++.h>
using namespace std;
const int maxn = 200000 + 10;
int f[maxn],pos[maxn],n;
int main(void)
{
	long long ans = 0;
	scanf("%d",&n);
	for(int i = 1;i <= n;i++)
	{
		scanf("%d",&f[i]);
		pos[f[i]] = i;
	}
	for(int i = 2; i <= n;i++)
	{
		ans += abs(pos[i] - pos[i-1]);
	}
	cout<<ans<<endl;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;

int main(void)
{
	long long n, k,ans1,ans2;
	cin>>n>>k;
	if(n == k)
		ans1 = 0LL;
	else
		ans1 = 1LL;
	if(k == 0LL)
		ans1 = 0LL;
	ans2 = min(n - k,k << 1);
	cout<<ans1<<" "<<ans2<<endl;
	return 0;
}

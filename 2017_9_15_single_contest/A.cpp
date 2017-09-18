#include<bits/stdc++.h>
using namespace std;
long long pow2[40];
void init(void)
{
	pow2[0]=1;
	for(int i=1;i<40;i++)
	{
		pow2[i] = pow2[i-1] << 1;
	}
}
int main(void)
{
	init();
	long long n,t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		long long ans = ((n+1) * n)/2;
		for(int i = 0;i<40;i++)
		{
			if(pow2[i]<=n)
				ans -=2*pow2[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}

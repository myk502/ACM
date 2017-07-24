#include<bits/stdc++.h>
using namespace std;
const long long Mod=1000000007;
long long pow_3(int n)
{
	if(n==0)
		return 1LL;
	if(n%2==0)
	{
		long long temp=pow_3(n/2);
		return (temp*temp)%Mod;
	}
	else
	{
		long long temp=pow_3(n-1);
		return (temp*3)%Mod;
	}

}
long long pow_2(int n)
{
	if(n==0)
		return 1LL;
	if(n%2==0)
	{
		long long temp=pow_2(n/2);
		return (temp*temp)%Mod;
	}
	else
	{
		long long temp=pow_2(n-1);
		return (temp*2)%Mod;
	}

}
int main(void)
{
	int n;
	cin>>n;
	long long inv=pow_2((int)(Mod-2));
	long long ans=pow_3(n+1)-1;
	ans=(ans+Mod)%Mod;
	ans*=inv;
	ans=(ans+Mod)%Mod;
	cout<<ans<<endl;
	return 0;
}

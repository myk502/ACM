#include<bits/stdc++.h>
using namespace std;
const long long Mod=1000000000+7;

long long FastMod(int x)
{
	if(x==0)
		return 1;
	if(x%2==0)
	{
		long long temp=FastMod(x/2);
		return temp*temp%Mod;
	}
	if(x%2==1)
	{
		long long temp=FastMod(x-1);
		return temp*3%Mod;
	}
}
int main(void)
{
	cout<<FastMod(1000000000+5)<<endl;
	return 0;
}

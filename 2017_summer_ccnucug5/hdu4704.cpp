#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<sstream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
string input;
int length;
const long long Mod=1000000000+7;

long long FastMod(long long n)//make sure x>0
{
	long long ans=1;
	long long p=2%Mod;
	while(n>0)
	{
		if(n&1LL)
			ans=(ans*p)%Mod;
		n>>=1;
		p=p*p%Mod;
	}
	return ans%Mod;
}

int main(void)
{
	ios::sync_with_stdio(false);
	while(cin>>input)
	{
		long long mod=0;
		long long y=-1;
		length=input.length();
		for(auto it:input)
		{
			int i=it-'0';
			mod*=10;
			mod+=i;
			mod%=Mod-1;
		}
		mod=(mod-1+Mod-1)%(Mod-1);
		if(length<20)
		{
			long long temp;
			stringstream ss(input);
			ss>>temp;
			temp--;
			if(temp<Mod-1)
				y=FastMod(temp);
		}
		if(y==-1)
			y=FastMod(mod+Mod-1);
		cout<<y<<endl;
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;

long long FastMod(int x,int n)
{
	 long long pow=x,ans=1;
	 while(n)
	 {
		 if(n&1)
			ans*=pow;
		 n>>=1;
		 pow*=pow;
	 }
	 return ans;
}


int main(void)
{
	int a,b;
	while(cin>>a>>b)
	{
		cout<<FastMod(a,b)<<endl;
	}
	return 0;
}

#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
string input;
int main(void)
{
	int n;
	ios::sync_with_stdio(false);
	while(cin>>input)
	{
		bool flag=true;
		n=input.length();
		if(n%2==1)
			flag=false;
		for(int i=0;i<n/2;i++)
		{
			if(input[i]!=input[i+(n/2)])
				flag=false;
		}
		if(flag)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;

}

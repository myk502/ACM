#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int X,Y,a,b,n,num[4];
string input[2];
int main(void)
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		X=Y=0;
		memset(num,0,sizeof(num));
		cin>>n>>a>>b;
		cin>>input[0]>>input[1];
		for(int i=0;i<n;i++)
		{
			if(input[0][i]!=input[1][i])
			{
				Y++;
			}
			else
				X++;

		}
		int temp_left=(a+b-Y);
		int temp_right=2*min(min(a,b),X);

		bool flag=temp_left<=temp_right;
		if(flag)
			cout<<"Not lying"<<endl;
		else
			cout<<"Lying"<<endl;

	}
	return 0;
}

#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
bool solve(int &weight)
{
	int w1,d1,w2,d2;
	bool flag1=true,flag2=true;
	cin>>w1>>d1>>w2>>d2;
	if(!w1)
		flag1=solve(w1);
	if(!w2)
		flag2=solve(w2);
	weight=w1+w2;
	return flag1 && flag2 && (w1*d1==w2*d2);
	
}
int main(void)
{
	int T,temp;
	scanf("%d",&T);
	while(T--)
	{
		if(solve(temp))
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
		if(T)
			cout<<endl;
	}
	return 0;
}

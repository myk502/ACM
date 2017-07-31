#include<cstdio>
#include<iostream>
#include<cmath>
#include<map>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
map<string,double> a;
int c,n;
string input;
double price;
double ans;
int main(void)
{
	double xx;
	int T;
	cin>>T;
	while(T--)
	{
		ans=0;
		cin>>c>>n;
		a.clear();
		a["JD"]=1;
		for(int i=0;i<c;i++)
		{
			cin>>input>>price;
			//cout<<input<<endl;
			a[input]=price;
		}
		/*
		for(auto it:a)
		{
			cout<<it.first<<" "<<it.second<<endl;
		}
		*/
		for(int i=0;i<n;i++)
		{
			cin>>xx>>input;
			ans+=xx*a[input];
		}
		printf("%.6lf\n",ans);
	}
	return 0;
}
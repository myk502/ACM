#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<set>
#include<cmath>
#include<algorithm>
using namespace std;
int n;
set<int> s;
typedef pair<int,int> pir;
set<pir> ANS;
int main(void)
{
	bool flag=false;
	cin>>n;
	for(int i=0;i*i<=n;i++)
	{
		s.insert(i*i);
	}
	for(auto it:s)//For every element in s
	{
		if(s.count(n-it)==1)//if n-it is in s
		{
			int aa=sqrt(it+0.5);
			int bb=sqrt(n-it+0.5);
			ANS.insert(make_pair(min(aa,bb),max(aa,bb)));
			flag=true;
		}

	}
	if(!flag)
		printf("No Solution\n");
	else
		for(auto it:ANS)
		{
			printf("%d %d\n",it.first,it.second);
		}
	return 0;
}

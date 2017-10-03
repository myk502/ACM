#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<vector>
#include<string>
#include<cctype>
using namespace std;
vector<string> a;
vector<string> b;
char input[100000 + 10];
int n;
int main(void)
{
	scanf("%s",input);
	int ll,rr;
	bool not_zero_exist,flag;
	n = strlen(input);
	ll = rr = 0;
	while(rr < n)
	{
		not_zero_exist = false;
		flag = true;
		if(input[rr] == ',' || input[rr] ==';')
		{
			b.push_back(string(""));
			rr++;
			ll = rr;
			continue;
		}
		while((rr < n) && (input[rr] != ',') && (input[rr] != ';'))
		{
			if(!isdigit( input[rr] ) )
				flag = false;
			if(isdigit( input[rr]) && input[rr] != '0')
				not_zero_exist = true;
			if(input[rr] == '0' && !not_zero_exist)
				flag = false;
			rr++;
		}
		if((rr - ll == 1) && input[ll] == '0')
			flag = true;
		if(flag)
			a.push_back(string(input + ll , input + rr));
		else
			b.push_back(string(input + ll , input + rr));
		rr++;
		ll = rr;
	}
	if(input[n - 1] == ';' || input[n - 1] == ',')
		b.push_back(string(""));

	if(a.size() == 0)
		printf("-\n");
	else
	{
		printf("\"");
		cout<<a[0];
		for(int i = 1; i < a.size(); i++)
			cout<<","<<a[i];
		printf("\"\n");
	}
	if(b.size() == 0)
		printf("-\n");
	else
	{
		printf("\"");
		cout<<b[0];
		for(int i = 1; i < b.size(); i++)
			cout<<","<<b[i];
		printf("\"\n");
	}
	return 0;
}

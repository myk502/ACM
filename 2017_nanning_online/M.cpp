#include<bits/stdc++.h>
using namespace std;
int n;
double a;
unsigned bits[32];
vector<unsigned int> myset;
bool judge(unsigned int x,unsigned int y)//whether x is contained in y
{
	return (x & y) == x;
}
string input;
int main(void)
{
	int x,ans=0,m=0;
	unsigned mask;
	scanf("%d%lf",&n,&a);
	bits[0] = 1;
	for(int i = 1;i <= 30;i++)
	{
		bits[i] = bits[i - 1] << 1;
	}
	scanf("\n");
	while(getline(cin,input))
	{
		m++;
		stringstream ss(input);
		mask = 0;
		while(ss >> x)
		{
			mask |= bits[x - 1];
		}
		myset.push_back(mask);
	}
	for(unsigned x = 1; x < (1U << n); x++)
	{
		int cnt = 0;
		for(auto it:myset)
		{
			if(judge(x,it))
				cnt++;
		}
		if((double)cnt >= a*m)
			ans++;

	}
	printf("%d\n",ans);
	return 0;
}

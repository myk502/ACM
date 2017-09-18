#include<bits/stdc++.h>
using namespace std;

int cnt=0;
int main(void)
{
	for(int i=1;i<=50;i++)
	{
		bool flag=true;
		for(int j=2;j<sqrt(i);j++)
			if(i%j==0)
				flag=false;
		if(flag)
		{
			cnt++;
		}
	}
	return 0;
}

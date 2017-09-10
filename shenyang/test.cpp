#include<cstdio>
#include<iostream>
using namespace std;

int main(void)
{
	int T;
	scanf("%d",&T);
	int x=729;
	while(T--)
	{
		if(x&1)
			printf("YES\n");
		else
			printf("NO\n");
		x>>=1;
	}
	return 0;
}

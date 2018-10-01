#include<cstdio>
#include<iostream>
using namespace std;

int main(void)
{
	int T;
	scanf("%d", &T);
	int temp;
	for(int ii = 1; ii <= T; ii++)
	{
		scanf("%d", &temp);
		printf("Case #%d: %d\n", ii, temp - 1);
	}
	return 0;
}

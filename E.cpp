#include<cstdio>
#include<iostream>
using namespace std;
int n, sum;
int main(void)
{
	int T, temp;
	scanf("%d", &T);
	for(int ii = 1; ii <= T; ii++)
	{
		sum = 0;
		scanf("%d", &n);
		for(int i = 0; i < n; i++)
		{
			scanf("%d", &temp);
			sum += temp;
			sum += temp / 10;
			if(temp % 10 != 0)
				sum++;
		}
		printf("Case #%d: %d\n", ii, sum);

	}
	return 0;
}

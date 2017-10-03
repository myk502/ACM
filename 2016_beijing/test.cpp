#include<bits/stdc++.h>
using namespace std;
int cnt;

int numofones(int x)
{
	int cnt = 0;
	while(x)
	{
		if(x % 10 == 1)
			cnt++;
		x /= 10;
	}
	return cnt;
}
int main(void)
{
	cnt = 0;
	int cntt = 0;
	printf("numofones(200000) = %d\n",numofones(200000));
	for(int i = 1; i <= 1e8;i++)
	{
		cnt += numofones(i);
		if(cnt == i)
		{
			cntt++;
			printf("%d\n",i);
		}
	}
	printf("%d\n",cntt);
	return 0;
}	

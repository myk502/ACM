#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
char input[10];
int miss,hit;
int x;
unsigned int val;
int cache[70];
int main(void)
{
	miss = hit = 0;
	memset(cache,-1,sizeof(cache));
	while(scanf("%s",input) != EOF)
	{
		if(strcmp("END",input) == 0)
		{
			printf("Hit ratio = %.2lf\%\n",(100.0 * hit) / (hit + miss));
			break;
		}
		sscanf(input,"%x",&x);
		val = x;
		int temp = (val >> 4) & 0x3f;//The row id of cache line
		int temp2 = (val >> 10) & 0x3ffff;
		if(cache[temp] != temp2)
		{
			miss++;
			cache[temp] = temp2;
			printf("Miss\n");
		}
		else
		{
			hit++;
			printf("Hit\n");
		}
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
char s[110];
int n ,p ,q;
void outputans(int x,int y)
{
	int id = 0;
	printf("%d\n",x + y);
	for(int i = 0; i < x;i++)
	{
		for(int j = id;j < id + p;j++)
			printf("%c",s[j]);
		id = id + p;
		printf("\n");
	}
	for(int i = 0;i < y;i++)
	{
		for(int j = id;j < id + q;j++)
			printf("%c",s[j]);
		id = id + q;
		printf("\n");
	}
}

int main(void)
{
	scanf("%d%d%d",&n,&p,&q);
	scanf("%s",s);
	bool flag = false;
	for(int x = 0; x <= 100;x++)
	{
		int temp = n - p * x;
		if(temp < 0)
			break;
		if(temp % q == 0)
		{
			flag = true;
			outputans(x,temp / q);
			break;
		}
	}
	if(!flag)
		printf("-1\n");
	return 0;
}

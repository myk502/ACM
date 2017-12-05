#include<bits/stdc++.h>
using namespace std;
int get_number(int ll, int rr)//close interval
{
	int temp = rand() % (rr - ll + 1);
	return ll + temp;
}

int main(void)
{
	srand((unsigned)time(NULL));
	printf("10\n");
	for(int i = 1; i <= 10; i++)
	{
		printf("%d\n", get_number(4396, 200000));
	}
}

#include<cstdio>
using namespace std;

int main(void)
{
	int T, n;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		printf("%d %d\n", n / 4396, n / 443);
	}
	return 0;
}

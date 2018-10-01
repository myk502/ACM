#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int v1, v2, v3, vm, x1, x2, x3;
int main(void)
{
	scanf("%d%d%d%d", &v1, &v2, &v3, &vm);
	bool flag = false;
	for(x3 = 1; x3 <= 200; x3++)
		for(x2 = x3 + 1; x2 <= 200; x2++)
			for(x1 = x2 + 1; x1 <= 200; x1++)
			{
				if((v1 > x1) || (x1 > (2 * v1)))
					continue;
				if((v2 > x2) || (x2 > (2 * v2)))
					continue;
				if((v3 > x3) || (x3 > (2 * v3)))
					continue;
				if((vm > x1) || (vm > x2) || (vm > x3) || (x3 >( 2*vm)))
					continue;
				if(x1 <= (2*vm))
					continue;
				if(x2 <= (2 * vm))
					continue;
				flag = true;
				printf("%d\n%d\n%d\n", x1, x2, x3);
				goto done;
			}
done:	if(!flag)
		printf("-1\n");
	return 0;
}


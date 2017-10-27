#include<cstdio>
#include<cmath>
using namespace std;

int main()
{
	double x,y;
	while(scanf("%lf",&x) != EOF)
	{
		y = abs(x);
		printf("%.2lf\n",y);
	}
	return 0;
}

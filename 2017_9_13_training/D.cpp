#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int dis,n,b;
double d,vx,vy,v0,yy0,xx0;
const int maxn=15;
int p[maxn],k[maxn];
int main(void)
{
	scanf("%d%d%d",&dis,&n,&b);
	for(int i=0;i<n;i++)
		scanf("%d%d",&p[i],&k[i]);
	double ans=10000000000000000;
	for(int i=0;i<=b;i++)
	{
		d = (double)dis / (double)(i+1);
		vx = sqrt(d/2);
		for(int j=0;j<n;j++)
		{
			xx0=p[j]-( (int)(p[j]/d + 0.1) * d );
			if(xx0 < 0)
				xx0 += d;
			yy0=k[j];
			double temp = sqrt((d*xx0 - xx0*xx0) / (2 * yy0 ));
			if(temp < vx)
				vx = temp;
		}
		vy = d / (2 * vx);
		ans = min(ans,sqrt(vx*vx+vy*vy));
	}
	printf("%.9lf\n",ans);
	return 0;
}

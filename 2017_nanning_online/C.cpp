#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m,reserved_price,bidder,bidder_price;
int ans[510];
int nearest(double x)
{
	int a = (int)x;
	int b = a + 1;
	double aa = fabs(a - x);
	double bb = fabs(b - x);
	if(fabs(aa-bb) < 0.0001)
		return b;
	if(aa < bb)
		return a;
	else
		return b;
}
int main(void)
{
	bool flag;
	int maxx,max_id,second_largest,q,k;
	scanf("%d%d",&n,&m);
	memset(ans,0,sizeof(ans));
	for(int i = 1;i <= n;i++)
	{
		flag = false;
		scanf("%d",&reserved_price);
		maxx = second_largest = reserved_price;
		while(scanf("%d",&bidder))
		{
			if(bidder == -1)
				break;
			scanf("%d",&bidder_price);
			if(bidder_price < reserved_price)
				continue;
			flag = true;
			if(bidder_price > maxx)
			{
				max_id = bidder;
				second_largest = maxx;
				maxx = bidder_price;
			}
			else if(bidder_price == maxx)
			{
				second_largest = max(second_largest , bidder_price);
				max_id = min(max_id,bidder);
			}
			else//bidder_price < maxx
			{
				second_largest = max(second_largest , bidder_price);
			}
		}
		if(!flag)
			continue;
        double xx = 1.1 * second_largest;
		double tempans = min(xx , (double)maxx);
		ans[max_id] += nearest(tempans);
	}
	scanf("%d",&k);
	while(k--)
	{
		scanf("%d",&q);
		printf("%d\n",ans[q]);
	}
	return 0;
}


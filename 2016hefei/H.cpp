#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn = 110;
int a[maxn],num[2500],n,m;
int sum[maxn];
int main(void)
{
	int T,xx;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		memset(num, -1, sizeof(num));
		sum[0] = 0;
		for(int i = 1; i <= n; i++)
			sum[i] = sum[i - 1] ^ a[i];
		for(int ll = 1; ll <= n; ll++)
		{
			for(int rr = ll; rr <= n; rr++)
			{
				int temp = sum[rr] ^ sum[ll - 1];
				if(num[temp] == -1)
					num[temp] = (rr - ll + 1);
				else
					num[temp] = max(num[temp], (rr - ll + 1));
			}
		}
		scanf("%d",&m);
		while(m--)
		{
			int lend,rend,ans1,ans2,ans;
			scanf("%d",&xx);
			if(xx < 0)
				xx = 0;
			ans1 = ans2 = -1;
			rend = lend = xx;
			while(lend >= 0)
			{
				if(num[lend] != -1)
				{
					ans1 = num[lend];
					break;
				}
				lend--;
			}
			while(rend <= 2048)
			{
				if(num[rend] != -1)
				{
					ans2 = num[rend];
					break;
				}
				rend++;
			}
			if(2 * xx == lend + rend)
				ans = max(ans1,ans2);
			else if(xx - lend < rend - xx && ans1 != -1)
				ans = ans1;
			else
				ans = ans2;
			printf("%d\n", ans);
		}
		printf("\n");
	}
	return 0;
}

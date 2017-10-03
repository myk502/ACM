#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<climits>
#include<algorithm>
using namespace std;
int n,m,q,p[110],a[110],sum[110],summ[110];
int main(void)
{
	int temp,ans,ans1,ans2;
	int ii = 0;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		ans = INT_MAX;
		for(int i = 0; i < n;i++)
			scanf("%d",&p[i]);
		memset(a,0,sizeof(a));
		memset(sum,0,sizeof(sum));
		memset(summ,0,sizeof(summ));
		scanf("%d",&q);
		while(q--)
		{
			scanf("%d",&temp);
			a[temp] = 1;
		}
		for(int i = 1; i <= n;i++)
		{
			summ[i] = summ[i-1] + p[i-1];	
			sum[i] = sum[i-1] + a[i-1];
		}
		int cnt,tempans2;
		for(int ll = 0;ll < n;ll++)
		{
			if(a[ll])
				continue;
			int minn = INT_MAX;
			cnt = 1;
			for(int rr = ll + 1;rr<n;rr++)
			{
				if(!a[rr])
					cnt++;
				if(cnt <= m && !a[rr])
				{
					if(minn > p[rr])
					{
						tempans2 = rr;
						minn = p[rr];
					}
				}
				if(cnt == m)
					break;

			}
			if(cnt != m)
				continue;
			if(p[ll] + p[tempans2] < ans)
			{
				ans = p[ll] + p[tempans2];
				ans1=ll;
				ans2 = tempans2;
			}
		}
		printf("%d %d\n",ans1,ans2);

	}
	return 0;
}

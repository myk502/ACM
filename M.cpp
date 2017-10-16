#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int n, m,num_broken,cnt_min,cnt_max;
const int maxn = 1000 + 10;
vector<int> G[maxn];
int main(void)
{
	int T,xx,yy;
	scanf("%d",&T);
	for(int ii = 1; ii <= T;ii++)
	{
		cnt_min = cnt_max = 0;
		for(int i = 0 ; i < maxn; i++)
			G[i].clear();
		scanf("%d%d",&n,&m);
		scanf("%d",&num_broken);
		while(num_broken--)
		{
			scanf("%d%d",&xx,&yy);
			G[xx].push_back(yy);
		}
		for(int i = 0 ; i < n;i++)
		{
			G[i].push_back(m);
			sort(G[i].begin(),G[i].end());
		}
		for(int i = 0 ; i < n;i++)
		{
			int pre = -1;
			for(auto it:G[i])
			{
				int temp = it - pre - 1;
				//printf("temp = %d,i = %d\n",temp,i);
				cnt_max += (temp + 1) / 2 ;
				if(temp != 0)
					cnt_min += (temp - 1) / 3 + 1;
				pre = it;
			}
		}
		printf("Case #%d: %d %d\n",ii,cnt_max,cnt_min);
	}
	return 0;
}

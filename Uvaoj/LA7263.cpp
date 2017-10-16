#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<vector>
#include<climits>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
queue<int> q;
const int maxn = 1000000;
const int INF = INT_MAX >> 1;
char input[120];
int origin[120],final[120],dis[maxn],pow_10[8],n;
void init(void)
{
	pow_10[0] = 1;
	for(int i = 1; i < 7;i++)
		pow_10[i] = pow_10[i - 1] * 10;
	for(int i = 0; i < maxn;i++)
		dis[i] = INF;
	dis[123456] = 0;
	q.push(123456);
	while(!q.empty())
	{
		int temp = q.front(),tmp;
		q.pop();
		for(int i = 1; i <= 6;i++)
		{
			for(int j = 1; j <= 6;j++)
			{
				tmp = temp;
				if(i == j)
					continue;
				for(int k = 0 ; k < 6; k++)
				{
					int id;
					id = tmp / pow_10[k];
					id %= 10;
					if(id == i)
						tmp += (j - i) * pow_10[k];
				}
				if(dis[tmp] == INF)
				{
					dis[tmp] = dis[temp] + 1;
					q.push(tmp);
				}
			}
		}
	}

}
int main(void)
{
	int ans,a[7],cnt;
	init();
	while(scanf("%s",input) != EOF)
	{
		n = strlen(input);
		for(int i = 1; i <= n;i++)
			final[i] = input[i - 1] - '0';
		scanf("%s",input);
		for(int i = 1; i <= n;i++)
			origin[i] = input[i - 1] - '0';
		ans = INF;
		for(int i = 111111; i <= 666666;i++)
		{
			if(dis[i] == INF)
				continue;
			cnt = dis[i];
			int j = 6,tmp = i;
			while(tmp)
			{
				a[j--] = tmp % 10;
				tmp /= 10;
			}
			for(int k = 1; k <= n;k++)
				if(a[origin[k]] != final[k])
					cnt++;
			ans = min(ans,cnt);
		}
		printf("%d\n",ans);
	}
	return 0;
}

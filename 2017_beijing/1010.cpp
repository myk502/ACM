#include<cstdio>
#include<iostream>
#include<cmath>
#include<climits>
#include<queue>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
const int maxn = 100 + 10;
int n, ll, rr, a[maxn];

bool isok(int x, int ll, int rr)//judge whether x can be composed by elements in [ll,rr]
{
	bool visit[210];
	memset(visit, 0, sizeof(visit));
	priority_queue<int,vector<int>, greater<int> > pq;
	int temp = 0;
	pq.push(temp);
	visit[0] = true;
	while(temp <= x)
	{
		temp = pq.top();
		if(temp == x)
			return true;
		pq.pop();
		for(int i = ll; i <= rr; i++)
			if(!visit[temp + i])
			{
				visit[temp + i] = true;
				pq.push(temp + i);
			}
	}
	return false;
}

int main(void)
{
	long long ans = 0;
	int lend, rend, minn, min_lend, min_rend;
	while(scanf("%d%d%d", &n, &ll, &rr) != EOF)
	{
		ans = 0;
		for(int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		if(!isok(n - 1, ll - 1, rr - 1))
		{
			printf("0\n");
			continue;
		}
		while(n != 1)
		{
			int i, tempsum;
			for(i = min(rr, n); i >= ll; i--)
				if(isok(n - i, ll - 1, rr - 1))
					break;
			min_lend = lend = 1;
			min_rend = rend = i;
			tempsum = 0;
			for(int ii = lend; ii <= rend; ii++)
				tempsum += a[ii];
			minn = tempsum;
			while(rend < n)
			{
				tempsum -= a[lend++];
				tempsum += a[++rend];
				if(tempsum < minn)
				{
					minn = tempsum;
					min_lend = lend;
					min_rend = rend;
				}
			}
			ans += minn;
			int id = 1;
			for(int ii = 1; ii <= n; ii++)
			{
				if(ii == min_lend)
				{
					a[id++] = minn;
					continue;
				}
				if((ii > min_lend) && (ii <= min_rend))
					continue;
				a[id++] = a[ii];
			}
			n = id - 1;
		}
		printf("%lld\n", ans);
	}
	return 0;
}

#include<cstdio>
#include<string>
#include<iostream>
#include<cstring>
#include<cmath>
#include<set>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
using namespace std;
int n,m;
const int INF = 50000000 + 10;
int a[55][55],instack[55],cnt[55];
double b[55][55],d[55];
stack<int> s;
set<int> myset;
bool SPFA(void)
{
	while(!s.empty())
		s.pop();
	myset.clear();
	for(int i = 1;i <= n;i++)
	{
		d[i] = INF;
		instack[i] = false;
		myset.insert(i);
		cnt[i] = 0;
	}
	bool flag = false;//whther there exsits a negative circle
	int x = 1;
	while(!flag)
	{
		d[x] = 0;
		instack[x] = true;
		cnt[x]++;
		myset.erase(x);
		s.push(x);
		while(!s.empty())
		{
			int u = s.top();
			s.pop();
			instack[u] = false;
			for(int to = 1;to <= n;to++)
			{
				if(!(fabs(b[u][to] + INF < 0.01)) && d[u] + b[u][to] < d[to])
				{
					myset.erase(to);
					d[to] = d[u] + b[u][to];
					if(!instack[to])
					{
						instack[to] = true;
						cnt[to]++;
						s.push(to);
					}
					if(cnt[to] >= n)
					{
						flag = true;
						break;
					}
				}
			}
			if(flag)
				break;
		}
		if(!flag)
		{
			if(myset.empty())
				break;
			for(int i = 1;i <= n;i++)
			{
				d[i] = INF;
				instack[i] = 0;
				cnt[i] = 0;
			}
			x = *myset.begin();
		}
	}
	return flag;
}

bool judge(double x)
{
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= n ;j++)
		{
			if(a[i][j] == -1)
				b[i][j] = -INF;
			else
			{
				b[i][j] = (double)a[i][j] - x;
			}
		}
	}
	return SPFA();
}

int main(void)
{
	int u,v,w,T,minn,maxx;
	double mid;
	scanf("%d",&T);
	for(int ii = 1;ii <= T;ii++)
	{
		memset(a,-1,sizeof(a));
		scanf("%d%d",&n,&m);
		for(int i = 0;i < m;i++)
		{
			scanf("%d%d%d",&u,&v,&w);
			a[u][v] = w;
			minn = min(minn,w);
			maxx = max(maxx,w);
		}
		double ll = minn;
		double rr = maxx + 1;
		if(!judge(rr))
		{
			printf("Case #%d: No cycle found.\n",ii);
			continue;
		}
		while(rr - ll > 0.001)
		{
			mid = (ll + rr) / 2;
			if(judge(mid))
				rr = mid;
			else
				ll = mid;
		}
		printf("Case #%d: %.2lf\n",ii,mid);

	}
	
	
	return 0;
}

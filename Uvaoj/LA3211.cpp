#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
const int maxn = 4000 + 10;
vector<int> G[maxn];
int n,a[maxn],b[maxn];
bool mark[maxn];
stack<int> S;
void add_edge(int x,int flag_x,int y,int flag_y)
{
	int from = (x << 1) + flag_x;
	int to = (y << 1) + flag_y;
	G[from].push_back(to);
}

bool dfs(int x)
{
	if(mark[x ^ 1])
		return false;
	if(mark[x])
		return true;
	mark[x] = true;
	S.push(x);
	for(auto it:G[x])
		if(!dfs(it))
			return false;
	return true;
}

bool solve(int x)
{
	for(int i = 0; i < n;i++)
	{
		for(int j = i + 1 ; j < n;j++)
		{
			if(abs(a[i] - a[j]) < x) 
			{
				add_edge(i,0,j,1);
				add_edge(j,0,i,1);
			}
			if(abs(b[i] - b[j]) < x)
			{
				add_edge(i,1,j,0);
				add_edge(j,1,i,0);
			}
			if(abs(a[i] - b[j]) < x) 
			{
				add_edge(i,0,j,0);
				add_edge(j,1,i,1);
			}
			if(abs(a[j] - b[i]) < x)
			{
				add_edge(i,1,j,1);
				add_edge(j,0,i,0);
			}
		}
	}
	/*
	{
		for(int i = 0 ; i < 2 * n;i++)
		{
			printf("%d: ",i);
			for(auto it:G[i])
				printf("%d ",it);
			printf("\n");
		}
	}
	*/
	for(int i = 0 ; i < n;i++)
	{
		if(!mark[i << 1] && !mark[i << 1 | 1])
		{
			if(!dfs(i << 1))
			{
				while(!S.empty())
				{
					int temp = S.top();
					mark[temp] =false;
					S.pop();
				}
				if(!dfs(i << 1 | 1))
					return false;
			}
		}
	}
	return true;
}
int main(void)
{
	int ll,rr,mid;
	while(scanf("%d",&n) != EOF)
	{
		for(int i = 0; i < n; i++)
		{
			scanf("%d%d",&a[i],&b[i]);
		}
		ll = 0;
		rr = 10000000;
		while(rr - ll > 1)
		{
			for(int i = 0 ; i < maxn; i++)
				G[i].clear();
			while(!S.empty())
				S.pop();
			memset(mark,0,sizeof(mark));
			mid = (ll + rr) >> 1;
			bool flag = solve(mid);
			if(flag)
				ll = mid;
			else
				rr = mid;
		}
		printf("%d\n",ll);
		//printf("The answer is %d.\n",solve(10));
	}
	return 0;
}

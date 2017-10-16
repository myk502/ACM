#include<cstdio>
#include<iostream>
#include<vector>
#include<cstring>
#include<string>
#include<climits>
#include<queue>
#include<algorithm>
using namespace std;
char input[200];
int origin[150],final[150],n,b[150];
int a[10],ans,inque[10];
vector<int> G[10];
queue<int> q;
bool visit[10];

bool isok(void)
{
	for(int i = 1; i <= 6;i++)
		G[i].clear();
	while(!q.empty())
		q.pop();
	memset(inque,0,sizeof(inque));
	for(int i = 1; i <= 6;i++)
	{
		if(a[i] != i)
		{
			G[i].push_back(a[i]);
			inque[a[i]]++;
		}
	}
	for(int i = 1; i <= 6;i++)
		if(inque[i] == 0)
			q.push(i);
	while(!q.empty())
	{
		int temp = q.front();
		q.pop();
		for(auto it:G[temp])
		{
			inque[it]--;
			if(inque[it] == 0)
				q.push(it);
		}
	}
	for(int i = 1; i <= 6;i++)
		if(inque[i] != 0)
			return false;
	return true;
}
int solve(void)
{
	int cnt = 0;
	for(int i = 1; i <= 6;i++)
		if(a[i] != i)
			cnt++;
	for(int i = 1; i <= n;i++)
	{
		b[i] = a[origin[i]];
		if(b[i] != final[i])
			cnt++;
	}
	if(!isok())
		return INT_MAX;//not a DAG
	/*
	if(cnt == 15)
	{
		for(int i = 1; i <= 6;i++)
			printf("%d",a[i]);
		printf("\n");
	}
	*/
	return cnt;

}
void dfs(int pos)
{
	if(pos == 6)
	{
		for(int i = 1; i <= 6;i++)
		{
			a[pos] = i;
			int temp = solve();
			if(temp < ans)
			{
				ans = temp;
			}
		}
		return;
	}
	for(int i = 1; i <= 6;i++)
	{
		a[pos] = i;
		dfs(pos + 1);
	}
}

int main(void)
{
	while(scanf("%s",input) != EOF)
	{
		ans = INT_MAX;
		n = strlen(input);
		for(int i = 1; i <= n;i++)
			final[i] = input[i - 1] - '0';
		scanf("%s",input);
		for(int i = 1; i <= n;i++)
			origin[i] = input[i - 1] - '0';
		dfs(1);
		printf("%d\n",ans);
	}
	return 0;
}

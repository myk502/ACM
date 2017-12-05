#include<bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 10;
int T, n, m, a[maxn];
int ans1, ans2, num[maxn];
queue<int> q;
bool inque[maxn];
int main(void)
{
	scanf("%d", &T);
	while(T--)
	{
		ans1 = 0;
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		memset(num, 0, sizeof(num));
		memset(inque, 0, sizeof(inque));
		while(!q.empty())
			q.pop();
		for(int i = 1; i <= n; i++)
		{
			if(num[a[i]] == 0)
				ans1++;
			num[a[i]]++;
		}
		for(ans2 = m; ans2 >= 1; ans2--)
		{
			bool flag = true;
			int cnt = 0;
			while(!q.empty())
				q.pop();
			memset(inque, 0, sizeof(inque));
			for(int i = 1; i <= ans2; i++)
				q.push(-1);
			for(int i = 1; i <= n; i++)
			{
				if(inque[a[i]])
					continue;
				int temp = q.front();
				inque[temp] = false;
				q.pop();
				q.push(a[i]);
				inque[a[i]] = true;
				cnt++;
				if(cnt > ans1)
				{
					flag = false;
					break;
				}
			}
			if(!flag)
			{
				printf("%d %d\n", ans1, ans2 + 1);
				break;
			}
		}
	}
	return 0;
}

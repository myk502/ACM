#include<bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 10;
queue<int> q;
bool inque[maxn];
int num[maxn];
int n, m, a[maxn];
int main(void)
{
	int T, ans1, ans2;
	scanf("%d", &T);
	while(T--)
	{
		ans1 = ans2 = 0;
		while(!q.empty())
			q.pop();
		memset(inque, 0, sizeof(inque));
		memset(num, 0, sizeof(num));
		scanf("%d%d", &n, &m);
		for(int i =1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			if(num[a[i]] == 0)
				ans1++;
			num[a[i]]++;
		}
		for(int i = 1; i <= n; i++)
		{
			int xx = a[i];
			num[xx]--;
			if(inque[xx])
				continue;
			if(q.empty())
			{
				ans2++;
				q.push(xx);
				inque[xx] = true;
				continue;
			}
			int yy = q.front();
			if(num[yy] == 0)
			{
				inque[yy] = false;
				inque[xx] = true;
				q.pop();
				q.push(yy);
			}
			else
			{
				ans2++;
				q.push(xx);
				inque[xx] = true;
			}
		}
		printf("%d %d\n", ans1, ans2);
	}
	return 0;
}

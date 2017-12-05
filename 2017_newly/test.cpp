#include<cstdio>
using namespace std;
const int maxn = 10000 + 10;
int n, L, R, t, pos[maxn];
int main()
{
	int T, speed, cnt;
	scanf("%d", &T);
	while(T--)
	{
		cnt = 0;
		scanf("%d%d%d%d", &n, &L, &R, &t);
		for(int i = 1; i <= n; i++)
			scanf("%d", &pos[i]);
		for(int i = 1; i <= n; i++)
		{
			scanf("%d", &speed);
			pos[i] = pos[i] + speed * t;
		}
		for(int i = 1; i <= n; i++)
			if(pos[i] >= L && pos[i] <= R)
				cnt++;
		printf("%d\n", cnt);
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;

int n,a[100],b[100];
bool visit[100];

void dfs(int x)
{
	if(x == n)
	{
		for(int i = 1; i <= n;i++)
		{
			if(!visit[i])
			{
				a[x] = i;
				visit[i]=true;
				for(int i = 1; i <= n;i++)
					printf("%d ",a[i]);
				printf("   ");
				int cnt = 0;
				for(int i = 1; i <= n;i++)
					for(int j = i + 1;j <=n;j++)
						if(a[i] > a[j])
							cnt++;
				printf("%d     ",cnt);
				for(int i = 1;i <= n;i++)
					printf("%d ",b[i] = a[a[i]]);
				cnt = 0;
				for(int i = 1; i <= n;i++)
					for(int j = i + 1;j <=n;j++)
						if(b[i] > b[j])
							cnt++;
				printf("    %d ",cnt);
				printf("\n");
				visit[i] = false;
			}
		}
		return ;
	}
	for(int i = 1;i <= n;i++)
	{
		if(!visit[i])
		{
			a[x] = i;
			visit[i] = true;
			dfs(x + 1);
			visit[i] = false;
		}
	}
}

int main(void)
{
	while(scanf("%d",&n) != EOF)
	{
		for(int i = 1; i <= n ;i++)
			a[i] = i;
		memset(visit,0,sizeof(visit));
		dfs(1);

	}
	return 0;
}

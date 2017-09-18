#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>
using namespace std;
const int maxn= 1000 + 10;
int a[maxn][maxn],num[maxn][maxn],ans[maxn*maxn],id[maxn][maxn];
int cnt;
const int dx[]={-1,1,0,0};
const int dy[]={0,0,-1,1};
char input[maxn];
int n,m,k;
bool iseligble(int x,int y)
{
	if(x<1)
		return false;
	if(x>n)
		return false;
	if(y<1)
		return false;
	if(y>m)
		return false;
	return true;
}

void dfs(int x, int y,int idx)
{
	//printf("x=%d,y=%d,id=%d\n",x,y,idx);
	int xx,yy;
	id[x][y] = idx;
	for(int k = 0; k < 4;k++)
	{
		xx = x + dx[k];
		yy = y + dy[k];
		if(!iseligble(xx,yy))
			continue;
		if(!a[xx][yy])
			continue;
		if(id[xx][yy]!=-1)
		{
			continue;
		}
		dfs(xx,yy,idx);
	}
}

int main(void)
{
	int xx,yy;
	memset(num,0,sizeof(num));
	memset(ans,0,sizeof(ans));
	memset(id,-1,sizeof(id));
	scanf("%d%d%d",&n,&m,&k);
	for(int i = 1;i <= n;i++)
	{
		scanf("%s",input);
		for(int j = 1; j <= m; j++)
		{
			if( input[j-1] == '.')
				a[i][j] = 1;
			else
				a[i][j] = 0;
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			if(!a[i][j])
				continue;
			int xx,yy;
			for(int k=0;k<4;k++)
			{
				xx = i + dx[k];
				yy = j + dy[k];
				if(!iseligble(xx,yy))
					continue;
				if(!a[xx][yy])
					num[i][j]++;
			}
		}
	cnt = 0;
	for(int i = 1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			if(a[i][j] && (id[i][j] == -1))
				dfs(i,j,cnt++);
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			if(!a[i][j])
				continue;
			ans[id[i][j]]+=num[i][j];
		}
	for(int i=0;i<k;i++)
	{
		scanf("%d%d",&xx,&yy);
		printf("%d\n",ans[id[xx][yy]]);
	}

	return 0;
}

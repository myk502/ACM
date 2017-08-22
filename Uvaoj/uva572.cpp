#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int a[110][110],n,m,id[110][110],cnt;
char input[110];
const int dx[]={-1,1,0,0,-1,-1,1,1};
const int dy[]={0,0,-1,1,-1,1,-1,1};
bool iseligble(int x,int y)
{
	return ((x>=1) && (x<=n) && (y>=1) && (y<=m));
}
void dfs(int x,int y,int idd)
{
	if(!iseligble(x,y))
		return ;
	if(id[x][y]!=-1)
		return ;
	if(a[x][y]==0)
		return ;
	id[x][y]=idd;
	for(int dir=0;dir<8;dir++)
	{
		int xx=x+dx[dir];
		int yy=y+dy[dir];
		dfs(xx,yy,id[x][y]);
	}

}
int main(void)
{
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		if(n==0)
			break;
		for(int i=1;i<=n;i++)
		{
			scanf("%s",input);
			for(int j=1;j<=m;j++)
			{
				if(input[j-1]=='*')
					a[i][j]=0;
				else
					a[i][j]=1;
			}
		}
		memset(id,-1,sizeof(id));
		cnt=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
			{
				if((id[i][j]==-1) && (a[i][j]==1) )
				{
					dfs(i,j,cnt);
					cnt++;
				}
			}
		printf("%d\n",cnt);
	}
	return 0;
}

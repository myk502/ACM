#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<climits>
#include<cmath>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;
const int dx[] = {-1,1,0,0};
const int dy[] = {0,0,-1,1};
struct Point
{
	int x,y;
	Point(int x=-1,int y=-1):x(x),y(y)
	{

	}
};
const int maxn = 1000+10;
int a[maxn][maxn],fire[maxn][maxn];
int n,m,start_x,start_y;
int visit[maxn][maxn];
queue<Point> q;
bool iseligble(int x,int y)
{
	return (x>=1 && x<=n && y>=1 && y<=m);
}
char input[1010];
int main(void)
{
	int T;
	scanf("%d",&T);
	for(int ii = 1;ii <= T;ii++)
	{
		while(!q.empty())
			q.pop();
		scanf("%d%d",&n,&m);
		for(int i = 1;i <= n;i++)
			for(int j = 1;j <= m;j++)
			{
				fire[i][j] = INT_MAX;
				visit[i][j] = -1;
			}
		for(int i = 1;i <= n;i++)
		{
			scanf("%s",input);
			for(int j = 0;j<m;j++)
			{
				if(input[j] == '#')
					a[i][j+1] = 0;//a wall
				if(input[j] == '.')
					a[i][j+1] = 1;
				if(input[j] == 'J')
				{
					a[i][j+1] = 1;
					start_x = i;
					start_y = j+1;
				}
				if(input[j] == 'F')
				{
					a[i][j+1] = 1;
					fire[i][j+1] = 0;
					q.push(Point(i,j+1));
				}
			}
		}
		while(!q.empty())
		{
			int xx,yy,xxx,yyy;
			Point temp = q.front();
			q.pop();
			xx = temp.x;
			yy = temp.y;
			for(int k = 0 ;k < 4;k++)
			{
				xxx = xx + dx[k];
				yyy = yy + dy[k];
				if(iseligble(xxx,yyy)  && (a[xxx][yyy] == 1))
				{
					if(fire[xxx][yyy] > fire[xx][yy] + 1)
					{
						fire[xxx][yyy] = fire[xx][yy] + 1;
						q.push(Point(xxx,yyy));
					}
				}
			}
		}
		q.push(Point(start_x,start_y));
		visit[start_x][start_y] = 1;
		int ans = -1;
		while(!q.empty())
		{
			int xx,yy,xxx,yyy;
			Point temp = q.front();
			q.pop();
			xx = temp.x;
			yy = temp.y;
			for(int k = 0;k < 4;k++)
			{
				xxx = xx + dx[k];
				yyy = yy + dy[k];
				if(!iseligble(xxx,yyy))
				{
					ans = visit[xx][yy];
					goto endd;
				}
				if((a[xxx][yyy] == 1) && (visit[xxx][yyy] == -1) && (fire[xxx][yyy] > visit[xx][yy]))
				{
					visit[xxx][yyy] = visit[xx][yy] + 1;
					q.push(Point(xxx,yyy));
				}
			}
		}
endd:
		if(ans == -1)
			printf("IMPOSSIBLE\n");
		else
			printf("%d\n",ans);

	}
	return 0;
}

#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<limits.h>
#include<queue>
using namespace std;
struct myk{
	int x;
	int y;
	int t;
};
const int dx[]={-1,1,0,0},dy[]={0,0,-1,1};
char a[110][110],b[110][110][11];
int visit[110][110][11],step[110][110][11];
int n,m,xx,yy,tt,temp_x,temp_y,temp_t,k,start_x,start_y,end_x,end_y;
myk temp;
queue <myk> q;
void duru(void)
{
    scanf("%d%d%d",&n,&m,&k);
    scanf("\n");
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            scanf("\n");
            scanf("%c",&a[i][j]);
            if(a[i][j]=='Y')
            {
                start_x=i;
                start_y=j;
            }
            if(a[i][j]=='G')
            {
                end_x=i;
                end_y=j;
            }
        }

    }
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
    {
        if(a[i][j]=='#')
            b[i][j][0]='.';
        for(int jishu=1;jishu<k;jishu++)
            b[i][j][jishu]=a[i][j];
    }
}
bool panduan(int aa,int bb)
{
	if((aa>=1)&&(aa<=n)&&(bb>=1)&&(bb<=m))
		return true;
	else
		return false;
}
void initialization(void)
{
	while(!q.empty())
		q.pop();
	memset(step,-1,sizeof(step));
	memset(visit,0,sizeof(visit));
	temp.x=start_x;
	temp.y=start_y;
	temp.t=0;
	q.push(temp);
	visit[temp.x][temp.y][0]=1;
	step[temp.x][temp.y][0]=0;
}
void push(int xx,int yy,int tt)
{
	temp.x=xx;
	temp.y=yy;
	temp.t=tt;
	q.push(temp);
	step[xx][yy][tt]=1+step[temp_x][temp_y][temp_t];
	visit[xx][yy][tt]=1;
}
void bfs(void)
{
	while(!q.empty())
	{
		temp=q.front();
		temp_x=temp.x;
		temp_y=temp.y;
		temp_t=temp.t;
		q.pop();
		for(int i=0;i<4;i++)
		{
			xx=temp_x+dx[i];
			yy=temp_y+dy[i];
			tt=(temp_t+1)%k;
			if((panduan(xx,yy))&&(!visit[xx][yy][tt])&&(b[xx][yy][tt]!='#'))
				push(xx,yy,tt);
		}
	}
}
int main(void)
{
	int status,minn,t;
	scanf("%d",&t);
	while(t--)
	{
		memset(b,-1,sizeof(b));
		duru();
/*
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
                printf("%c",a[i][j]);
            printf("\n");
        }
*/
		initialization();
		bfs();
		status=0;
		minn=INT_MAX;
		for(int i=0;i<k;i++)
			if(step[end_x][end_y][i]>0)
			{
				status=1;
				minn=min(minn,step[end_x][end_y][i]);
			}
		if(status==0)
			printf("Please give me another chance!\n");
		else
			printf("%d\n",minn);
	}
	return 0;
}

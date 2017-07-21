#include<stdio.h>
#include<string.h>
#include<queue>
#include<algorithm>
using namespace std;

const int dx[]={-1,1,0,0},dy[]={0,0,-1,1};
struct myk{
int x;
int y;};
myk temp;
int time[25][25],visit[25][25];
char a[25][25];
int temp_time,temp_x,temp_y,m,n,start_x,start_y,end_x,end_y,xx,yy,xxx,yyy;
queue <myk> q;
bool panduan(int aa,int bb)
{
	if((aa>=1)&&(aa<=n)&&(bb>=1)&&(bb<=m))
		return true;
	else
		return false;
}
void duru(void)
 {

 	for(int i=1;i<=n;i++)
 	for(int j=1;j<=m;j++)
 	{
 		scanf("\n");
 		scanf("%c",&a[i][j]);
 		if(a[i][j]=='S')
 		{
 			start_x=i;
 			start_y=j;
		}
		if(a[i][j]=='T')
		{
			end_x=i;
			end_y=j;
		}
    }
 }
 void initialization(void)
 {
 	while(!q.empty())
 		q.pop();
 	memset(visit,0,sizeof(visit));
 	memset(time,0,sizeof(time));
 	temp.x=start_x;
 	temp.y=start_y;

 	q.push(temp);
 	visit[start_x][start_y]=1;
 }
void push(int xx,int yy)
{
	temp.x=xx;
	temp.y=yy;
	q.push(temp);
	visit[xx][yy]=1;
	time[xx][yy]=1+time[temp_x][temp_y];
	//printf("From (%d,%d) to (%d,%d),now time is %d\n",temp_x,temp_y,xx,yy,time[xx][yy]);
}
void push2(int xx,int yy,int status)
{
    temp.x=xx;
	temp.y=yy;
	q.push(temp);
	visit[xx][yy]=1;
	time[xx][yy]=status+1+time[temp_x][temp_y];
	//printf("From (%d,%d) to (%d,%d),now time is %d,status=%d\n",temp_x,temp_y,xx,yy,time[xx][yy],status);
}
void bfs(void)
{
    int status=0;
    char temp_fangxiang;
 	while(!q.empty())
 	{
 		temp=q.front();
 		temp_x=temp.x;
 		temp_y=temp.y;
 		temp_time=time[temp_x][temp_y];
 		q.pop();
 		for(int i=0;i<4;i++)
 		{
 			xx=dx[i]+temp_x;
 			yy=dy[i]+temp_y;
 			if((a[xx][yy]!='-')&&(a[xx][yy]!='|'))
            {
                if((panduan(xx,yy))&&(!visit[xx][yy])&&(a[xx][yy]!='*'))
                    push(xx,yy);
                if((xx==end_x)&&(yy==end_y))
                    return ;
            }
            else
            {
                //printf("Now temp_time=%d\n",temp_time);
                if((temp_time%2==0))
                    temp_fangxiang=a[xx][yy];
                else
                {
                    if(a[xx][yy]=='-')
                        temp_fangxiang='|';
                    else
                        temp_fangxiang='-';
                }

                if((temp_fangxiang=='-')&&(i<2))
                {
                    status=1;
                    temp_fangxiang='|';
                }
                else
                {
                    if((temp_fangxiang=='|')&&(i>1))
                    {
                        status=1;
                        temp_fangxiang='-';
                    }
                    else
                        status=0;
                }
                xxx=xx+dx[i];
                yyy=yy+dy[i];
                if((panduan(xxx,yyy))&&(!visit[xxx][yyy])&&(a[xxx][yyy]!='*'))
                   push2(xxx,yyy,status);
                if((xxx==end_x)&&(yyy==end_y))
                    return ;
            }

	    }

	}
}

int main(void)
 {
 	while((scanf("%d%d",&n,&m)!=EOF))
 	{

 		duru();
 		initialization();
 		bfs();

 		printf("%d\n",time[end_x][end_y]);
	}
	return 0;
 }

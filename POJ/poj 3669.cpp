#include<stdio.h>
#include<iostream>
#include<string.h>
#include<string>
#include<queue>
#include<math.h>
#include<algorithm>
using namespace std;
struct myk{
int x;
int y;
int time;};
myk storm[50000+10];
queue <myk> q;
const int dx[]={-1,1,0,0};
const int dy[]={0,0,-1,1};
int ans=-1,max_time=-1,m,b[1010][1010],visit[1010][1010];//b[x][y][t] stands for whether coordinate (x,y) is safe at time t
//max_time stands for the greatest time of storm hit(after which there will be no more storm hit)
bool iseligble(int x,int y)
{
    if((x>=0)&&(y>=0)&&(x<=1010)&&(y<=1010))
        return true;
    else
        return false;
}
void push(int xx,int yy,int tt)
{
    myk temp;
    temp.x=xx;
    temp.y=yy;
    temp.time=tt;
    q.push(temp);
    visit[xx][yy]=1;
}
bool issafe(int x,int y)
{
    if(b[x][y]==10000)
        return true;
    else
        return false;
}

void bfs(void)
{
    int x_now,y_now,t_now,xx,yy,tt;
    myk temp;
    while(!q.empty())
    {
        temp=q.front();
        x_now=temp.x;
        y_now=temp.y;
        t_now=temp.time;
        q.pop();
        //printf("(%d,%d):%d\n",x_now,y_now,t_now);
        for(int i=0;i<4;i++)
        {
            xx=x_now+dx[i];
            yy=y_now+dy[i];
            tt=t_now+1;


            if((iseligble(xx,yy))&&((b[xx][yy]>tt))&&(!visit[xx][yy]))
            {
                //step[xx][yy]=tt;
                if((issafe(xx,yy)))
                {
                    ans=tt;
                    return ;

                }
                push(xx,yy,tt);
            }
        }
    }
}

int main(void)
{
    int xx,yy,tt;
    cin>>m;
    //memset(b,-1,sizeof(b));
    memset(visit,0,sizeof(visit));
    //memset(step,-1,sizeof(step));
    for(int i=0;i<1010;i++)
        for(int j=0;j<1010;j++)
            b[i][j]=10000;
    //printf("b[0][1]=%d\nb[1][0]=%d\n",b[0][1],b[1][0]);
    for(int i=0;i<m;i++)
    {
        scanf("%d%d%d",&storm[i].x,&storm[i].y,&storm[i].time);
        max_time=max(max_time,storm[i].time);
        b[storm[i].x][storm[i].y]=min(storm[i].time,b[storm[i].x][storm[i].y]);
        //printf("1:b[0][1]=%d\nb[1][0]=%d\n",b[0][1],b[1][0]);
        for(int j=0;j<4;j++)
        {
            xx=storm[i].x+dx[j];
            yy=storm[i].y+dy[j];
            tt=storm[i].time;
            if(iseligble(xx,yy))
                b[xx][yy]=min(b[xx][yy],tt);
            //printf("2:b[0][1]=%d\nb[1][0]=%d\n",b[0][1],b[1][0]);
        }

    }
    //printf("b[0][1]=%d\nb[1][0]=%d\n",b[0][1],b[1][0]);
    if(issafe(0,0))
        printf("0\n");
    else
    {
        if(b[0][0]==0)
            printf("-1\n");
        else
        {
            push(0,0,0);
            //visit[0][0]=0;
            bfs();
            printf("%d\n",ans);
        }

    }
    //step[0][0]=0;

    return 0;
}

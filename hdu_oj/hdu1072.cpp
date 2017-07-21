#include<stdio.h>
#include<string.h>
#include<queue>
#include<algorithm>
using namespace std;
struct myk{
int x;
int y;};
const int dx[]={-1,1,0,0},dy[]={0,0,-1,1};
int visit[10][10],step[10][10],time[10][10],a[10][10];
int xx,yy,n,t,m,qishi_x,qishi_y,jieshu_x,jieshu_y;
myk temp,temp_jieshu;
queue <myk> q;
void initialization(void)
{
    memset(step,-1,sizeof(step));
    memset(visit,0,sizeof(visit));
    step[qishi_x][qishi_y]=0;
    visit[qishi_x][qishi_y]=1;
    temp.x=qishi_x;
    temp.y=qishi_y;
    q.push(temp);
}
bool panduan(int aa,int bb)
{
    if((aa>=1)&&(aa<=n)&&(bb>=1)&&(bb<=m))
        return true;
    else
        return false;
}
void push(int xx,int yy)
{
    myk tempn;
    tempn.x=xx;
    tempn.y=yy;
    q.push(tempn);
    visit[xx][yy]=1;
    step[xx][yy]=1+step[temp.x][temp.y];
    time[xx][yy]=time[temp.x][temp.y]-1;
    if(a[xx][yy]==4)
        time[xx][yy]=6;
    //printf("From (%d,%d) to (%d,%d)\n",temp.x,temp.y,xx,yy);
}
void bfs(void)
{
    while(!q.empty())
    {
        temp=q.front();
        q.pop();
        if(time[temp.x][temp.y]<=1)
            continue;
        for(int i=0;i<4;i++)
        {
            xx=temp.x+dx[i];
            yy=temp.y+dy[i];
            if(panduan(xx,yy)&&(a[xx][yy]!=0))
                push(xx,yy);
            myk temp2;
            temp2=q.back();
            if((temp2.x==jieshu_x)&&(temp2.y==jieshu_y))
                return ;

        }




    }
}
int main(void)
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            scanf("%d",&a[i][j]);
            time[i][j]=6;
            if(a[i][j]==2)
            {
                qishi_x=i;
                qishi_y=j;
            }
            if(a[i][j]==3)
            {
                jieshu_x=i;
                jieshu_y=j;
            }
        }
        initialization();
        bfs();
        printf("%d\n",step[jieshu_x][jieshu_y]);
    }
}

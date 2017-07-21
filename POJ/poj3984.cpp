#include<stdio.h>
#include<string.h>
#include<limits.h>
#include<ctype.h>
#include<string>
#include<sstream>
#include<iostream>
#include<queue>
#include<math.h>
#include<algorithm>
using namespace std;
int a[6][6],visit[6][6],step[6][6];
const int dx[]={0,1};
const int dy[]={1,0};
struct myk{
int x;
int y;};
queue <myk> q;
myk pre[10][10];
myk temp;
void push(int xx,int yy)
{
    visit[xx][yy]=1;
    temp.x=xx;
    temp.y=yy;
    q.push(temp);
}
bool iseligble(int x,int y)
{
    if((x>=1)&&(x<=5)&&(y>=1)&&(y<=5)&&(a[x][y]==0))
        return true;
    else
        return false;
}
void bfs(void)
{
    int xx,yy,x_now,y_now;
    while(!q.empty())
    {
        temp=q.front();
        q.pop();
        x_now=temp.x;
        y_now=temp.y;
        for(int i=0;i<2;i++)
        {
            xx=x_now+dx[i];
            yy=y_now+dy[i];
            if((iseligble(xx,yy))&&(!visit[xx][yy]))
            {
                step[xx][yy]=1+step[x_now][y_now];
                pre[xx][yy].x=x_now;
                pre[xx][yy].y=y_now;
                //printf("(%d, %d)\n",xx-1,yy-1);
                if((xx==5)&&(yy==5))
                    return ;
                push(xx,yy);
            }
        }
    }
}
int main(void)
{
    int indexx=0;
    myk ans[10];
    for(int i=1;i<=5;i++)
        for(int j=1;j<=5;j++)
        cin>>a[i][j];
    memset(visit,0,sizeof(visit));
    memset(step,-1,sizeof(step));
    push(1,1);
    step[1][1]=0;
    //printf("(0, 0)\n");
    bfs();
    int i=5,j=5;
    while(i*j!=1)
    {
        ans[indexx].x=i;
        ans[indexx].y=j;
        indexx++;
        int tempp=i;
        i=pre[i][j].x;
        j=pre[tempp][j].y;
    }
    ans[indexx].x=ans[indexx].y=1;
    for(int i=indexx;i>=0;i--)
        printf("(%d, %d)\n",ans[i].x-1,ans[i].y-1);
    return 0;
}

#include<stdio.h>
#include<queue>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
int t,n,start_x,start_y,end_x,end_y,visit[310][310],step[310][310];
struct myk{
int x;
int y;};
const int dx[]={-2,-1,1,2,2,1,-1,-2};
const int dy[]={1,2,2,1,-1,-2,-2,-1};
queue <myk> q;
bool iseligble(int x,int y)
{
    if((x>=1)&&(x<=n)&&(y>=1)&&(y<=n))
        return true;
    else
        return false;
}
void push(int xx,int yy)
{
    myk temp;
    temp.x=xx;
    temp.y=yy;
    q.push(temp);
    visit[xx][yy]=1;
}
void bfs(void)
{
    int xx,yy,x_now,y_now;
    myk temp;
    while(!q.empty())
    {
        temp=q.front();
        q.pop();
        x_now=temp.x;
        y_now=temp.y;
        for(int i=0;i<8;i++)
        {
            xx=x_now+dx[i];
            yy=y_now+dy[i];
            if((iseligble(xx,yy))&&(!visit[xx][yy]))
            {
                step[xx][yy]=1+step[x_now][y_now];
                if((xx==end_x)&&(yy==end_y))
                    return ;
                push(xx,yy);
            }
        }
    }
}
int main(void)
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        cin>>start_x>>start_y>>end_x>>end_y;
        start_x++;start_y++;end_x++;end_y++;
        memset(step,-1,sizeof(step));
        memset(visit,0,sizeof(visit));
        while(!q.empty())
            q.pop();
        push(start_x,start_y);
        step[start_x][start_y]=0;
        if((start_x!=end_x)||(start_y!=end_y))
            bfs();
        printf("%d\n",step[end_x][end_y]);

    }
    return 0;
}

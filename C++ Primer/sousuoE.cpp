#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<string>
#include<sstream>
#include<iostream>
#include<queue>
#include<math.h>
#include<algorithm>
using namespace std;
const int dx[]={-1,1,0,0};
const int dy[]={0,0,-1,1};
int a[25][25];
char temp_char;
int ans,n,m,start_x,start_y;
int visit[25][25];
struct myk{
int x;
int y;};
queue <myk> q;
bool iseligble(int x,int y)
{
    if((x>=1)&&(x<=n)&&(y>=1)&&(y<=m))
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
    while(!q.empty())
    {
        myk temp=q.front();
        x_now=temp.x;
        y_now=temp.y;
        q.pop();
        for(int i=0;i<4;i++)
        {
            xx=x_now+dx[i];
            yy=y_now+dy[i];
            if((iseligble(xx,yy))&&(a[xx][yy]==0)&&!visit[xx][yy])
                push(xx,yy);
        }
    }
}
int main(void)
{

    while(cin>>m>>n)
    {
        ans=0;
        while(!q.empty())
            q.pop();
        if((n==0)&&(m==0))
            break;
        memset(visit,0,sizeof(visit));
        string temp;
        for(int i=1;i<=n;i++)
        {
            cin>>temp;
            stringstream ss(temp);
            for(int j=1;j<=m;j++)
            {
                ss>>temp_char;
                switch(temp_char)
                {
                    case '.':a[i][j]=0;
                             break;
                    case '#':a[i][j]=1;
                             break;
                    case '@':a[i][j]=2;
                             start_x=i;
                             start_y=j;
                             break;
                }
            }

        }
        push(start_x,start_y);
        bfs();
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
            {
                if(visit[i][j]!=0)
                    ans++;
            }
            cout<<ans<<endl;


    }


    return 0;
}

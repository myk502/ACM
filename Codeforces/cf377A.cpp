#include<stdio.h>
#include<string.h>
#include<string>
#include<iostream>
#include<sstream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
const int dx[]={-1,1,0,0};
const int dy[]={0,0,-1,1};
struct Point
{
    int x;
    int y;
    Point()
    {
        x=y=0;
    }
    Point(int a,int b)
    {
        x=a;
        y=b;
    }
};
int flag=0,n,m,k,a[510][510],visit[510][510],start_x,start_y,num_wall,num_empty,num_emptyrequired;
Point pre[510][510];
int ans_x,ans_y;
string input;

char temp;
bool iseligble(int x,int y)
{
    if((x>=1)&&(x<=n)&&(y>=1)&&(y<=m))
        return true;
    else
        return false;
}
void dfs(int step,int x,int y)
{
    if(flag==1)
        return ;
    int xx,yy;
    visit[x][y]=1;

    a[x][y]=2;
    //printf("Now step is %d and x=%d and y=%d\n",step,x,y);
    if(step==num_emptyrequired)
    {
        flag=1;
        return ;
    }
    for(int i=0;i<4;i++)
    {
        xx=x+dx[i];
        yy=y+dy[i];
        if((iseligble(xx,yy))&&!visit[xx][yy]&&(a[xx][yy]==1))
        {
            dfs(step+1,xx,yy);
            if(flag==0)
            {
                visit[xx][yy]=0;
                a[xx][yy]=1;
            }
            else
                return ;
        }
    }
}

int main(void)
{
    cin>>n>>m>>k;
    num_wall=num_empty=0;
    memset(a,-1,sizeof(a));
    memset(visit,0,sizeof(visit));
    //memset(step,-1,sizeof(step));
    for(int i=1;i<=n;i++)
    {
        cin>>input;
        stringstream ss(input);
        for(int j=1;j<=m;j++)
        {
            ss>>temp;
            if(temp=='.')
            {
                a[i][j]=1;
                start_x=i;
                start_y=j;
                num_empty++;
            }
            else
            {
                a[i][j]=0;
                num_wall++;
            }
        }
    }
    num_emptyrequired=num_empty-k;
    //printf("require %d empty\n",num_emptyrequired);
    dfs(1,start_x,start_y);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i][j]==0)
                printf("#");
            if(a[i][j]==1)
                printf("X");
            if(a[i][j]==2)
                printf(".");
        }
        printf("\n");
    }

    return 0;
}

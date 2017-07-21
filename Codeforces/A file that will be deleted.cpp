#include<bits/stdc++.h>
using namespace std;
int t,r,c,k,x_start,y_start,x_end,y_end;
const int dx[]={-1,1,0,0};
const int dy[]={0,0,-1,1};
int a[110][100],b[110][110][15],visit[110][110][15],step[110][110][15];
char temp[110];
struct myk
{
    int x;
    int y;
    int t;
    myk(int xx,int yy,int tt)
    {
        x=xx;
        y=yy;
        t=tt;
    }
};
queue<myk> q;
bool iseligble(int x,int y)
{
    if((x>=1)&&(x<=r)&&(y>=1)&&(y<=c))
        return true;
    else
        return false;
}
void push(int x,int y,int t)
{
    //printf("Now come to(%d,%d) and time is %d\n",x,y,t);
    myk temp(x,y,t);
    visit[x][y][t]=1;
    q.push(temp);
}
void init(void)
{
    while(!q.empty())
            q.pop();
    for(int i=1;i<=r;i++)
    {
        for(int j=1;j<=c;j++)
        {
            for(int t=0;t<k;t++)
            {
                b[i][j][t]=a[i][j];
                if((t==0)&&(a[i][j]==0))
                    b[i][j][t]=1;
            }
        }
    }
    memset(step,-1,sizeof(step));
    memset(visit,0,sizeof(visit));
    push(x_start,y_start,0);
    step[x_start][y_start][0]=0;
}
void bfs(void)
{
    int x_now,y_now,t_now,xx,yy,tt;
    while(!q.empty())
    {
        myk temp=q.front();
        q.pop();
        x_now=temp.x;
        y_now=temp.y;
        t_now=temp.t;
        for(int i=0;i<4;i++)
        {
            xx=x_now+dx[i];
            yy=y_now+dy[i];
            tt=(t_now+1)%k;
            if(iseligble(xx,yy)&&(!visit[xx][yy][tt])&&(b[xx][yy][tt]))
            {
                step[xx][yy][tt]=1+step[x_now][y_now][t_now];
                push(xx,yy,tt);
            }
            if((xx==x_end)&&(yy==y_end))
                return ;
        }
        /*
        {
            xx=x_now;
            yy=y_now;
            tt=(t_now+1)%k;
            if(iseligble(xx,yy)&&(!visit[xx][yy][tt])&&(b[xx][yy][tt]))
            {
                step[xx][yy][tt]=1+step[x_now][y_now][t_now];
                push(xx,yy,tt);
            }
            if((xx==x_end)&&(yy==y_end))
                return ;
        }
        */

    }
}
int main(void)
{
    int ans;
    cin>>t;
    while(t--)
    {
        cin>>r>>c>>k;
        for(int i=1;i<=r;i++)
        {
            scanf("%s",temp);
            for(int j=0;j<c;j++)
            {
                if(temp[j]=='.')
                    a[i][j+1]=1;
                if(temp[j]=='#')
                    a[i][j+1]=0;
                if(temp[j]=='Y')
                {
                    a[i][j+1]=1;
                    x_start=i;
                    y_start=j+1;
                }
                if(temp[j]=='G')
                {
                    a[i][j+1]=1;
                    x_end=i;
                    y_end=j+1;
                }
            }
        }

        //printf("(%d,%d) to (%d,%d)\n",x_start,y_start,x_end,y_end);
        init();
        bfs();
        ans=INT_MAX;
        for(int i=0;i<k;i++)
        {
            if(step[x_end][y_end][i]!=-1)
            {
                ans=min(ans,step[x_end][y_end][i]);
            }
        }
        if(ans==INT_MAX)
            printf("Please give me another chance!\n");
        else
            printf("%d\n",ans);


    }

    return 0;
}

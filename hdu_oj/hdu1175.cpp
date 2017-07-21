 #include<stdio.h>
#include<string.h>
#include<queue>
#include<algorithm>
#define zuida 1000
using namespace std;
int qq,n,m,a[zuida+10][zuida+10],x1,y1,x2,y2,visit[zuida+10][zuida+10][4],num[zuida+10][zuida+10][4];//num用来存储到这个位置转弯多少次
int xx,yy,tempn_x,tempn_y,tempn_fangxiang,status;
const int dx[]={-1,0,0,1};//上左右下
const int dy[]={0,-1,1,0};
struct myk{
int x;
int y;
int fangxiang;};//fangxiang是这一步要走的方向
myk temp,tempn;
queue <myk> q;
bool panduan(int aa,int bb)
{
    if((aa>=1)&&(aa<=n)&&(bb>=1)&&(bb<=m))
        return true;
    else
        return false;
}
void push(myk temp)
{
    q.push(temp);
    visit[temp.x][temp.y][temp.fangxiang]=1;
}
void initialization(void)
{
    while(!q.empty())
        q.pop();
    memset(num,0,sizeof(num));
    memset(visit,0,sizeof(visit));
    for(int i=0;i<4;i++)
    {
        visit[x1][y1][i]=1;
        xx=x1+dx[i];
        yy=y1+dy[i];
        if((xx=x2)&&(yy=y2))
        {
            status=1;
            return ;
        }
        if((panduan(xx,yy))&&(a[xx][yy]==0))
        {
            temp.x=xx;
            temp.y=yy;
            temp.fangxiang=i;
            push(temp);
        }
    }
}
void bfs(void)
{
    while(!q.empty())
    {
        tempn=q.front();
        q.pop();
        tempn_x=tempn.x;
        tempn_y=tempn.y;
        tempn_fangxiang=tempn.fangxiang;
        for(int i=0;i<4;i++)
        {
            xx=tempn_x+dx[i];
            yy=tempn_y+dy[i];
            if(panduan(xx,yy)&&!visit[xx][yy][i]&&!visit[xx][yy][3-i]&&(a[xx][yy]==0))
            {
                if((tempn_fangxiang)!=i)
                    num[xx][yy][i]=num[tempn_x][tempn_y][tempn_fangxiang]+1;
                else
                    num[xx][yy][i]=num[tempn_x][tempn_y][tempn_fangxiang];
                if(num[xx][yy][i]<2)
                {
                    temp.x=xx;
                    temp.y=yy;
                    temp.fangxiang=i;
                    push(temp);
                    if((xx==x2)&&(yy==y2))
                    {
                        status=1;
                        return ;
                    }
                }
                if(num[xx][yy][i]==2)
                {
                    int temp_xx=xx,temp_yy=yy;
                    while(panduan(temp_xx,temp_yy))
                    {
                        if((temp_xx==x2)&&(temp_yy==y2))
                        {
                            status=1;
                            return ;
                        }
                        temp_xx+=dx[i];
                        temp_yy+=dy[i];
                    }
                }

            }
        }
    }
}
int main(void)
{

    while(scanf("%d%d",&n,&m))
    {
        if(n*m==0)
            break;
        for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&a[i][j]);//从1开始编号
        scanf("%d",&qq);//询问次数
        for(int i=0;i<qq;i++)
        {
            status=0;
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            if((a[x1][y1]==a[x2][y2])&&(a[x1][y1]!=0))//如果两个棋子种类相同且不为0
            {
                initialization();
                if(!status)
                    bfs();
                if(status)
                    printf("YES\n");
                else
                    printf("NO\n");
            }
            else
            {
                printf("NO\n");
            }

        }
    }
    return 0;
}

#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<limits.h>
#include<math.h>
using namespace std;
const int dx[]={-1,1,0,0},dy[]={0,0,-1,1};
int m,n,start_x,start_y,end_x,end_y,xx,yy,minn,xxx,yyy;
int a[25][25];

bool panduan(int aa,int bb)
{
    if((aa>=1)&&(aa<=n)&&(bb>=1)&&(bb<=m))
        return true;
    else
        return false;
}
bool panduan2(int i,int x,int y)//判断能不能走并给出走到哪里,i是方向，xy是起始位置坐标
{
    xx=x+dx[i];
    yy=y+dy[i];
    if(panduan(xx,yy)&&(a[xx][yy]==3))//如果下一步就是结束点，直接return
        return true;
    if((!panduan(xx,yy))||(a[xx][yy]==1))//如果下一步越界或者下一步是障碍不能走
        return false;
    while(panduan(xx,yy)&&(a[xx][yy]!=1))//走到这里，说明下一步既不是终点，而且能走，找出最后的的停止点
    {
        xx=xx+dx[i];
        yy=yy+dy[i];
        if((a[xx][yy]==3))
            return true;
    }
    if(a[xx][yy]!=1)//假如xx，yy此时越界，而且这一格子正好是1，那就完蛋了。所以a要赋初值-1
        return false;
    xxx=xx;//保存这时候障碍物的位置xxx,yyy
    yyy=yy;
    xx-=dx[i];
    yy-=dy[i];
    return true;
}
void dfs(int step,int x,int y)
{
    int temp_xxx,temp_yyy;
    //printf("(%d,%d),step=%d\n",x,y,step);
    int temp_x,temp_y;
    if((step>=10)||((x==end_x)&&(y==end_y)))
        return ;
    for(int i=0;i<4;i++)
    {
        if(panduan2(i,x,y))
        {
            temp_x=xx;
            temp_y=yy;
            if((xx==end_x)&&(yy==end_y))
            {
                minn=min(step+1,minn);
                //printf("++\n");
            }

            a[xxx][yyy]=0;//更改状态
            temp_xxx=xxx;
            temp_yyy=yyy;//将这次dfs对应的block位置保存在这层递归中，防止被破坏
            dfs(step+1,xx,yy);
            a[temp_xxx][temp_yyy]=1;//回溯
        }
    }
}
void duru(void)
{
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
    {
        scanf("%d",&a[i][j]);
        if(a[i][j]==2)
        {
            start_x=i;
            start_y=j;
            a[i][j]=0;
        }
        if(a[i][j]==3)
        {
            end_x=i;
            end_y=j;

        }
    }
}
int main(void)
{
    while(1)
    {
        scanf("%d%d",&m,&n);
        memset(a,-1,sizeof(a));
        if(m*n==0)
            goto myk;
        duru();
        minn=INT_MAX;
        dfs(0,start_x,start_y);
        if(minn==INT_MAX)//走不到的情况
            minn=-1;
        printf("%d\n",minn);
    }
    myk:return 0;
}

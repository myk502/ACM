#include<iostream>
#include<math.h>
#include<stdio.h>
#include<algorithm>
using namespace std;

int sx,sy,ex,ey;
int n,m;
char map[10][10];
int flag,step;
int d[4][2]={0,1,1,0,0,-1,-1,0};
void dfs(int x,int y,int t)
{
    if(flag==1) return ;                                           //若找到所需解，则不用再找其余路径
    if(t<abs(ex-x)+abs(ey-y)||(t-abs(ex-x)+abs(ey-y))%2) return ;  //剪枝。若剩余时间-当前点到终点的横纵坐标之和，为偶数
                                                                   //则，该路，可走。（若无障碍，差值为0，若有障碍则绕道
                                                                   //即差值-1+(n*2+3)为偶数）
    else if(t==0)                //t代表剩余时间，每走一步t--，这里若t=0，则迷宫坍塌
    {
         if(x==ex&&y==ey)  {flag=1; return ;}    //若此时，t=0且刚好到达终点，则标记找到所需解。
         else { return ;  }
    }
    else
    for(int i=0;i<4;i++)                  //每次向4个方向探。
    {
            int nx=x+d[i][0],ny=y+d[i][1];
            if (nx>0&&nx<=n&&ny>0&&ny<=m&&(map[nx][ny]=='.'||map[nx][ny]=='D')) //若该点不为墙，则为可走
            {
                   map[nx][ny]='X';                    //标记走过
                   dfs( nx,ny,t-1) ;
                   map[nx][ny]='.';                   //回溯
            }

    }
    return ;
}
int main()
{


    char str[10];
    int t;
    while (scanf("%d%d%d",&n,&m,&t)!=EOF)
    {
          if(n==0&&m==0&&t==0) return 0;
          for (int i=1;i<=n;i++)
          {
              scanf("%s",str);
              for (int j=1;j<=m;j++)
              {
                  map[i][j]=str[j-1];
                  if(map[i][j]=='S')  sx=i,sy=j;
                  else if(map[i][j]=='D') ex=i,ey=j;
              }
          }
          flag=0;
          dfs(sx,sy,t);
          if(flag==0) printf("NO\n");
          else printf("YES\n");
    }
    return 0;
}

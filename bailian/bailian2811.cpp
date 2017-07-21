#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;
int a[7][7],b[7][7],beifen[7][7];
bool iseligble(int x,int y)
{
    if((x>=1)&&(x<=5)&&(y>=1)&&(y<=6))
        return true;
    else
        return false;
}
void put(int x,int y)
{
    if(iseligble(x,y))
        a[x][y]=1-a[x][y];
    if(iseligble(x-1,y))
        a[x-1][y]=1-a[x-1][y];
    if(iseligble(x+1,y))
        a[x+1][y]=1-a[x+1][y];
    if(iseligble(x,y-1))
        a[x][y-1]=1-a[x][y-1];
    if(iseligble(x,y+1))
        a[x][y+1]=1-a[x][y+1];
}
bool jiancha(void)
{
    int status=1;

    for(int i=1;i<=5;i++)
        for(int j=1;j<=6;j++)
            beifen[i][j]=a[i][j];
    for(int i=2;i<=5;i++)
        for(int j=1;j<=6;j++)
    {
        if(a[i-1][j]==1)
            put(i,j);
    }
    for(int i=1;i<=5;i++)
        for(int j=1;j<=6;j++)
        {
            if(a[i][j]==1)
            {
                status=0;
                //printf("a[%d][%d]=0\n",i,j);
            }
            //break;
        }
    for(int i=1;i<=5;i++)
        for(int j=1;j<=6;j++)
            a[i][j]=beifen[i][j];
    return status;
}
bool dfs(int x)
{
    if(jiancha())
        return true;
    if(x>=7)
        return false;
    {
        if(dfs(x+1))
            return true;
    }
    {
        put(1,x);
        b[1][x]=1;
        if(dfs(x+1))
            return true;
        b[1][x]=0;
        put(1,x);
    }
    return false;
    //return false;
}
int main(void)
{
    memset(b,0,sizeof(b));
    memset(a,0,sizeof(a));
    for(int i=1;i<=5;i++)
        for(int j=1;j<=6;j++)
    {
        cin>>a[i][j];
    }
    bool temp=dfs(1);
    /*
    {
        put(1,1);
        put(1,3);
        put(1,6);
        printf("%d\n",jiancha());
    }
    */
     for(int i=2;i<=5;i++)
        for(int j=1;j<=6;j++)
    {
        if(a[i-1][j]==1)
        {
            put(i,j);
            b[i][j]=1;
        }
    }
    for(int i=1;i<=5;i++)
    {
        for(int j=1;j<=6;j++)
            printf("%d ",b[i][j]);
        printf("\n");
    }
    return 0;
}

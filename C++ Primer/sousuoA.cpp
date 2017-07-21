#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int a[10][10],b[10][10],beifen[10][10];
int c[128][10];
int ans;

bool iseligble(int x,int y)
{
    if((x>=1)&&(x<=5)&&(y>=1)&&(y<=6))
        return true;
    else
        return false;
}

int mov[4][2]={1,0,0,1,-1,0,0,-1};
void put(int x,int y)
{
    a[x][y]=1-a[x][y];
    for(int i=0;i<4;i++)
    {
        int x1=x+mov[i][0];
        int y1=y+mov[i][1];
        if(iseligble(x1,y1))
        {
            a[x1][y1]=1-a[x1][y1];
        }
    }
}
bool jiancha(int d[])
{
    bool status=true;
//    if((b[1][1]==1)&&(b[1][2]==0)&&(b[1][3]==1)&&(b[1][4]==0)&&(b[1][5]==0)&&(b[1][6]==1))
//        printf("haha\n");
    for(int i=1;i<=5;i++)
        for(int j=1;j<=6;j++)
            beifen[i][j]=a[i][j];
    for(int i=1;i<=6;i++)
    {
        if(d[i]==1) put(1,i);
        cout<<d[i]<<"~";
    }
    cout<<endl;
//    for(int i=1;i<=5;i++)
//    {
//        for(int j=1;j<=6;j++)
//            cout<<a[i][j]<<" ";
//        cout<<endl;
//    }
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
                status=false;
                //printf("a[%d][%d]=0\n",i,j);
            }
            //break;
        }
//    for(int i=1;i<=5;i++)
//    {
//        for(int j=1;j<=6;j++)
//            cout<<a[i][j]<<"!";
//        cout<<endl;
//    }
//    cout<<"@"<<status<<endl;
    for(int i=1;i<=5;i++)
        for(int j=1;j<=6;j++)
            a[i][j]=beifen[i][j];
    return status;
}
//bool dfs(int x,int c[])
//{
//    if(jiancha())
//    {
//        for(int i=1;i<=6;i++)
//            b[1][i]=c[i];
//        return true;
//    }
//    if(x>=7)
//        return false;
//    if(dfs(x+1,c))
//        return true;
//    put(1,x);
//    c[x]=1;
//    if(dfs(x+1,c))
//        return true;
//    return false;
//}

void Dfs()
{
    memset(c,0,sizeof(c));
    for(int i=0;i<128;i++)
    {
        int cnt=0;
        int res=i;
        while(res>0)
        {
            c[i][cnt]=res%2;
            res/=2;
            cnt++;
        }
        if(jiancha(c[i]))
        {
            ans=i;
            return;
        }
    }
}

int main()
{
    memset(b,0,sizeof(b));
    memset(a,0,sizeof(a));
    for(int i=1;i<=5;i++)
        for(int j=1;j<=6;j++)
        {
            cin>>a[i][j];
        }
    Dfs();
    for(int i=1;i<=6;i++)
    {
        b[1][i]=c[ans][i];
    }
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

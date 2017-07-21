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
//const int dx[]={-1,1,0,0};
//const int dy[]={0,0,-1,1};
int indexx=0;//counting from 0
char ans[100][100];
int b[10],visit[10];
void zhuanhuan(void)
{
    for(int i=0;i<8;i++)
        ans[indexx][i]=(char)(b[i+1]+'0');
    ans[indexx][8]='\0';
    //printf("%s\n",ans[indexx]);
    indexx++;
}
bool iseligble(int x,int y)
{
    int x1,x2,y1,y2,status=1;
    x2=x;
    y2=y;

    for(int i=1;i<x;i++)
    {
        x1=i;
        y1=b[i];
        if(abs(x2-x1)==abs(y2-y1))
            status=0;
    }
    return status;
}
void dfs(int x)
{
    //printf("Now x=%d\n",x);
    if(x==9)
    {
        zhuanhuan();

        return;
    }
    for(int i=1;i<=8;i++)
    {
        if((!visit[i])&&(iseligble(x,i)))
        {
            b[x]=i;
            visit[i]=1;
            dfs(x+1);
            visit[i]=0;
        }
    }
    return ;
}
int main(void)
{
    int t,input;
    memset(ans,0,sizeof(ans));
    memset(visit,0,sizeof(visit));
    cin>>t;
    dfs(1);
    while(t--)
    {
        //memset(ans,0,sizeof(ans));
        //memset(visit,0,sizeof(visit));
        cin>>input;

        //sort(ans,ans+92);
        int tempp=input-1;
        printf("%s\n",ans[tempp]);
        //printf("\n");
        //cout<<num<<endl;
    }

    return 0;
}

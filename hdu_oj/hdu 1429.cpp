#include<stdio.h>
#include<string.h>
#include<limits.h>
#include<ctype.h>
#include<string>
#include<sstream>
#include<iostream>
#include<queue>
#include<math.h>
#include<algorithm>
using namespace std;
int n,m,t,start_x,start_y,end_x,end_y;
const int dx[]={-1,1,0,0};
const int dy[]={0,0,-1,1};
int step[25][25][2048],visit[25][25][2048];
int a[25][25];
struct myk{
int x;
int y;
int z;};
queue <myk> q;
char tempp;
void push(int xx,int yy,int zz)
{
    myk temp;
    temp.x=xx;
    temp.y=yy;
    temp.z=zz;
    visit[xx][yy][zz]=1;
    q.push(temp);
}
bool iseligble(int x,int y)
{
    if((x>=1)&&(x<=n)&&(y>=1)&&(y<=m))
        return true;
    else
        return false;
}
bool havekey(int status,int x)
{
    int key[20],indexx=0;
    for(int i=1;i<=10;i++)
    {
        key[i]=status%2;
        status/=2;
    }
    if(key[x]==1)
        return true;
    else
        return false;
}
int addkey(int status,int x)
{
    if(!havekey(status,x))
        status+=(int)pow(2,x-1);
    return status;
}
void bfs(void)
{
    int xx,yy,zz,x_now,y_now,z_now,num_key;
    myk temp;
    while(!q.empty())
    {
        temp=q.front();
        x_now=temp.x;
        y_now=temp.y;
        z_now=temp.z;
        //printf("(%d,%d):%d\n",x_now,y_now,step[x_now][y_now][z_now]);

        q.pop();
        for(int i=0;i<4;i++)
        {
            xx=x_now+dx[i];
            yy=y_now+dy[i];
            if(iseligble(xx,yy)&&(a[xx][yy]!=0))
            {
                if (isupper((char)a[xx][yy]))
                {
                    num_key=a[xx][yy]-'A'+1;//counting from 1
                    if((havekey(z_now,num_key)&&!visit[xx][yy][z_now]))
                    {
                        step[xx][yy][z_now]=1+step[x_now][y_now][z_now];
                        push(xx,yy,z_now);
                    }
                    else
                    {
                        continue;
                    }

                }
                if (islower((char)a[xx][yy]))
                {
                    //printf("daolehaha\n");
                    num_key=a[xx][yy]-'a'+1;
                    zz=addkey(z_now,num_key);
                    //printf("zz=%d\n",zz);
                    if(!visit[xx][yy][zz])
                    step[xx][yy][zz]=1+step[x_now][y_now][z_now];
                    push(xx,yy,zz);

                }
                if((a[xx][yy]==1)&&!visit[xx][yy][z_now])
                {
                    //printf("daolehaha,x=%d,y=%d,z=%d\n",xx,yy,zz);
                    step[xx][yy][z_now]=1+step[x_now][y_now][z_now];
                    if((step[xx][yy][z_now]>t)||((end_x==xx)&&(end_y==yy)))
                        break;
                    push(xx,yy,z_now);
                }
            }
        }

    }
}
int main(void)
{
    int flag;
    while(cin>>n>>m>>t)
    {
        string temp;
        memset(step,-1,sizeof(step));
        memset(visit,0,sizeof(visit));
        //memset(key,0,sizeof(key));
        for(int i=1;i<=n;i++)
        {
            cin>>temp;
            stringstream ss(temp);
            for(int j=1;j<=m;j++)
            {
                ss>>tempp;
                switch(tempp)
                {
                    case '.':a[i][j]=1;
                             break;
                    case '*':a[i][j]=0;
                             break;
                    case '@':a[i][j]=1;
                             start_x=i;
                             start_y=j;
                             break;
                    case '^':a[i][j]=1;
                             //printf("wocao\n");
                             end_x=i;
                             end_y=j;
                             break;
                    default:a[i][j]=(int)tempp;
                            break;
                }

            }
        }

        push(start_x,start_y,0);
        step[start_x][start_y][0]=0;
        bfs();
        //printf("%d\n",havekey(10,2));
        flag=0;
        for(int i=1;i<=1024;i++)
        {
            if((step[end_x][end_y][i]!=-1)&&(step[end_x][end_y][i]<t))
            {
                cout<<step[end_x][end_y][i]<<endl;
                flag=1;
                break;
            }
        }

        if(!flag)
            printf("-1\n");
    }
    return 0;
}

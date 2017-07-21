#include<cstdio>
#include<cstring>
#include<queue>
#include<map>
#include<iostream>
using namespace std;
const int dx[]={-1,1,0,0};
const int dy[]={0,0,-1,1};
int ans;
struct Matrix
{
    int a[4][4];
    bool operator ==(const Matrix& X)const
    {
        return(  (a[1][1]==X.a[1][1])&&(a[1][2]==X.a[1][2])&&(a[1][3]==X.a[1][3])
               &&(a[2][1]==X.a[2][1])&&(a[2][2]==X.a[2][2])&&(a[2][3]==X.a[2][3])
               &&(a[3][1]==X.a[3][1])&&(a[3][2]==X.a[3][2])&&(a[3][3]==X.a[3][3])
               );
    }
    Matrix& operator=(const Matrix& X)
    {
        for(int i=1;i<=3;i++)
            for(int j=1;j<=3;j++)
                a[i][j]=X.a[i][j];
    }
    bool operator <(const Matrix& X)const
    {
        for(int i=1;i<=3;i++)
            for(int j=1;j<=3;j++)
            {
                if(a[i][j]==X.a[i][j])
                    continue;
                return(a[i][j]<X.a[i][j]);
            }
        return false;
    }
};
bool iseligble(int x,int y)
{
    return((x>=1)&&(x<=3)&&(y>=1)&&(y<=3));
}
queue<Matrix> q;
map<Matrix,int> step;
Matrix start,finish;
void init(void)
{
    for(int i=1;i<=3;i++)
        for(int j=1;j<=3;j++)
            cin>>start.a[i][j];
    for(int i=1;i<=3;i++)
        for(int j=1;j<=3;j++)
            cin>>finish.a[i][j];
    while(!q.empty())
        q.pop();
    q.push(start);
    step.clear();
    step[start]=0;
    ans=-1;
}
int main(void)
{
    freopen("in.txt","r",stdin);
    int temp_step,t,xx,yy,xxx,yyy;//(xx,yy) is the blank position
    Matrix temp;
    cin>>t;
    while(t--)
    {
        init();
        while(!q.empty())
        {
            temp=q.front();
            temp_step=step[temp];

            if(temp==finish)
            {
                ans=temp_step;
                break;
            }
            q.pop();
            for(int i=1;i<=3;i++)
                for(int j=1;j<=3;j++)
                {
                    if(temp.a[i][j]==0)
                    {
                        xx=i;
                        yy=j;
                        break;
                    }
                }
            for(int i=0;i<4;i++)
            {
                xxx=xx+dx[i];
                yyy=yy+dy[i];
                Matrix newtemp=temp;
                if(iseligble(xxx,yyy))
                    swap(newtemp.a[xxx][yyy],newtemp.a[xx][yy]);
                else
                    continue;
                if(step.count(newtemp)==1)
                    continue;
                q.push(newtemp);
                step[newtemp]=temp_step+1;


            }

        }
        cout<<ans<<endl;
    }
    return 0;
}

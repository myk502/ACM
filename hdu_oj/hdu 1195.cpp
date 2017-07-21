#include<cstdio>
#include<cstring>
#include<string>
#include<sstream>
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
int flag,t,visit[2][10][10][10][10],step[2][10][10][10][10];
int ans,start[4],finish[4];
int jia(int x)
{
    if(x==9)
        return 0;
    else
        return (x+1);
}
int jian(int x)
{
    if(x==0)
        return 9;
    else
        return (x-1);
}
struct Lock
{
    int num[10];
    Lock(int aa,int bb,int cc,int dd)
    {
        num[0]=aa;
        num[1]=bb;
        num[2]=cc;
        num[3]=dd;
    }
    Lock()
    {

    }

};
queue <Lock> q[2];
void push0(int aa,int bb,int cc,int dd)
{
    Lock temp(aa,bb,cc,dd);
    visit[0][aa][bb][cc][dd]=1;
    q[0].push(temp);
}
void push1(int aa,int bb,int cc,int dd)
{
    Lock temp(aa,bb,cc,dd);
    visit[1][aa][bb][cc][dd]=1;
    q[1].push(temp);
}

void init(void)
{
    while(!q[0].empty())
        q[0].pop();
    while(!q[1].empty())
        q[1].pop();
    push0(start[0],start[1],start[2],start[3]);
    push1(finish[0],finish[1],finish[2],finish[3]);
    step[0][start[0]][start[1]][start[2]][start[3]]=0;
    step[1][finish[0]][finish[1]][finish[2]][finish[3]]=0;
}
void bfs0(void)
{
    int now[4],nnow[4],step_now;
    if(!q[0].empty())
    {
        Lock temp=q[0].front();

        for(int i=0;i<4;i++)
        {
            now[i]=temp.num[i];
            nnow[i]=temp.num[i];
        }
        step_now=step[0][now[0]][now[1]][now[2]][now[3]];
        q[0].pop();

        for(int i=0;i<8;i++)
        {

            if(i%2==0)//minus
            {
                nnow[i/2]=jian(nnow[i/2]);
            }
            else
            {
                nnow[i/2]=jia(nnow[i/2]);
            }
            if(!visit[0][nnow[0]][nnow[1]][nnow[2]][nnow[3]])
            {
                step[0][nnow[0]][nnow[1]][nnow[2]][nnow[3]]=1+step_now;
                if(visit[1][nnow[0]][nnow[1]][nnow[2]][nnow[3]])
                {
                    ans=step[0][nnow[0]][nnow[1]][nnow[2]][nnow[3]]+step[1][nnow[0]][nnow[1]][nnow[2]][nnow[3]];
                    flag=1;
                    return ;
                }
                push0(nnow[0],nnow[1],nnow[2],nnow[3]);
            }
            for(int j=0;j<4;j++)
                nnow[i]=now[i];
        }
        for(int i=0;i<3;i++)//swap i and i+1
        {
            swap(nnow[i],nnow[i+1]);
            if(!visit[0][nnow[0]][nnow[1]][nnow[2]][nnow[3]])
            {
                step[0][nnow[0]][nnow[1]][nnow[2]][nnow[3]]=1+step_now;
                if(visit[1][nnow[0]][nnow[1]][nnow[2]][nnow[3]])
                {
                    ans=step[0][nnow[0]][nnow[1]][nnow[2]][nnow[3]]+step[1][nnow[0]][nnow[1]][nnow[2]][nnow[3]];
                    flag=1;
                    return ;
                }
                push0(nnow[0],nnow[1],nnow[2],nnow[3]);
            }
            for(int j=0;j<4;j++)
                nnow[i]=now[i];
        }
    }
}
void bfs1(void)
{
    int now[4],nnow[4],step_now;
    if(!q[1].empty())
    {
        Lock temp;
        temp=q[1].front();
        for(int i=0;i<4;i++)
        {
            now[i]=temp.num[i];
            nnow[i]=temp.num[i];
        }
        step_now=step[1][now[0]][now[1]][now[2]][now[3]];
        q[1].pop();
        for(int i=0;i<8;i++)
        {

            if(i%2==0)//minus
            {
                nnow[i/2]=jian(nnow[i/2]);
            }
            else
            {
                nnow[i/2]=jia(nnow[i/2]);
            }
            if(!visit[1][nnow[0]][nnow[1]][nnow[2]][nnow[3]])
            {
                step[1][nnow[0]][nnow[1]][nnow[2]][nnow[3]]=1+step_now;
                if(visit[0][nnow[0]][nnow[1]][nnow[2]][nnow[3]])
                {
                    ans=step[0][nnow[0]][nnow[1]][nnow[2]][nnow[3]]+step[1][nnow[0]][nnow[1]][nnow[2]][nnow[3]];
                    flag=1;
                    return ;
                }
                push1(nnow[0],nnow[1],nnow[2],nnow[3]);
            }
            for(int j=0;j<4;j++)
                nnow[i]=now[i];
        }
        for(int i=0;i<3;i++)//swap i and i+1
        {
            swap(nnow[i],nnow[i+1]);
            if(!visit[1][nnow[0]][nnow[1]][nnow[2]][nnow[3]])
            {
                step[1][nnow[0]][nnow[1]][nnow[2]][nnow[3]]=1+step_now;
                if(visit[0][nnow[0]][nnow[1]][nnow[2]][nnow[3]])
                {
                    ans=step[0][nnow[0]][nnow[1]][nnow[2]][nnow[3]]+step[1][nnow[0]][nnow[1]][nnow[2]][nnow[3]];
                    flag=1;
                    return ;
                }
                push1(nnow[0],nnow[1],nnow[2],nnow[3]);
            }
            for(int j=0;j<4;j++)
                nnow[i]=now[i];
        }
    }
}
int main(void)
{
    //cin>>t;
    t=1;
    while(t--)
    {
        flag=0;
        memset(visit,0,sizeof(visit));
        memset(step,-1,sizeof(step));
        char input[10];
        /*
        scanf("%s",input);
        for(int i=0;i<4;i++)
            start[i]=input[i]-'0';
        scanf("%s",input);
        for(int i=0;i<4;i++)
            finish[i]=input[i]-'0';
        */
        start[0]=1;
        start[1]=2;
        start[2]=3;
        start[3]=4;
        finish[0]=2;
        finish[1]=1;
        finish[2]=4;
        finish[3]=4;
        init();

        while(flag==0)
        {

            int size0=q[0].size(),size1=q[1].size();

            if(size0>size1)
            {
                bfs1();
            }
            else
                bfs0();
        }

        cout<<ans<<endl;
    }
    return 0;
}

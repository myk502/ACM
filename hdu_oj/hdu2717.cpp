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
int visit[100000*3+10],step[100000*3+10],temp;
int n,k;
queue <int> q;
void push(int x)
{

    visit[x]=1;
    q.push(x);
    //step[x]=1+step[temp];
}
bool iseligble(int x)
{
    if((x>=1)&&(x<=2*k))
        return true;
    else
        return false;
}
void bfs(void)
{
    while(!q.empty())
    {
        temp=q.front();
        q.pop();
        if((iseligble(2*temp))&&(!visit[2*temp]))
        {
            step[2*temp]=1+step[temp];
            if(2*temp==k)
                break;
            push(2*temp);
        }
        if((iseligble(temp+1))&&(!visit[temp+1]))
        {
            step[temp+1]=1+step[temp];
            if(1+temp==k)
                break;
            push(temp+1);
        }
        if((iseligble(temp-1))&&(!visit[temp-1]))
        {
            step[temp-1]=1+step[temp];
            if(temp-1==k)
                break;
            push(temp-1);
        }
    }



}
int main(void)
{

    memset(visit,0,sizeof(visit));
    memset(step,-1,sizeof(step));
    cin>>n>>k;
    if(n<k)
    {
        step[n]=0;
        push(n);
        bfs();
        cout<<step[k];
    }
    else
    {
        cout<<n-k;
    }

    return 0;
}

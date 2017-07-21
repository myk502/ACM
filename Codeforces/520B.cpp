#include<stdio.h>
#include<float.h>
#include<math.h>
#include<string.h>
#include<queue>
#include<algorithm>
using namespace std;
queue <int> q;
#define zuida 20000
int m,n,a[zuida],visit[zuida],step[zuida];
int temp;
void push(int x)
{
    visit[x]=1;
    q.push(x);
    step[x]=1+step[temp];
}
void bfs(void)
{
    while(!q.empty())
    {
        temp=q.front();
        q.pop();
        if((temp<m)&&!visit[temp*2])
            push(temp*2);
        if(temp*2==m)
            return ;
        if(!visit[temp-1])
            push(temp-1);
        if(temp*2==m)
            return ;
    }
}
int main(void)
{
    scanf("%d%d",&n,&m);
    memset(visit,0,sizeof(visit));
    memset(step,-1,sizeof(step));
    if(n>=m)
        printf("%d",n-m);
    else
    {
        q.push(n);
        step[n]=0;
        bfs();
        printf("%d",step[m]);
    }
}

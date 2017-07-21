#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;
int n,visit[100],a[100];
void dfs(int x)
{
    if(x==n+1)
    {
        for(int i=1;i<=n;i++)
            printf("%d ",a[i]);
        printf("\n");
        return ;
    }
    for(int i=1;i<=n;i++)
    {
        if(!visit[i])
        {
            visit[i]=1;
            a[x]=i;
            dfs(x+1);
            visit[i]=0;
        }
    }
}

int main(void)
{
    memset(visit,0,sizeof(visit));
    cin>>n;
    dfs(1);
    return 0;
}

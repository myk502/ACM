#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;
int ans,a[100];
int t;
int m,n;

void dfs(int x)
{
    int sum=0;
    for(int i=1;i<x;i++)
        sum+=a[i];
    if(sum>m)
        return ;
    if((x==n+1)&&(sum==m))
    {

        ans++;
        return ;
    }
    if(x==n+1)
        return ;
    for(int i=m;i>=0;i--)
    {
        if(i>=a[x-1])
        {
            a[x]=i;
            dfs(x+1);
            a[x]=-1;
        }
        else
        {
            return ;
        }
    }

}
int main(void)
{
    //int t;

    scanf("%d",&t);

    while(t--)
    {

        scanf("%d%d",&m,&n);
        memset(a,-1,sizeof(a));

        ans=0;
        dfs(1);
        //printf("%d\n",t);
        printf("%d\n",ans);
    }

    return 0;
}

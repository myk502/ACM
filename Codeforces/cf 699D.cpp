#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<iostream>
#include<vector>
#include<sstream>
#include<queue>
#include<limits.h>
#include<set>
#include<math.h>
#include<algorithm>
using namespace std;
 int ans=0,noroot=0;
int pre[200000+10],a[200000+10],status[200000+10],b[200000+10];
int root,n,indexx=0;
int find(int x)
{
    int r=x;
    while(pre[r]!=r)
        r=pre[r];
    int i=x,j;
    while(i!=r)
    {
        j=pre[i];
        pre[i]=r;
        i=j;
    }
    return r;
}
void join(int x,int y)
{
    int fx=find(x),fy=find(y);
    if(fx!=fy)
    {
        pre[fx]=fy;
        b[indexx++]=y;
    }

    else
    {
        if(noroot==1)
        {
            noroot=0;
            b[indexx++]=x;
            root=x;
            ans++;
            status[x]=1;
        }
        else
        {
            status[fx]=1;
            b[indexx++]=root;
        }
    }
}
int main(void)
{

    cin>>n;
    memset(status,0,sizeof(status));
    for(int i=1;i<=n;i++)
    {
        pre[i]=i;
    }

    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    root=-1;
    for(int i=1;i<=n;i++)
    {
        if(a[i]==i)
        {
            root=i;
            break;
        }
    }
    if(root==-1)
    {
        noroot=1;
    }

    for(int i=1;i<=n;i++)
    {
        join(i,a[i]);
    }

    for(int i=1;i<=n;i++)
    {
        if(status[i]!=0)
            ans++;
    }
    cout<<ans-1<<endl;
    for(int i=0;i<n;i++)
        printf("%d ",b[i]);
    return 0;
}

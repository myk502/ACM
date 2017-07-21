#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int n,m,k,a[110];
int main(void)
{
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    int j=m;
    int ans=-1;
    for(int i=1;i<=n;i++)
    {
        int xx=j-i,yy=j+i;
        if(xx>=1&&xx<=n)
            if((a[xx]!=0) && (a[xx]<=k))
            ans=i;
        if(yy>=1 && yy<=n)
            if((a[yy]!=0) && (a[yy]<=k))
            ans=i; 
        if(ans!=-1)
        {
            cout<<ans*10<<endl;
            break;
        }
    }
    return 0;
}

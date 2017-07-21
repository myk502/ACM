#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int n,x,y,status;
long long temp,sum=0,ans,a[510][510];
int main(void)
{
    status=1;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>a[i][j];
            if(a[i][j]==0)
            {
                x=i;
                y=j;
            }
        }
    }
    if(n==1)
    {
        printf("1");
        return 0;
    }
    if(x==1)
    {
        for(int j=1;j<=n;j++)
            sum+=a[2][j];
    }
    else
    {
        for(int j=1;j<=n;j++)
            sum+=a[1][j];
    }
    temp=0;
    for(int j=1;j<=n;j++)
        temp+=a[x][j];
    ans=sum-temp;
    a[x][y]=ans;
    for(int i=1;i<=n;i++)//计算每行的和
    {
        temp=0;
        for(int j=1;j<=n;j++)
            temp+=a[i][j];
        if(temp!=sum)
            status=0;
    }
    for(int j=1;j<=n;j++)
    {
        temp=0;
        for(int i=1;i<=n;i++)
            temp+=a[i][j];
        if(temp!=sum)
            status=0;
    }
    {
        temp=0;
        for(int i=1;i<=n;i++)
            temp+=a[i][i];
        if(temp!=sum)
            status=0;
    }
    {
        temp=0;
        for(int i=1;i<=n;i++)
            temp+=a[i][n-i+1];
        if(temp!=sum)
            status=0;
    }
    if(ans<=0)
        status=0;
    if(status)
        cout<<ans;
    else
        printf("-1");
    return 0;
}

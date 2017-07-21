#include<stdio.h>
#include<string.h>
#include<algorithm>
#define zuida 1000
using namespace std;
int i,j,k,l,maxn,n,m,a[zuida+10][zuida+10];
long long dp1[zuida+10][zuida+10],dp2[zuida+10][zuida+10],dp3[zuida+10][zuida+10],dp4[zuida+10][zuida+10];
int main(void)
{
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            scanf("%d",&a[i][j]);
    memset(dp1,0,sizeof(dp1));
    memset(dp2,0,sizeof(dp2));
    memset(dp3,0,sizeof(dp3));
    memset(dp4,0,sizeof(dp4));
    for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
        dp1[i][j]=max(dp1[i][j-1],dp1[i-1][j])+a[i][j];
    for(i=1;i<=n;i++)
    for(j=m;j>=1;j--)
        dp2[i][j]=max(dp2[i][j+1],dp2[i-1][j])+a[i][j];
    for(i=n;i>=1;i--)
    for(j=m;j>=1;j--)
        dp3[i][j]=max(dp3[i][j+1],dp3[i+1][j])+a[i][j];
    for(i=n;i>=1;i--)
    for(j=1;j<=m;j++)
        dp4[i][j]=max(dp4[i][j-1],dp4[i+1][j])+a[i][j];
    maxn=0;
    int temp1,temp2;
    for(i=1;i<n;i++)
        for(j=1;j<m;j++)
    {
        temp1=max(dp1[i][j-1]+dp3[i][j+1]+dp4[i+1][j]+dp2[i-1][j],dp1[i-1][j]+dp3[i+1][j]+dp4[i][j-1]+dp2[i][j+1]);
        maxn=max(temp1,maxn);
    }


    printf("%d",maxn);
    return 0;
}

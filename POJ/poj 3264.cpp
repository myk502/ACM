#include<cstdio>
#include<cstring>
#include<string>
#include<queue>
#include<vector>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=50000+10;
int n,q,a[maxn],dp1[maxn][20],dp2[maxn][20],logg2[maxn];//dp1 represents the minimal number while dp2 represents the maximal number
void RMQ_init(void)
{
    for(int i=1;i<=n;i++)
        dp1[i][0]=dp2[i][0]=a[i];
    for(int j=1;(1<<j)<=n;j++)
    {
        for(int i=1;i+(1<<j)-1<=n;i++)
        {
            dp1[i][j]=min(dp1[i][j-1],dp1[i+(1<<j-1)][j-1]);
            dp2[i][j]=max(dp2[i][j-1],dp2[i+(1<<j-1)][j-1]);
        }
    }
    for(int i=1;i<=n;i++)
    {
        logg2[i]=(double)log10(i)/(double)log10(2);
        //printf("logg2[%d]=%d\n",i,logg2[i]);
    }
}
int main(void)
{
    cin>>n>>q;
    int L,R,ans_min,ans_max,ans;
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    RMQ_init();
    //printf("logg2[8]=%d\n",logg2[8]);
    while(q--)
    {
        scanf("%d%d",&L,&R);
        int k=logg2[R-L];
        //printf("L=%d R=%d k=%d\n",L,R,k);
        //printf("R-(1>>k)+1=%d\n",R-(1<<k)+1);
        //printf("dp1[1][2]=%d,dp1[2][2]=%d\n",dp1[L][k],dp1[R-(1>>k)+1][k]);
        ans_min=min(dp1[L][k],dp1[R-(1<<k)+1][k]);
       // printf("min=%d\n",ans_min);
        ans_max=max(dp2[L][k],dp2[R-(1<<k)+1][k]);
        ans=ans_max-ans_min;

        printf("%d\n",ans);
    }
    return 0;
}

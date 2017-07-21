#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<string>
#include<sstream>
#include<set>
#include<algorithm>
using namespace std;
int n,a[100000+10],dp[100000+10],index[100000+10];
int main(void)
{
    int t,max_left,max_right,maxn;
    cin>>t;
    for(int ii=1;ii<=t;ii++)
    {
        cin>>n;
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        dp[0]=0;
        index[0]=1;
        for(int i=1;i<=n;i++)
        {
            if(dp[i-1]<0)
            {
                index[i]=i;
                dp[i]=a[i];
            }
            else
            {
                index[i]=index[i-1];
                dp[i]=dp[i-1]+a[i];
            }
        }
        maxn=dp[1];
        max_left=max_right=index[1];
        for(int i=1;i<=n;i++)
        {
            if(dp[i]>maxn)
            {
                maxn=dp[i];
                max_right=i;
                max_left=index[i];
            }

        }
        if(ii!=1)
            printf("\n");
        printf("Case %d:\n",ii);
        printf("%d %d %d\n",maxn,max_left,max_right);

    }
    return 0;
}

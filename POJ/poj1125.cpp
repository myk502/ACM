#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<limits.h>
using namespace std;
#define zuida 10000
int a[110][110],n,m,tempa,tempb;
int main(void)
{
    int status,ans,maxn,ans_num;
    while(scanf("%d",&n))
    {
        if(n==0)
            break;
        status=0;
        for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            a[i][j]=zuida;
            a[i][i]=0;
        }
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&m);
            for(int j=0;j<m;j++)
            {
                scanf("%d%d",&tempa,&tempb);
                a[i][tempa]=tempb;
            }
        }
        for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
        ans=zuida;
        for(int i=1;i<=n;i++)
        {
            maxn=INT_MIN;
            for(int j=1;j<=n;j++)
            {
                if(i==j)
                    continue;
                maxn=max(a[i][j],maxn);
            }
            if(maxn<ans)
            {
                ans=maxn;
                ans_num=i;
                status=1;
            }
        }
        if(!status)
            printf("disjoint\n");
        else
            printf("%d %d\n",ans_num,ans);
    }
    return 0;
}

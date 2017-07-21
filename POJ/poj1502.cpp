#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<limits.h>
using namespace std;
int n,a[110][110];
int main(void)
{
    int maxn,ans;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            a[i][j]=INT_MAX/3;
            a[i][i]=0;
        }
    for(int i=2;i<=5;i++)
        for(int j=1;j<i;j++)
        {
            if(scanf("%d",&a[i][j])==0)
            {
                a[i][j]=INT_MAX/3;
                scanf("%c");
            }
            a[j][i]=a[i][j];
        }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
            {
                a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
            }
    int i=1;
    maxn=0;
    for(int j=2;j<=n;j++)
    {
        maxn=max(a[i][j],maxn);
    }
    printf("%d",maxn);
    return 0;
}

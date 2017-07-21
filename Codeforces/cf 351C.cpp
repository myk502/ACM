#include<stdio.h>
#include<math.h>
#include<string.h>
#include<limits.h>
#include<algorithm>
using namespace std;
int n,t[5010],num[5010],a[5010*5011/2+1][5010];
int main(void)
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&t[i]);
    memset(num,0,sizeof(num));
    memset(a,0,sizeof(a));
    for(int i=1;i<=n;i++)
        a[i][i][t[i]]=1;
    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j++)
    {
        int max_num=0,max_k=1;//针对这一段的最大的k
        for(int k=1;k<=n;k++)
        {
            if(j>i)
            {
                if(t[j]==k)
                    a[i][j][k]=a[i][j-1][k]+1;
                else
                    a[i][j][k]=a[i][j-1][k];
            }
            if(a[i][j][k]>max_num)
            {
                max_num=a[i][j][k];
                max_k=k;
            }
        }
        num[max_k]++;
    }
    for(int i=1;i<=n;i++)
        printf("%d ",num[i]);
    return 0;
}

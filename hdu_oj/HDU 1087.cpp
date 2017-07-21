#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int a[1010],b[1010];
int main(void)
{
    int n,i,j,maxn;
    while(scanf("%d",&n))
    {
        if(n==0)
            break;
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        b[0]=a[0];
        for(i=1;i<n;i++)
        {
            maxn=0;
            for(j=0;j<i;j++)
            {
                if(a[j]<a[i])
                    maxn=max(maxn,b[j]);
            }
            b[i]=a[i]+maxn;
        }
        maxn=0;
        for(i=0;i<n;i++)
        {
            maxn=max(maxn,b[i]);
            printf("b[%d]=%d\n",i,b[i]);
        }
        printf("%d\n",maxn);
    }
    return 0;
}

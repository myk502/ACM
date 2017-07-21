#include<stdio.h>
#include<string.h>
#include<math.h>
#include<limits.h>
#include<algorithm>
using namespace std;
#define zuida 100000
int n,m;

int main(void)
{

    scanf("%d%d",&n,&m);

    if(n==m)
        printf("-1");
    else
    {
        printf("%d ",n-m);
        for(int i=1;i<=n-m-1;i++)
        {
            printf("%d ",i);
        }
        for(int i=n-m+1;i<=n;i++)
            printf("%d ",i);
    }
    return 0;
}

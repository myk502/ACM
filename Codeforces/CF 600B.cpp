#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<limits.h>
using namespace std;
#define maxn 200000
int m,n,a[maxn+10],b[maxn+10],minn;
int chazhao(int input)
{
    int l,r,zhongjian;
    l=0;
    r=n;
    if(input<minn)
        return 0;
    while(r-l>1)
    {
        zhongjian=(l+r)/2;
        if(a[zhongjian]<=input)
        {
            l=zhongjian;
        }
        else
            r=zhongjian;
    }
    return(l+1);
}
int main(void)
{
    minn=INT_MAX;
    int i,j;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]<minn)
            minn=a[i];
    }
    sort(a,a+n);
    for(j=0;j<m;j++)
        scanf("%d",&b[j]);
    for(j=0;j<m;j++)
        printf("%d ",chazhao(b[j]));
    return 0;

}


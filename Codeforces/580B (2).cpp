#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<limits.h>
#define zuida 100000
using namespace std;
int n,d,i;
long long maxn,sum,qiuhe[zuida];
struct myk{
int m;
int s;
};
myk a[zuida+10];
bool cmp(myk a,myk b)
{
    if(a.m<b.m)
        return 1;
    else
        return 0;
}
int chazhao(int input)
{
    int l,r,mid;
    l=input;
    r=n;
    while(r-l>1)
    {
        mid=(l+r)/2;
        if((a[mid].m-a[i].m)<d)
            l=mid;
        else
            r=mid;
    }
    return l;
}
int main(void)
{
    scanf("%d%d",&n,&d);
    int j;
    for(i=0;i<n;i++)
        scanf("%d%d",&a[i].m,&a[i].s);
    sort(a,a+n,cmp);
    maxn=0;
    qiuhe[0]=a[0].s;
    for(i=1;i<n;i++)
        qiuhe[i]=qiuhe[i-1]+a[i].s;
    for(i=0;i<n;i++)
    {
        j=chazhao(i);

        sum=qiuhe[j]-qiuhe[i]+a[i].s;
        maxn=(sum>maxn)?sum:maxn;
    }
    printf("%I64d",maxn);
    return 0;
}

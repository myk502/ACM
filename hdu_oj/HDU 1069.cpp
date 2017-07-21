#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
struct myk{
int chang;
int kuan;
int gao;};
myk a[100],b[300];
int dp[300],i,j,m,n;
void tuozhan(void)
{
    for(j=0;j<n;j++)
        {
            b[j].chang=max(a[j].chang,a[j].kuan);
            b[j].kuan=min(a[j].chang,a[j].kuan);
            b[j].gao=a[j].gao;
        }
        for(j=n;j<2*n;j++)
        {
            b[j].gao=a[j-n].chang;
            b[j].chang=max(a[j-n].kuan,a[j-n].gao);
            b[j].kuan=min(a[j-n].kuan,a[j-n].gao);
        }
        for(j=2*n;j<3*n;j++)
        {
            b[j].gao=a[j-2*n].kuan;
            b[j].chang=max(a[j-2*n].chang,a[j-2*n].gao);
            b[j].kuan=min(a[j-2*n].chang,a[j-2*n].gao);
        }
}
bool cmp(myk x,myk y)
{
    if(x.chang==y.chang)
        return(x.kuan>y.kuan);
    else
        return(x.chang>y.chang);
}
bool panduan(myk i,myk j)
{
    if((i.chang<j.chang)&&(i.kuan<j.kuan))
        return true;
    else
        return false;
}
int main(void)
{
    int maxn,num=0;
    while(1)
    {
        scanf("%d",&n);
        if(n==0)
            break;
        for(i=0;i<n;i++)
            scanf("%d%d%d",&a[i].chang,&a[i].kuan,&a[i].gao);
        tuozhan();
        sort(b,b+3*n,cmp);
        dp[0]=b[0].gao;
        for(i=1;i<3*n;i++)
        {
            maxn=0;
            for(j=0;j<i;j++)
                if(panduan(b[i],b[j]))
                    maxn=(dp[j]>maxn)?dp[j]:maxn;
            dp[i]=b[i].gao+maxn;
        }
        maxn=-1;
        for(i=0;i<3*n;i++)
            maxn=(dp[i]>maxn)?dp[i]:maxn;
        printf("Case %d: maximum height = %d\n",++num,maxn);

    }
    return 0;
}

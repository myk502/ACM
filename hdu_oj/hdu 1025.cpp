#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<string>
#include<sstream>
#include<set>
#include<algorithm>
using namespace std;
struct link
{
    int p;
    int r;
};
link a[500000+10];
int d[500000+10];
int n,len;
bool cmp(link x,link y)
{
    return(x.p<y.p);
}
int chazhao(int left,int right,int value)//×ó±ÕÓÒ¿ª
{
    if(value<d[1])//important!
        return 1;
    while(right-left>1)
    {
        int mid=(left+right)/2;
        if(value<d[mid])
            right=mid;
        else
            left=mid;
    }
    return (right);
}
int main(void)
{
    int tt=0;
    while(scanf("%d",&n)!=EOF)
    {
        tt++;
        for(int i=1;i<=n;i++)
            scanf("%d%d",&a[i].p,&a[i].r);
        sort(a+1,a+n+1,cmp);
        memset(d,0,sizeof(d));
        len=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i].r>d[len])
            {
                d[++len]=a[i].r;
            }
            else
            {
                int x=chazhao(1,len,a[i].r);
                d[x]=a[i].r;
            }
        }
        printf("Case %d:\n",tt);
        if(len==1)
        {
            printf("My king, at most 1 road can be built.\n\n");
        }
        else
        {
            printf("My king, at most %d roads can be built.\n\n",len);
        }
    }
    return 0;
}

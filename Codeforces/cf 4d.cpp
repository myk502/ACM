#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
int n,w,h,b[5010],c[5010],d[5010],maxn,maxx;
struct myk{
int width;
int height;
};
myk a[5010],yuanshi[5010];
bool panduan(myk a,myk b)
{
    if((a.width<b.width)&&(a.height<b.height))
        return true;
    else
        return false;
}
bool cmp(myk a,myk b)
{
    if(a.width==b.width)
        return(a.height<b.height);
    else
        return(a.width<b.width);
}
int chazhao(int input)
{
    int i;
    for(i=1;i<=n;i++)
        if((yuanshi[i].width==a[input].width)&&(yuanshi[i].height==a[input].height))
            return i;
}
int main(void)
{
    scanf("%d%d%d",&n,&w,&h);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&a[i].width,&a[i].height);
        yuanshi[i].width=a[i].width;
        yuanshi[i].height=a[i].height;
    }
    sort(a+1,a+n+1,cmp);
    a[0].width=w;
    a[0].height=h;
    /*for(int i=0;i<=n;i++)
        printf("Number %d: %d %d\n",i,a[i].width,a[i].height);
    */
    memset(b,0,sizeof(b));
    memset(c,-1,sizeof(c));
    for(int i=1;i<=n;i++)
    {
        maxn=-1;
        for(int j=0;j<i;j++)
        {
            if(panduan(a[j],a[i]))
            {
                if((j>0)&&b[j]==0)
                    continue;
                if(b[j]>maxn)
                {
                    maxn=b[j];
                    c[i]=j;
                }
            }
        }
        b[i]=maxn+1;
    }
    /*for(int i=0;i<=n;i++)
        printf("c[%d]=%d\n",i,c[i]);
    */
    /*for(int i=0;i<=n;i++)
        printf("b[%d]=%d\n",i,b[i]);
    */
    int temp,tempn;
    maxx=0;
    for(int i=1;i<=n;i++)
    {
        if(b[i]>maxx)
        {
            maxx=b[i];
            temp=i;
        }
    }
    if(maxx==0)
        printf("0");
    else
    {
        printf("%d\n",maxx);
        int num=0;
        tempn=temp;
        while(tempn!=0)
        {
            d[num++]=tempn;
            tempn=c[tempn];

        }
        for(int j=num-1;j>=0;j--)
            printf("%d ",chazhao(d[j]));

    }
    return 0;


}

#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<limits.h>
#include<math.h>
using namespace std;
int n,a[200000+10],status[1000000+10],zuida[1000000+10];//zuida[i]表示到i出现过的最大的数，如果没有数为-1;
void initialization(void)
{
    memset(zuida,-1,sizeof(zuida));
    zuida[1]=(status[1]>0)?1:-1;
    for(int i=2;i<=1000000;i++)
    {
        if(status[i]==1)
            zuida[i]=i;
        else
            zuida[i]=zuida[i-1];
    }
}
int main(void)
{
    int xx,yy,ans,maxn,zuida_num;
    scanf("%d",&n);
    memset(status,0,sizeof(status));
    zuida_num=-1;
    for(int i=1;i<=n;i++)
    {
         scanf("%d",&a[i]);
         status[a[i]]=1;
         zuida_num=max(zuida_num,a[i]);
    }
    initialization();
    ans=0;
    for(int i=1;i<=zuida_num;i++)//确定被除数
    {
        if(status[i]==0)
            continue;
        maxn=ans;
        for(int k=0;k<=zuida_num/i;k++)//确定一个区间
        {
            xx=k*i;
            yy=min(k*i+i-1,zuida_num);
            if(zuida[yy]<xx)//这个区间没数
                continue;
            else
            {
                if(zuida[yy]>i)
                    maxn=max(maxn,zuida[yy]%i);//maxn是被除数是i时最大的一个结果，最后再与ans比较
                //printf("maxn=%d,and now i=%d,k=%d,xx=%d,yy=%d\n",maxn,i,k,xx,yy);
            }

        }
        ans=max(ans,maxn);
    }
    printf("%d",ans);
    return 0;
}

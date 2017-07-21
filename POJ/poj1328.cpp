#include<stdio.h>
#include<string.h>
#include<iostream>
#include<limits.h>
#include<math.h>
#include<algorithm>
#include<ctype.h>
using namespace std;
typedef struct {
double start;
double finish;
int x;
int y;}myk;
myk a[10100];
int n,d;
bool cmp(myk xx,myk yy)
{
    return(xx.finish<yy.finish);
    return(xx.start>yy.start);
}
int main(void)
{
    //int i;
    int ans,cases=0,flag;
    double temp;
    while(scanf("%d%d",&n,&d))
    {
        flag=0;
        //printf("n=%d and d=%d\n",n,d);
        if((n==0)&&(d==0))
               break;

        for(int i=0;i<n;i++)
        {
            ans=1;
            scanf("%d%d",&a[i].x,&a[i].y);
            //printf("%d %d",a[i].x,a[i].y);
            if(d<a[i].y)
            {
                ans=-1;

                continue;
            }
            if(ans!=-1)
            {
                temp=fabs(sqrt(d*d-a[i].y*a[i].y));
                //printf("temp=%lf\n",temp);
                a[i].start=-temp+a[i].x;
                a[i].finish=temp+a[i].x;
            }
        }
        if(ans==-1)
            goto endd;
        ans=1;
        sort(a,a+n,cmp);
/*
        for(int i=0;i<n;i++)
            printf("%lf   %lf   \n",a[i].start,a[i].finish);
*/
        temp=a[0].finish;
        for(int i=1;i<n;i++)
        {
            if(a[i].start<=temp)
                //ans++;
                continue;
            else
            {
                temp=a[i].finish;
                ans++;
            }
        }
        endd:cases++;
        printf("Case %d: %d\n",cases,ans);
    }
    return 0;
}

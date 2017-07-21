#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<queue>
#include<cmath>
#include<climits>
#include<sstream>
#include<algorithm>
using namespace std;
#define pi acos(-1)
struct myk{
double x;
double y;
double distance;};
myk a[100000+10];
int n,origin_x,origin_y;
double xiao,da;
double juli(double xx1,double yy1,double xx2,double yy2)
{
    double xx0=origin_x,yy0=origin_y;
    double temp,temp2;
    temp=sqrt((xx2-xx1)*(xx2-xx1)+(yy2-yy1)*(yy2-yy1));
    temp2=(xx1-xx0)*(yy2-yy0)-(yy1-yy0)*(xx2-xx0);
    temp2=fabs(temp2);
    return(temp2/temp);
}
bool isruijiao(double xx1,double yy1,double xx2,double yy2)
{
    int status=1;
    double xx0=origin_x,yy0=origin_y;
    if((xx0-xx1)*(xx2-xx1)+(yy0-yy1)*(yy2-yy1)<0)
        status=0;

    if((xx1-xx2)*(xx0-xx2)+(yy1-yy2)*(yy0-yy2)<0)
        status=0;
    return status;

}
int main(void)
{
    cin>>n>>origin_x>>origin_y;
    xiao=1000000000;
    da=0;
    for(int i=0;i<n;i++)
    {
        scanf("%lf%lf",&a[i].x,&a[i].y);
        a[i].distance=sqrt(((a[i].x-origin_x)*(a[i].x-origin_x))+((a[i].y-origin_y)*(a[i].y-origin_y)));
        xiao=min(xiao,a[i].distance);
        da=max(da,a[i].distance);
    }
    //printf("xiao=%lf,da=%lf\n",xiao,da);
    for(int i=1;i<n;i++)//an edge from verex i-1 to vertex i
    {
        if(isruijiao(a[i-1].x,a[i-1].y,a[i].x,a[i].y))
            xiao=min(xiao,juli(a[i-1].x,a[i-1].y,a[i].x,a[i].y));
        //da=max(da,juli(a[i-1].x,a[i-1].y,a[i].x,a[i].y));
    }
    //printf("xiao=%lf,da=%lf\n",xiao,da);
    if(isruijiao(a[0].x,a[0].y,a[n-1].x,a[n-1].y))
        xiao=min(xiao,juli(a[0].x,a[0].y,a[n-1].x,a[n-1].y));
    //da=max(da,juli(a[0].x,a[0].y,a[n-1].x,a[n-1].y));
    //printf("xiao=%lf,da=%lf\n",xiao,da);
    double temp=da*da-xiao*xiao;
    printf("%.15lf",pi*temp);
    return 0;
}

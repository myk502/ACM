#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<string>
#include<sstream>
#include<cfloat>
#include<set>
#include<queue>
#include<algorithm>
using namespace std;
const double pi=acos(-1.0);
double s,r,v,h;
double f(double r)
{
    double temp=sqrt(s*s-2*s*pi*r*r);
    temp*=r;
    temp/=3;
    return temp;
}
int main(void)
{
    double ll,rr,mid1,mid2;
    while(cin>>s)
    {
        ll=0;
        rr=sqrt(s/(2*pi));
        while(rr-ll>FLT_EPSILON)
        {
            double temp=(rr-ll)/3;
            mid1=ll+temp;
            mid2=rr-temp;
            if(f(mid1)<f(mid2))
                ll=mid1;
            else
                rr=mid2;
        }
        r=rr;
        h=sqrt(s*s-2*s*pi*r*r)/(pi*r);
        v=pi*r*r*h/3;
        printf("%.2lf\n%.2lf\n%.2lf\n",v,h,r);
    }
    return 0;

}

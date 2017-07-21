#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<string>
#include<cfloat>
#include<sstream>
#include<set>
#include<queue>
#include<algorithm>
using namespace std;
double y,xiao,da;
double f(double x)
{
    double temp=8*x*x*x*x+7*x*x*x+2*x*x+3*x+6;
    return temp;
}
int main(void)
{
    double ll,rr,mid;
    int t;
    cin>>t;
    xiao=f(0);
    da=f(100);

    while(t--)
    {
        cin>>y;
        if((y<xiao)||(y>da))
            printf("No solution!\n");
        else
        {
            ll=0;
            rr=100;
            while(rr-ll>FLT_EPSILON)
            {
                mid=(ll+rr)/2;
                if(f(mid)<y)
                    ll=mid;
                else
                    rr=mid;
            }
            printf("%.4lf\n",rr);
        }
    }
    return 0;
}

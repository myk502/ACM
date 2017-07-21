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
double r,R,h,v,h1,r1,ans,leftt,rightt,temp;
const double pi=acos(-1.0);
int main(void)
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>r>>R>>h>>v;
        leftt=0;
        rightt=h;
        while(rightt-leftt>FLT_EPSILON)
        {
            h1=(leftt+rightt)/2;
            r1=h1/h*(R-r)+r;
            temp=pi*h1*(r1*r1+r*r+r1*r)/3;
            if (fabs(temp-v)<FLT_EPSILON)
                break;
            if(temp>v)
            {
                rightt=h1;
            }
            else
            {
                leftt=h1;
            }
        }
        printf("%.6lf\n",leftt);
    }
    return 0;
}

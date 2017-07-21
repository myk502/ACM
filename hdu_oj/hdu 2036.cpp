#include<bits/stdc++.h>
using namespace std;
int n;
class Point
{
public:
    long long x,y;
    Point(long long xx=0,long long yy=0):x(xx),y(yy){}
};
Point P[110];
double area(const Point &p,const Point &q)
{
    return(p.x*q.y-q.x*p.y);
}
int main(void)
{
    long long xx,yy;
    double ans;
    while(cin>>n)
    {
        if(n==0)
            break;
        for(int i=0;i<n;i++)
        {
            cin>>xx>>yy;
            P[i]=Point(xx,yy);
        }
        ans=area(P[n-1],P[0]);
        for(int i=1;i<n;i++)
            ans+=area(P[i-1],P[i]);
        ans/=2;
        printf("%.1f\n",ans);

    }
    return 0;
}

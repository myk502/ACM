#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
const double eps=1e-2;
const double pi=acos(-1);
struct Point
{
    double x,y;
    Point(){}
    Point(double xx,double yy):x(xx),y(yy)
    {
    }
};
Point A,B,C;
double a,b,c,S,r;
double aa,bb,cc;//the angle of A,B,C(radian messure)

double gcd(double x,double y)
{
    while(fabs(x)>eps && fabs(y)>eps)
    {
        if(x>y)
            x-=floor(x/y)*y;
        else
            y-=floor(y/x)*x;

    }
    return x+y;
}

double cal_triangle_a(double a,double b,double c)//the return value is between[0,pi)
{
    double temp=b*b+c*c-a*a;
    temp/=2*b*c;
    return acos(temp);
}

double get_area(double a,double b,double c)
{
    double p=(a+b+c)/2;
    return sqrt(p*(p-a)*(p-b)*(p-c) );

}
double dis(Point X,Point Y)
{
    return sqrt((X.x-Y.x)*(X.x-Y.x)+(X.y-Y.y)*(X.y-Y.y) );
}
int main(void)
{
    int n;
    double angle;
    cin>>A.x>>A.y>>B.x>>B.y>>C.x>>C.y;
    a=dis(B,C);
    b=dis(A,C);
    c=dis(A,B);
    S=get_area(a,b,c);
    r=a*b*c/(4*S);//the radius of the polygon
    aa=cal_triangle_a(a,r,r);
    bb=cal_triangle_a(b,r,r);
    cc=2*pi-aa-bb;
    angle=gcd(aa,gcd(bb,cc));
    n=(2*pi)/angle+eps;
    double ss=0.5*r*r*sin(angle);
    printf("%.8lf\n",ss*n);
    return 0;
}

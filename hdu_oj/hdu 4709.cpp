#include<bits/stdc++.h>
using namespace std;
class Point
{
public:
    double x,y;
    Point(double xx=0,double yy=0):x(xx),y(yy){}
    double dis(const Point& X)const
    {
        double temp=(X.x-x)*(X.x-x)+(X.y-y)*(X.y-y);
        return sqrt(temp);
    }
};
double Area2(Point p,Point q,Point s)//2 times the area,in the direction(p,q,s)(directed area)
{
    return
        p.x*q.y-p.y*q.x
       +q.x*s.y-q.y*s.x
       +s.x*p.y-s.y*p.x;
}
int n;
Point P[110];
int main(void)
{
    int t,num;
    double xx,yy;//num means the number of triangles
    double ans=-1;
    cin>>t;
    for(int ii=0;ii<t;ii++)
    {
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>xx>>yy;
            P[i]=Point(xx,yy);
        }
        num=0;
        ans=-1;
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
                for(int k=j+1;k<n;k++)
                {
                    double temp=fabs(Area2(P[i],P[j],P[k]));
                    temp/=2;
                    if(fabs(temp-0)<FLT_EPSILON)
                        continue;
                    num++;//the number of triangles increases
                    if(ans==-1)
                        ans=temp;
                    else if(ans>temp)
                        ans=temp;
                }
        if(num==0)
            cout<<"Impossible"<<endl;
        else
            printf("%.2f\n",ans);
    }
    return 0;
}

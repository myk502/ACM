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
double Area2(Point p,Point q,Point r)
{
    return q.x*r.y-q.y*r.x
          +p.y*r.x-p.x*r.y
          +p.x*q.y-p.y*q.x;
}
bool ToLeft(Point p,Point q,Point r)//because there is no point on the line so it is easy
{
    return Area2(p,q,r)>0;
}
class Rectangle
{
public:
    Point ltl,htr;//lowest-then-leftmost,highest-then-rightmost
    Rectangle(double ltl_xx=0,double ltl_yy=0,double htr_xx=0,double htr_yy=0)
    :ltl(ltl_xx,ltl_yy),htr(htr_xx,htr_yy)
    {
    }
    bool contains(const Point &p)const
    {
        return((p.x>=ltl.x)&&(p.x<=htr.x)&&(p.y>=ltl.y)&&(p.y<=htr.y));
    }
};
class Circle
{
public:
    double r;
    Point origin;
    Circle(double xx=0,double yy=0,double rr=0):origin(xx,yy),r(rr){}
    bool contains(const Point &p)const
    {
        double dist=p.dis(origin);
        return(dist<=r);
    }
};
class Triangle
{
public
:
    Point p,q,r;
    Triangle(double p_x=0,double p_y=0,double q_x=0,double q_y=0,double r_x=0,double r_y=0)
    :p(p_x,p_y),q(q_x,q_y),r(r_x,r_y){}
    bool contains(const Point &s)const
    {
        bool pqLeft=ToLeft(p,q,s);
        bool qrLeft=ToLeft(q,r,s);
        bool rpLeft=ToLeft(r,p,s);
        return(pqLeft==qrLeft&&qrLeft==rpLeft);
    }
};
vector<Circle>circle;
vector<Triangle>triangle;
vector<Rectangle>rectangle;
void readin(void)
{
    int n;
    double temp[10];
    string type;
    circle.clear();
    triangle.clear();
    rectangle.clear();
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>type;
        if(type=="C")//this is a circle
        {
            for(int j=0;j<3;j++)
                cin>>temp[j];
            circle.push_back(Circle(temp[0],temp[1],temp[2]));
        }
        if(type=="R")
        {
            for(int j=0;j<4;j++)
                cin>>temp[j];
            rectangle.push_back(Rectangle(temp[0],temp[1],temp[2],temp[3]));
        }
        if(type=="T")
        {
            for(int j=0;j<6;j++)
                cin>>temp[j];
            triangle.push_back(Triangle(temp[0],temp[1],temp[2],temp[3],temp[4],temp[5]));
        }
    }
}
Point get_point(void)
{
    double xx,yy;
    cin>>xx>>yy;
    return Point(xx,yy);
}
int main(void)
{
    int round;
    int num_Hannah,num_Bob;
    Point user_input;
    readin();
    cin>>round;
    for(int i=0;i<round;i++)
    {
        num_Hannah=num_Bob=0;
        //Bob's play
        for(int j=0;j<3;j++)
        {
            user_input=get_point();
            for(auto it:circle)
                if(it.contains(user_input))
                    num_Bob++;
            for(auto it:rectangle)
                if(it.contains(user_input))
                    num_Bob++;
            for(auto it:triangle)
                if(it.contains(user_input))
                    num_Bob++;
        }
        //Hannah's play
        for(int j=0;j<3;j++)
        {
            user_input=get_point();
            for(auto it:circle)
                if(it.contains(user_input))
                    num_Hannah++;
            for(auto it:rectangle)
                if(it.contains(user_input))
                    num_Hannah++;
            for(auto it:triangle)
                if(it.contains(user_input))
                    num_Hannah++;
        }
        if(num_Bob>num_Hannah)
            cout<<"Bob"<<endl;
        else if(num_Bob==num_Hannah)
            cout<<"Tied"<<endl;
        else
            cout<<"Hannah"<<endl;
    }
    return 0;
}

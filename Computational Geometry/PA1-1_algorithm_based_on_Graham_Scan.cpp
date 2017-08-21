#include"Vector.h"
#include"Stack.h"
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
//using namespace std;
const int maxn=1e5+10;
class Point
{
public:
    long long x,y;
    int id;//for the answer output
    Point(long long xx,long long yy):x(xx),y(yy){}
    Point(void){}
    bool operator ==(const Point &X)
    {
        return(x==X.x)&&(y==X.y);
    }
};
std::ostream &operator<<(std::ostream& out,Point &X)
{
    printf("(%lld,%lld)",X.x,X.y);
    return out;
}
Point P[maxn];
int n;
void readin(Point P[])
{
    std::cin>>n;
    long long xx,yy;
    for(int i=0;i<n;i++)
    {
        scanf("%lld%lld",&xx,&yy);
        P[i].x=xx;
        P[i].y=yy;
        P[i].id=i+1;
    }
}
int LTL(Point P[],int n)
{
    int ltl=0;
    for(int i=1;i<n;i++)
    {
        if(P[i].y<P[ltl].y||(P[i].y==P[ltl].y&&(P[i].x<P[ltl].x)))
            ltl=i;
    }
    return ltl;
}
long long Area2(Point p,Point q,Point s)
{
    return q.x*s.y-q.y*s.x
           -(p.x*s.y-p.y*s.x)
           +p.x*q.y-p.y*q.x;

}
bool between(Point p,Point q,Point s)//whether q is in between p and s
{
    return((q.x-p.x)*(s.x-q.x)+(q.y-p.y)*(s.y-q.y)>0);
}
bool ToLeft(Point p,Point q,Point s)
{
    long long temp=Area2(p,q,s);
    if(temp!=0)
        return(temp>0);
    return between(p,q,s);//important!
}
int cmp(const void *a,const void *b)
{
    const Point *A=(Point*)a;
    const Point *B=(Point*)b;
    if(ToLeft(P[0],*A,*B))
        return -1;
    else
        return 1;
}
int main(void)
{
    //freopen("in.txt","r",stdin);
    //freopen("out1","w",stdout);
    long long ans=1,cnt=0;
    readin(P);
    int ltl=LTL(P,n);
    std::swap(P[0],P[ltl]);
    qsort(P+1,n-1,sizeof(Point),cmp);
    /*
    for(int i=0;i<n;i++)
        std::cout<<P[i]<<std::endl;
    */
    //std::cout<<"Then is the extreme Point:"<<std::endl;
    Stack<Point> S,T;
    S.push(P[0]);
    S.push(P[1]);
    for(int i=n-1;i>1;i--)
        T.push(P[i]);
    //the construction of two stacks
    //Graham Scan
    while(!T.empty())
        if(ToLeft(S.second(),S.top(),T.top()))
            S.push(T.pop());
        else
            S.pop();
    Point temp=S.top();//temp is the last found extreme point
    for(int i=0;i<n;i++)
    {
        if(P[i]==P[0]||(P[i]==temp))
            continue;
        if(Area2(P[0],P[i],temp)==0LL)
        {
            ans*=P[i].id;
            cnt++;
            ans%=n+1;

        }
    }
    for(int i=0;i<S.size();i++)
    {
        ans*=S[i].id;
        cnt++;
        ans%=n+1;
        //std::cout<<S[i]<<std::endl;
    }
    ans*=cnt;
    ans%=n+1;
    std::cout<<ans;
    return 0;
}

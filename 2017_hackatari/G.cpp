#include<bits/stdc++.h>
using namespace std;
class Student
{
public:
    int id;
    int score;
    double possibility;
    Student(int id=0,int score=0,double possibility=0):id(id),score(score),possibility(possibility){}
    bool operator <(const Student &X)const
    {
        return score<X.score;
    }
    bool operator <=(const Student &X)const
    {
        return score<=X.score;
    }
    bool operator >(const Student &X)const
    {
        return score>X.score;
    }
    bool operator >=(const Student &X)const
    {
        return score>=X.score;
    }
    bool operator ==(const Student &X)const
    {
        return score==X.score;
    }
    bool operator <(int x)const
    {
        return score<x;
    }
    bool operator <=(int x)const
    {
        return score<=x;
    }
    bool operator >(int x)const
    {
        return score>x;
    }
    bool operator >=(int x)const
    {
        return score>=x;
    }
    bool operator ==(int x)const
    {
        return score==x;
    }
    friend bool operator <(int x,const Student &X)
    {
        return x<X.score;
    }
    friend bool operator <=(int x,const Student &X)
    {
        return x<=X.score;
    }
    friend bool operator >(int x,const Student &X)
    {
        return x>X.score;
    }
    friend bool operator >=(int x,const Student &X)
    {
        return x>=X.score;
    }

};
const int maxn=1e5+10;
Student a[maxn];
double p[maxn];
double pre[maxn];
int n,sa;//sa is the score of problem A

int main(void)
{
    double ans=0;
    int L,R;
    cin>>n>>sa;
    for(int i=0;i<n;i++)
        scanf("%lf",&a[i].score);
    for(int i=0;i<n;i++)
    {
        double temp;
        scanf("%lf",&temp);
        a[i].possibility=1-temp;
    }
    pre[0]=0;
    for(int i=0;i<n;i++)
        pre[i+1]=pre[i]+1-a[i].possibility;
    for(int i=0;i<n;i++)//对于第i个学生，分析
    {
        auto Left=upper_bound(a,a+i,a[i].score+sa);//we can take it
        auto Right=lower_bound(a,a+i,a[i].score);//we can not take it
        L=Left-a;
        R=Right-a;
        if(R==i)
            L=0;

        //cout<<L<<" "<<R<<endl;
        double pos=pre[R]-pre[L];
        ans+=a[i].possibility*pos;
    }
    printf("%.9f\n",ans);
    return 0;
}

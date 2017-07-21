#include<bits/stdc++.h>
using namespace std;
long long Height,Width,n;
double dist[110][110],d[110],zuida=1e13;
bool visit[110];
class Point
{
public:
    long long x,y;
    Point(long long xx,long long yy):x(xx),y(yy){}
    Point& operator =(const Point& X)
    {
        x=X.x;
        y=X.y;
        return *this;
    }
};
class Rect
{
public:
    long long height,width,dis,spot;
    Point down(void)const
    {
        if(spot==0)//left side!
            return Point(width,dis);
        else
            return Point(Width-width,dis);
    }
    Point up(void)const
    {
        if(spot==0)
            return(Point(width,dis+height));
        else
            return(Point(Width-width,dis+height));
    }
};

istream& operator >>(istream &in,Rect &X)
{
    scanf("%I64d%I64d%I64d%I64d",&X.height,&X.width,&X.dis,&X.spot);
    return in;
}
ostream& operator <<(ostream &out,const Rect &X)
{
    printf("%I64d %I64d %I64d %I64d",X.height,X.width,X.dis,X.spot);
    return out;
}
double dis(Point &X,Point &Y)
{
    double temp1=(X.x-Y.x);
    double temp2=(X.y-Y.y);
    double temp=temp1*temp1+temp2*temp2;
    return sqrt(temp);
}
double dis(Rect X,Rect Y)
{
    if (X.dis>Y.dis) swap(X,Y);//X is below Y
    if(X.spot==Y.spot)
        return (Y.dis-(X.dis+X.height));
    else//2 sides
    {
        if(X.dis+X.height>=Y.dis)
            return Width-X.width-Y.width;
        else if(X.width+Y.width>=Width)
            return(Y.dis-(X.dis+X.height));
        else
        {
            Point A=X.down();
            Point B=X.up();
            Point C=Y.down();
            Point D=Y.up();
            double minn=dis(A,C);
            minn=min(minn,dis(A,D));
            minn=min(minn,dis(B,C));
            minn=min(minn,dis(B,D));
            return minn;
        }
    }
}
Rect P[110];
int main(void)
{
    freopen("street.in","r",stdin);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>Height>>Width;
        for(int i=1;i<=n;i++)
            cin>>P[i];
        for(int i=0;i<=n+1;i++)
            dist[i][i]=0;
        for(int j=1;j<=n;j++)
        {
            dist[0][j]=dist[j][0]=P[j].dis;
            //printf("dist[0][%d]=%.6f\n",j,dist[0][j]);
        }
        dist[n+1][0]=dist[0][n+1]=Height;
        for(int i=1;i<=n;i++)
            dist[i][n+1]=dist[n+1][i]=Height-P[i].dis-P[i].height;

        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
               dist[j][i]=dist[i][j]=dis(P[i],P[j]);
            }
        }
        /*
        for(int i=0;i<=n+1;i++)
        {
            for(int j=i+1;j<=n+1;j++)
            {
                printf("dist[%d][%d]=%.6f\n",i,j,dist[i][j]);
            }
        }
        */
        for(int i=0;i<=n+1;i++)
            d[i]=zuida;
        d[0]=0;
        memset(visit,0,sizeof(visit));
        while(1)
        {
            //printf("mark1\n");
            int v=-1;
            for(int i=0;i<=n+1;i++)
            {
                if(!visit[i]&&((v==-1)||(d[i]<d[v])))
                    v=i;
            }
            if(v==-1)
                break;
            visit[v]=true;
            for(int i=0;i<=n+1;i++)
            {
                d[i]=min(d[i],d[v]+dist[v][i]);
            }
        }
        printf("%.6f\n",d[n+1]);
    }
    return 0;
}

#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
int nn,n,m,k,a[60][60];
int dis(int a,int b,int c,int d)
{
    int ans=0;
    ans+=abs(c-a);
    ans+=abs(d-b);
    return ans;
}
struct Point
{
    int x,y,num;
    Point(int x=0,int y=0,int c=0):x(x),y(y),num(c){}
};
int dis(Point X,Point Y)
{
    return dis(X.x,X.y,Y.x,Y.y);
}
bool cmp(Point X,Point Y)
{
    if(X.num==Y.num)
        return X.x<Y.x;
    return(X.num>Y.num);
}
int to_road(Point X)
{
    return X.x;
}
vector<Point> P;
int main(void)
{
    //freopen("in","r",stdin);
    int t,ans;
    Point now;
    cin>>t;
    while(t--)
    {
        ans=0;
        P.clear();
        cin>>n>>m>>k;
        memset(a,0,sizeof(a));
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
            {
                scanf("%d",&a[i][j]);
                if(a[i][j]!=0)
                    P.push_back(Point(i,j,a[i][j]));
            }
        sort(P.begin(),P.end(),cmp);
        nn=P.size();
        if(2*to_road(P[0])+1<=k)
        {
            ans+=P[0].num;
            k-=to_road(P[0])+1;
            now=P[0];
        }
        else
        {
            cout<<0<<endl;
            continue;
        }
        for(int i=1;i<nn;i++)
        {
            if(dis(now,P[i])+1+to_road(P[i])<=k)
            {
                ans+=P[i].num;
                k-=dis(now,P[i])+1;
                now=P[i];
            }
            else
                break;
        }
        cout<<ans<<endl;
    }
    return 0;
}

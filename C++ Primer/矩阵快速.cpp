#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<string>
#include<sstream>
#include<set>
#include<cfloat>
#include<queue>
#include<algorithm>
using namespace std;
int n,f,r[10000+10];
const double pi=acos(-1.0);
double v[10000+10];
int F(double x)
{
    int num=0;
    for(int i=1;i<=n;i++)
    {
        num+=(int)(v[i]/x);
    }
    return num;

}
int main(void)
{
    int t;
    double left,right,sum,min_v,mid;
    cin>>t;
    while(t--)
    {
        cin>>n>>f;
        min_v=1000000;
        sum=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&r[i]);
            v[i]=pi*r[i]*r[i];
            min_v=min(min_v,v[i]);
            sum+=v[i];

        }
        left=min_v/(f+1);
        right=sum/(f+1);
        //cout<<left<<endl<<right<<endl;
        while(right-left>FLT_EPSILON)
        {
            mid=(left+right)/2;
            if(F(mid)<f+1)
            {
                right=mid;

            }
            else
            {
                left=mid;
            }
        }
        printf("%.10f\n",left);


    }
    return 0;
}

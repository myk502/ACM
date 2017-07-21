#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
struct record
{
    int time;
    int position;
};
const int maxn=10000+10;
record a[maxn+10];
int t,n;
bool cmp(record aa,record bb)
{
    return(aa.time<bb.time);
}
int main(void)
{
    cin>>t;
    double ans=-1;
    for(int ii=1;ii<=t;ii++)
    {
        cin>>n;
        ans=-1;
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&a[i].time,&a[i].position);
        }
        sort(a,a+n,cmp);
        for(int i=1;i<n;i++)
        {
            double temp=fabs((double)(a[i].position-a[i-1].position))/(double)(a[i].time-a[i-1].time);
            //cout<<temp<<endl;
            ans=max(temp,ans);
        }
        printf("Case #%d: %.2f\n",ii,ans);
    }
    return 0;
}

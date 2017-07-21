#include<bits/stdc++.h>
using namespace std;
int n,m;
double min_height,max_height,a[35][35];
double v;
int check(double x)//检查如果水位为x，最后的体积与题目给的是否符合
{
    double temp=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if(a[i][j]<x)
                temp+=(x-a[i][j])*100;
        }
    //printf("The input is %.2f and the Volumn is %.2f\n",x,temp);
    if(fabs(temp-v)<0.0001)
        return 0;
    if(temp>v)
        return 1;
    if(temp<v)
        return -1;
}//如果正好，返回0；如果试探值太大，返回1,太小返回-1
double cal(double lo,double hi)
{
    while(hi-lo>0.00001)
    {
        double mi=(hi+lo)/2;
        int temp=check(mi);
        if(temp!=1)
            lo=mi;
        else
            hi=mi;
    }
    return lo;
}
int main(void)
{
    int testcase=0;
    double ans,sum;
    while(cin>>n>>m)
    {
        if((m==0)&&(n==0))
            break;
        testcase++;
        printf("Region %d\n",testcase);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                cin>>a[i][j];
        min_height=max_height=a[1][1];
        sum=0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
            {
                min_height=min(min_height,a[i][j]);
                max_height=max(max_height,a[i][j]);
                sum+=a[i][j];
            }
        cin>>v;
        if(check(max_height)==1)
            ans=cal(min_height,max_height);//take into consideration: v==0;ans>max_height
        else
        {
            ans=(v/100)+sum;
            ans/=(n*m);
        }
        int cnt=0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                if(a[i][j]<ans)
                    cnt++;
        printf("Water level is %.2f meters.\n",ans);
        printf("%.2f percent of the region is under water.\n",100.0*(double)cnt/(double)(n*m));
        cout<<endl;

    }
    return 0;
}

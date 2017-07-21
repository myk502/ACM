#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int t,n,m;
int b[10000+10],a[1000000+10];
int N[10000+10];
void build_next(void)
{
    int j=0;
    int t=N[0]=-1;
    while(j<m-1)
        if(0>t||b[j]==b[t])
        {
            j++;
            t++;
            N[j]=(b[j]!=b[t]?t:N[t]);
        }
        else
            t=N[t];
}
int match(void)
{
    int i=0,j=0;
    while((j<m)&&(i<n))
    {
        if((0>j)||a[i]==b[j])
        {
            i++;
            j++;
        }
        else
            j=N[j];
    }
    return i-j;
}
int main(void)
{
    int ans;
    cin>>t;
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        for(int i=0;i<m;i++)
            scanf("%d",&b[i]);
        if(n>=m)
        {
            build_next();
            ans=match()+1;
            if((ans<1)||(ans+m-1>n))
                ans=-1;
        }
        else
            ans=-1;
        printf("%d\n",ans);
    }
    return 0;
}

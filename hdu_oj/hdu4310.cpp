#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<iostream>
#include<string.h>
#include<iso646.h>
using namespace std;

struct myk{
int health;
int dps;
double rate;};
myk a[25];
bool cmp(myk x,myk y)
{
    return(x.rate<y.rate);
}
int main(void)
{
    int n,ans,dps_all,turn;
    while(cin>>n)
    {
        turn=dps_all=ans=0;
        for(int i=0;i<n;i++)
        {
            cin>>a[i].dps>>a[i].health;
            dps_all+=a[i].dps;
            a[i].rate=1.0*a[i].health/a[i].dps;
        }
        sort(a,a+n,cmp);
        //a[0].health-=1;
        for(int i=0;i<n;i++)
        {
            ans+=dps_all*a[i].health;
            dps_all-=a[i].dps;
        }
        cout<<ans<<endl;
    }
    return 0;
}

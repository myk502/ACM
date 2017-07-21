#include<cmath>
#include<cstring>
#include<iostream>
#include<cstdio>
using namespace std;
bool status[220];
long long cnt=0LL;
int main(void)
{
    for(int i=1;i<220;i++)
        status[i]=false;
    for(int i=1;i<=210;i++)
    {
        if( (i%2!=0) && (i%3!=0) && (i%5!=0) &&(i%7!=0) )
        {
            status[i]=true;
            cnt++;
        }
    }
   // for(int i=1;i<=210;i++)
   //     printf("status[%d]=%d\n",i,status[i]);
    long long x;
    cin>>x;
    long long ans=0;
    ans+=(x/210LL)*cnt;
    int y=x%210;
    for(int i=1;i<=y;i++)
    {
        if(status[i])
            ans++;
    }
    cout<<ans<<endl;
    return 0;
}

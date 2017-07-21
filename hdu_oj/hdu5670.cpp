#include<bits/stdc++.h>
using namespace std;
long long m,n;
long long pow3(long long i)
{
    long long ans=1,pow=3;
    while(i>0)
    {
        if(i&1)
            ans*=pow;
        i>>=1;
        pow*=pow;
    }
    return ans;

}
void showColor(int x)
{
    if(x==0)
        printf("R");
    if(x==1)
        printf("G");
    if(x==2)
        printf("B");
}
int main(void)
{
    int T;
    cin>>T;
    while(T--)
    {
        cin>>m>>n;
        for(long long i=m;i>=1;i--)
        {
            long long color=(n%pow3(i))/pow3(i-1);
            showColor(color);
        }
        printf("\n");
    }
    return 0;
}

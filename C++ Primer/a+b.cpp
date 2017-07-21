#include<iostream>
using namespace std;

long long power(long long a,long long n,long long Mod)
{
    long long pow=1;
    long long p=a;
    while(n>0)
    {
        if(n&1)
            pow*=p;
        n>>=1;
        p*=p;
    }
    return pow;
}
int main(void)
{
    cout<<power(2,5,1000001);
    return 0;
}

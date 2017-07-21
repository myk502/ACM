#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    long long ans=1,n=20;
    while(n>=1)
    {
        ans*=n;
        n--;
    }
    cout<<ans<<endl;
    return 0;
}

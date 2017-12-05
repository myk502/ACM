#include<bits/stdc++.h>
using namespace std;
long long n,k,a;
int main(void)
{
    scanf("%lld",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&a);
        k+=a-1;
        printf("%d\n",k%2?1:2);
    }
    return 0;
}

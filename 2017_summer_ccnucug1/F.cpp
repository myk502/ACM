#include<cstdio>
#include<cmath>
#include<algorithm>
#include<climits>
#include<iostream>
using namespace std;
int s;
int ans=INT_MAX;
int main(void)
{
    cin>>s;
    for(int i=1;i<=sqrt(s)+0.5;i++)
    {
        int j=s/i;
        if((long long)i*(long long)j!=(long long)s)
            continue;
        int temp=(i+i+j+j);
        ans=min(ans,temp);
    }
    cout<<ans<<endl;

    return 0;
}

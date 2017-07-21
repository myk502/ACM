#include<bits/stdc++.h>
using namespace std;
int c,v0,v1,a,l;
int main(void)
{
    cin>>c>>v0>>v1>>a>>l;
    int cnt=v0,day=1;
    while(cnt<c)
    {
        cnt+=min(v0+day*a-l,v1-l);
        day++;
    }
    cout<<day<<endl;
    return 0;
}

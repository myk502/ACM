#include<bits/stdc++.h>
using namespace std;
int cnt=0;
int solve(int x)
{
    int cnt=0;
    while(x)
    {
        if(x%10==1)
            cnt++;
        x/=10;
    }
    return cnt;
}
int main(void)
{
    for(int i=0;i<1000;i++)
        cnt+=solve(i);
    cout<<cnt<<endl;
    return 0;
}

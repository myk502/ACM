#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
int n,m,a;
int main(void)
{
    cin>>n>>m>>a;
    int ans1=n/a;
    if(n%a!=0)
        ans1++;
    int ans2=m/a;
    if(m%a!=0)
        ans2++;
    cout<<(long long)ans1*(long long)ans2<<endl;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
long long n;
int t;
int main(void)
{
    cin>>t;
    for(int i=0;i<t;i++)
    {
        cin>>n;
        double x=log10(n);
        x=x*n;
        //cout<<"x="<<x<<endl;
        double y=floor(x);
        double z=pow(10,x-y);
        cout<<floor(z)<<endl;
    }

    return 0;
}

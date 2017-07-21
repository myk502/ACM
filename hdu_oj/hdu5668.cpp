#include<bits/stdc++.h>
using namespace std;

int main(void)
{    
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int ans=-1;
    for(int i=0;i<1e4;i++)
    {
        int temp=b+i*a-d;
        if((temp%c==0)&&(temp>=0))
        {
            ans=b+i*a;
            break;
        }

    }

    cout<<ans;
    return 0;    
}

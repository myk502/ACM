#include<bits/stdc++.h>
using namespace std;
int n;
int main(void)
{
    bool flag_0,flag_1;
    int T,input;
    cin>>T;
    while(T--)
    {
        flag_0=flag_1=false;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&input);
            if(input==0)
                flag_0=true;
            if(input==1)
                flag_1=true;
        }
        if(flag_0&&flag_1)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}

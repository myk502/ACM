#include<bits/stdc++.h>
using namespace std;
int t,r[70],l[70];
unsigned long long ll,rr;
int get_r(long long x)
{
    int index=0;
    memset(r,0,sizeof(r));
    while(x)
    {
        r[index]=x%2;
        x/=2;
        index++;
    }
    return index-1;
}
int get_l(long long x)
{
    int index=0;
    memset(l,0,sizeof(l));
    while(x)
    {
        l[index]=x%2;
        x/=2;
        index++;
    }
    return index-1;
}
int main(void)
{
    unsigned long long sum;
    int length,length_l,length_r;
    cin>>t;
    while(t--)
    {
        cin>>ll>>rr;
        length_l=get_l(ll);
        length_r=get_r(rr);
        length=max(length_l,length_r);
        sum=0;
        for(int i=length;i>=0;i--)
        {
            if(l[i]==r[i])
            {
                if(l[i]==1)
                    sum+=(long long)pow(2,i);
            }
            else
            {
                sum+=(long long)pow(2,i+1)-1;
                break;
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}

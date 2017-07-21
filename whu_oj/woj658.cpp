#include<bits/stdc++.h>
using namespace std;
deque<int> dq;
const long long Mod=1000000000+7;
const int maxn=100000+10;
long long length;//this length is mod by Mod
int a[maxn],n;
int backup[maxn<<1];
deque<int>::iterator it_begin,it_end,it;
long long ans;
int main(void)
{
    int T;
    cin>>T;
    for(int ii=1;ii<=T;ii++)
    {
        length=ans=0;
        dq.clear();
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            if((a[i]==-1)&&dq.empty())//empty and pop,no result
                continue;
            if(a[i]>0)
            {
                dq.push_front(a[i]);
                length=(length+1)%Mod;
                ans=(ans*2333+length)%Mod;
            }
            if(a[i]==-1)
            {
                ans=(ans*2333+dq.front())%Mod;
                dq.pop_front();
                length=(length-1+Mod)%Mod;
            }
            if(a[i]==0)
            {
                length=length*2;
                length%=Mod;
                ans=(ans*2333+length)%Mod;
                if(dq.size()>200000)
                    continue;
                else
                {
                    int num=0;
                    for(auto it:dq)
                        backup[num++]=it;
                    for(int i=0;i<num;i++)
                        dq.push_back(backup[i]);
                }

            }
        }
        printf("CASE #%d: ",ii);
        cout<<ans<<endl;
    }
    return 0;
}

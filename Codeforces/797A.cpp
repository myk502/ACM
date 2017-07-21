#include<bits/stdc++.h>
using namespace std;
const int maxn=100000+10;
bool isprime[maxn];
int prime[maxn];
vector<int> factor;
void Prepare_prime(void)
{
    for(int i=0;i<maxn;i++)
        isprime[i]=true;
    prime[0]=0;
    isprime[0]=isprime[1]=false;
    for(int i=2;i<maxn;i++)
    {
        if(isprime[i])//if i is a prime
            prime[++prime[0]]=i;
        for(int j=1;(j<=prime[0])&&((double)prime[j]<(double)maxn/(double)i);j++)
        {
            isprime[i*prime[j]]=false;
            if(i%prime[j]==0)
                break;
        }

    }
}
int main(void)
{
    int n,k;
    Prepare_prime();
    cin>>n>>k;
    factor.clear();
    for(int i=1;i<=prime[0];i++)
    {
        if(prime[i]>n)
            break;
        while(n%prime[i]==0)
        {
            n/=prime[i];
            factor.push_back(prime[i]);
        }
    }
    if(k>factor.size())
        printf("-1");
    else
    {
        for(int i=0;i<k-1;i++)
            printf("%d ",factor[i]);
        int ans=1;
        for(int i=k-1;i<factor.size();i++)
            ans*=factor[i];
        printf("%d",ans);
    }
    return 0;
}

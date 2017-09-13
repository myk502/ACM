#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;
typedef long long ll;
const int maxn=505;
const ll mod=1000000007;
int prime[maxn];
ll pownum[maxn];
ll n,k;
int bound;

void getprime()//素数筛选
{
    memset(prime,0,sizeof(prime));
    for(int i=2;i<=maxn;i++)
    {
        if(!prime[i]) prime[++prime[0]]=i;
        for(int j=1;j<=prime[0]&&prime[j]<=maxn/i;j++)
        {
            prime[prime[j]*i]=1;
            if(i%prime[j]==0) break;
        }
    }
}

//对于某数b,n!|b^k的b的个数
ll fun(ll k)
{
    ll ans=1;
    for(int i=1;i<=bound;i++)
    {
        ans*=(pownum[i]/k+1);//乘法原理
        ans%=mod;
    }
    return ans;
}

ll cal(int i)//求n!含有prime[i]的个数
{
    ll exp=0;
    ll tmp=n;
    while(tmp)
    {
        tmp/=prime[i];
        exp+=tmp;
    }
    return exp;
}

int main()
{
    ios::sync_with_stdio(false);
    getprime();
//    cout<<prime[0]<<endl;
//    for(int i=1;i<=96;i++)
//    {
//        cout<<prime[i]<<" ";
//        if(i%10==0) cout<<endl;
//    }
    int t;
    cin>>t;
    int cas=0;
    while(t--)
    {
        cin>>n>>k;
	bound=96;
        for(int i=1;i<=96;i++)//503 第96个素数
        {
            pownum[i]=cal(i);
        }
        cout<<"case "<<++cas<<": "<<((fun(k)-fun(k+1)%mod+mod))%mod<<endl;
    }
    return 0;
}

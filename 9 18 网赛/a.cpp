#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
#define F(x,a,b) for (ll x=a;x<=b;x++)
long long Mod;
const long long maxn=100005;
long long prime[maxn];
bool isprime[maxn];
struct P_factor
{
    long long p,k;
    P_factor()
    {
        p=k=0;
    }
    P_factor(long long x,long long y)
    {
        p=x;
        k=y;
    }
};
vector<P_factor> ANS_factor;
void prepare_prime()
{
    for(ll i=0;i<maxn;i++)
        isprime[i]=1;
    isprime[1]=0;
    prime[0]=0;
    for(long long i=2;i<maxn;i++)
    {
        if(isprime[i])
        {
            prime[++prime[0]]=i;
        }
        for(long long j=1;j<=prime[0];j++)
        {
            if(i*prime[j]>=maxn)
                break;
            isprime[i*prime[j]]=0;
            if(i%prime[j]==0)
                break;
        }
    }
}
vector <P_factor> divide_factor(long long x)
{
    vector <P_factor> R;
    R.clear();
    for(long long i=1;i<=prime[0];i++)
    {
        long long p=prime[i];
        if(p*p>x)
            break;
        long long k=0;
        while(x%p==0)
        {
            x/=p;
            k++;
        }
        if(k)R.push_back(P_factor(p,k));
    }
    if(x>1)R.push_back(P_factor(x,1));
    return R;
}


struct Mat
{
    long long line;
    long long column;
    long long a[5][5];//注意!!!根据题目需要更改大小
    Mat()
    {
        memset(a,0,sizeof(a));
        line=column=4;//同上！！！这里是初始化为单位矩阵，但是在正式写代码时不建议用这个，用下面那个比较好
        a[1][1]=a[2][2]=a[3][3]=a[4][4]=1;
    }
    Mat(long long x,long long y)
    {
        line=x;
        column=y;
        memset(a,0,sizeof(a));
    }
};
Mat MulMat(Mat A,Mat B,long long MOD)//A's column and B's line must be equal
{
    long long aa,bb,cc;
    aa=A.line;
    bb=A.column;
    cc=B.column;
    Mat C(aa,cc);
    for(long long i=1;i<=aa;i++)
    {
        for(long long j=1;j<=cc;j++)
        {
            for(long long k=1;k<=bb;k++)
            {
                C.a[i][j]+=(A.a[i][k]*B.a[k][j])%MOD;
                C.a[i][j]%=MOD;
            }
        }
    }
    return C;
}
Mat FastMod(Mat A,long long n,long long Mod)
{
    Mat E;
    if(n==0)
        return E;
    if(n==1)
        return A;
    if(n%2==1)
    {
        //prlong longf("step1\n");
        return(MulMat(A,FastMod(A,n-1,Mod),Mod));
    }
    else
    {
        Mat temp=FastMod(A,n/2,Mod);
        //prlong longf("step 2\n");
        return(MulMat(temp,temp,Mod));
    }
}
Mat operator *(const Mat& A,const Mat& B)
{
    return(MulMat(A,B,Mod));
}
long long t;
long long cnt,n,y,s,x,g;//g represents g(n*y)
long long Calculate_g(long long x)
{
    Mat M(4,4);
    Mat _M(4,4);
    if(x==1)
        return 1;
    if(x==2)
        return 5;
    M.a[1][1]=1;
    M.a[1][2]=1;
    M.a[2][2]=4;
    M.a[2][3]=9;
    M.a[2][4]=4;
    M.a[3][2]=1;
    M.a[4][3]=2;
    M.a[4][4]=1;
    //printf("MARK1\n");
    _M=FastMod(M,x-1,Mod);

    Mat B(4,1);
    B.a[1][1]=1;
    B.a[2][1]=4;
    B.a[3][1]=1;
    Mat _ANS(4,1);
    _ANS=_M*B;
    return(_ANS.a[1][1]);
}
long long Divide_factor(long long x)
{
    long long kk=0;
    ANS_factor=divide_factor(x);
    /*while(!ANS.empty())
    {
        P_factor temp=ANS.back();
        ANS.pop_back();
        ANS_factor[kk].p=temp.p;
        ANS_factor[kk].k=temp.k;
        kk++;
    }*/
    return ANS_factor.size();
}
long long QuickMod(long long x,long long n,long long MOD)//for long longeger
{
    if(n==0)
        return 1;
    if(n==1)
        return (x%MOD);
    if(n%2==0)
    {
        long long temp=QuickMod(x,n/2,MOD);
        return((temp*temp)%MOD);
    }
    else
    {
        return((x%MOD)*QuickMod(x,n-1,MOD))%MOD;
    }
}
ll phi(ll x)
{
        ll c=0; ll cntt=1;
        ll res=x;
        ll sqrtx=(long long)sqrt(x);
        while (prime[cntt]<=sqrtx)
        {
          if(x%prime[cntt]==0) res=res/prime[cntt]*(prime[cntt]-1);
          while (x%prime[cntt]==0)
          {
              x/=prime[cntt];
          }
          cntt++;
        }
        if(x>1) res=res/x*(x-1);
        return res;
}
int main(void)
{
    prepare_prime();
    //printf("%d",isprime[14593]);
    //F(i,2,403) if (334%i==0) cout<<i<<endl;
    cin>>t;
    while(t--)
    {
        cin>>n>>y>>x>>s;
        ll ph=phi(s+1);
        Mod=ph;
        g=Calculate_g(n*y);
        cout<<g<<endl;
        //cout<<n*y<<endl;
        cnt=Divide_factor(x);
        //F(i,0,cnt-1) cout<<ANS_factor[i].p<<" "<<ANS_factor[i].k<<endl;
        ll anss=1;
        F(i,0,cnt-1)
        {
            anss*=QuickMod(ANS_factor[i].p,ANS_factor[i].k*g%Mod,Mod)%(s+1);
        }
        cout<<anss%(s+1)<<endl;
    }
    return 0;
}

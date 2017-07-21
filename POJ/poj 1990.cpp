#include<cstdio>
#include<cstring>
#include<iso646.h>
#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<cmath>
#include<algorithm>
#define ll long long
using namespace std;
const long long maxn=40000;
struct myk
{
    long long v;
    long long x;
};
myk a[maxn];
long long n,tree1[maxn],tree2[maxn];//tree1 记录x出现的总次数，tree2记录x的和
bool cmp(myk aa,myk bb)
{
    return(aa.v<bb.v);
}
void add(long long tree[],long long k,long long num)
{
    while(k<maxn)
    {
        tree[k]+=num;
        k+=k&(-k);
    }
}
long long read(long long tree[],long long k)
{
    long long sum=0;
    while(k)
    {
        sum+=tree[k];
        k-=k&(-k);
    }
    return sum;
}
int main(void)
{
    long long sum=0,total_sum=0,cnt=0,ans=0;
    cin>>n;
    memset(tree1,0,sizeof(tree1));
    memset(tree2,0,sizeof(tree2));
    for(int i=1;i<=n;i++)
        cin>>a[i].v>>a[i].x;
    sort(a+1,a+n+1,cmp);
    //printf("At first ans=%lld\n",ans);
    for(int i=1;i<=n;i++)
    {
        sum=read(tree2,a[i].x);
        //printf("1:Now i=%d and ans=%I64d\n",i,ans);
        cnt=read(tree1,a[i].x);
        //printf("2:Now i=%d and ans=%lld\n",i,ans);
        ans+=(cnt*a[i].x-sum+(total_sum-sum)-(i-cnt-1)*a[i].x)*a[i].v;
        //printf("3:Now i=%d and ans=%lld\n",i,ans);
        total_sum+=a[i].x;
        add(tree1,a[i].x,1);
        add(tree2,a[i].x,a[i].x);
    }
    cout<<ans;
    return 0;
}

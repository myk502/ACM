#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
const int maxn=500000+10;
int l,n,m,maxm;
int a[maxn];
int idx(int dis)//to find the closest stone before dis
//or to say,the most far stone the frog could jump to
{
    auto ptr=upper_bound(a,a+n+2,dis);
    int id=ptr-a-1;
    //printf("dis=%lld id=%d\n",dis,id);
    return id;
}
bool isok(int x)//to testify if our ability is x,could we cross the river within  m times
{
    if(x<maxm)
        return false;
    //printf("We are testing %lld\n",x);
    int i,id=0,cnt=0;//we start at 0, cnt means the minimum times we jump
    while(id!=n+1)
    {
        for(i=id+1;i<=n+1;i++)
            if(a[i]-a[id]>x)
            {
                id=i-1;
                cnt++;
                break;
            }
        if(i==n+2)
        {
            id=n+1;
            cnt++;
        }
    }
    return cnt<=m;
}
int main(void)
{
    while(cin>>l>>n>>m)
    {
        maxm=-1;
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        a[0]=0LL;
        a[n+1]=l;
        sort(a,a+n+2);
        for(int i=1;i<=n+1;i++)
            maxm=max(maxm,a[i]-a[i-1]);
        if(n==0)
        {
            cout<<l<<endl;
            continue;
        }
        if(m==n+1)
        {
            cout<<maxm<<endl;
            continue;
        }
        int ll=maxm-1,rr=l;//(ll,rr]
        //cout<<"MARK1"<<endl;
        while(rr-ll>1)
        {
            int mid=(ll+rr)/2;
            if(isok(mid))
                rr=mid;
            else
                ll=mid;
        }
        //cout<<"MARK2"<<endl;
        cout<<rr<<endl;
    }
    return 0;
}

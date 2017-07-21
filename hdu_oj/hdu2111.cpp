#include<cstdio>
#include<cstring>
#include<cmath>
#include<climits>
#include<iostream>
#include<algorithm>
using namespace std;
struct myk{
int price;
int weight;
double rate;};
myk a[110];
int v,n;//c is price while w is weight
bool cmp(myk x,myk y)
{
    return (x.price>y.price);
}
int main(void)
{
    int ans,w;
    while(scanf("%d",&v))
    {
        if(v==0)
            break;
        cin>>n;
        for(int i=0;i<n;i++)//counting from 1
        {
            cin>>a[i].price>>a[i].weight;
            a[i].rate=a[i].price/a[i].weight;
        }
        sort(a,a+n,cmp);
        ans=w=0;
        for(int i=0;i<n;i++)
        {
            if(w+a[i].weight>v)
            {
                ans+=a[i].price*(v-w);
                break;
            }
            ans+=a[i].price*a[i].weight;
            w+=a[i].weight;
        }
        cout<<ans<<endl;
    }

    return 0;
}

#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
int n,m,k,ans,pos;
const int maxn=1e6+10;
bool is_hole[maxn];
int main(void)
{
    cin>>n>>m>>k;
    memset(is_hole,0,sizeof(is_hole));
    int input,u,v;
    for(int i=0;i<m;i++)
    {
        scanf("%d",&input);
        is_hole[input]=true;
    }
    ans=-1;
    pos=1;
    if(is_hole[1])
        ans=1;
    for(int i=0;i<k;i++)
    {
        scanf("%d%d",&u,&v);
        if(ans!=-1)
            continue;//The bone is already in a hole
        if(u==pos)
            pos=v;
        else if(v==pos)
            pos=u;
        if(is_hole[pos])
            ans=pos;
    }
    if(ans==-1)
        ans=pos;
    cout<<ans<<endl;

        

    return 0;
}

#include<cstdio>
#include<cstring>
#include<iostream>
#include<climits>
#include<cmath>
#include<string>
#include<sstream>
#include<set>
#include<map>
#include<queue>
#include<algorithm>
using namespace std;
int a[1000000+10],p,temp,l,r,n;
map<int,int> beifen,x;
int main(void)
{
    int ans;
    cin>>p;
    for(int i=1;i<=p;i++)
    {
        scanf("%d",&temp);
        a[i]=temp;
        beifen[temp]++;//important! when the key 'temp' does not exist,then a new key 'temp'is created when its value is initialized to 0
    }
    l=1;
    r=1;
    ans=INT_MAX;
    //x[a[1]]++;
    n=beifen.size();
    while(1)
    {
        while((r<=p)&&(x.size()<n))
        {
            x[a[r++]]++;
        }
        if(x.size()<n)
            break;
        ans=min(ans,r-l);
        l++;
        x[a[l-1]]--;
        if(x[a[l-1]]<=0)
            x.erase(a[l-1]);

    }
    cout<<ans<<endl;

    return 0;
}

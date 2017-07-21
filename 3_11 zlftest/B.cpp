#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
int a[10000+10],l,m;
int main(void)
{
    int start,finish,cnt=0;
    cin>>l>>m;
    for(int i=0;i<=l;i++)
        a[i]=1;
    for(int ii=0;ii<m;ii++)
    {
        cin>>start>>finish;
        for(int i=start;i<=finish;i++)
            a[i]=0;
    }
    for(int i=0;i<=l;i++)
        cnt+=a[i];
    cout<<cnt;
    return 0;
}

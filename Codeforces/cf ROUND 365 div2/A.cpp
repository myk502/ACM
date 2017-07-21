#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<climits>
#include<cfloat>
#include<map>
#include<set>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int n,m,c,a,b;
int main(void)
{
    cin>>n;
    m=c=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a>>b;
        if(a>b)
            m++;
        if(a<b)
            c++;
    }
    if(m>c)
        printf("Mishka");

    if(m==c)
        printf("Friendship is magic!^^");
    if(m<c)
        printf("Chris");
    return 0;
}

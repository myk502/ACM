#include<bits/stdc++.h>
using namespace std;
int n,m,a[10000],b,minx;
int main(void)
{
    scanf("%d%d%d\n",&n,&m,&b);
    minx=n;
    for(int i=1;i<=n;i++)
        scanf("%c",&a[i]);
    if(a[m]==a[b])
        printf("0");
    else
        printf("1");
    return 0;
}

#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<stack>
#include<set>
#include<algorithm>
using namespace std;
const long long MOD=1000000000+27;
char s[400000+10];
long long a[400000+10],n,expp[400000+10];//expp[i] means 31^i
void init(void)
{
    expp[0]=1;
    for(int i=1;i<400000+10;i++)
        expp[i]=(expp[i-1]*31)%MOD;
}
int main(void)
{
    init();
    while(scanf("%s",s+1)!=EOF)
    {
        memset(a,0,sizeof(a));
        a[0]=0;
        n=strlen(s+1);
        a[1]=(s[1]-'a'+1);
        for(int i=2;i<=n;i++)
        {
            a[i]=(a[i-1]+expp[i-1]*(s[i]-'a'+1))%MOD;
        }
        for(int i=1;i<=n;i++)
        {
            long long tempa=(a[i])%MOD,tempb=(a[n]-a[n-i]+MOD)%MOD;
            if((tempa*expp[n-i])%MOD==tempb)
                printf("%d ",i);
        }
        printf("\n");
    }
    return 0;
}

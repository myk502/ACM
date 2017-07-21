#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <vector>
#include <bitset>
using namespace std;

#define bll long long
#define dou double
#define For(i,a,b) for (int i=(a),_##i=(b); i<=_##i; i++)
#define Rof(i,a,b) for (int i=(a),_##i=(b); i>=_##i; i--)
#define rep(i,a,b) for (int i=(a),_##i=(b); i<=_##i; i++)
#define rek(i,a,b) for (int i=(a),_##i=(b); i>=_##i; i--)
#define Mem(a,b) memset(a,b,sizeof(a))
#define Cpy(a,b) memcpy(a,b,sizeof(b))

int gcd(int a,int b)
{
    if (b==0) return a;
    return gcd(b,a%b);
}

int main(int argc, char* argv[])
{
    int zz=0; 
    scanf("%d",&zz);
    for (int test=1; test<=zz; test++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        if (y%x!=0)
        {
            printf("0\n");
            continue;
        }
        int r=y/x;
        int ans=0;
        for (int i=1; i*i<=r; i++)
            if (r%i==0 && gcd(i,r/i)==1)
            {
                ans++;
                if (i!=r/i) ans++; 
            }
        printf("%d\n",ans);
    }
    return 0;
}
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <cstring>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <algorithm>
using namespace std;

#define LL long long
#define min(a, b) (a < b? a: b)
#define max(a, b) (a > b? a: b)
#define abs(a) (a > 0? a: -a)

const LL MOD = 1000000000 + 7;
const int maxn = 1000000 + 100;
int cas, T;
LL n, m, k;
LL inv[maxn], pro[maxn], invpro[maxn];

LL fast_pow(LL res, LL n)
{
    LL ans = 1;
    for(; n != 0; n >>= 1)
    {
        if((n & 1LL) == 1)
        {
            ans = (ans * res) % MOD;
        }
        res = (res * res) % MOD;
    }
    return ans;
}

void Init()
{
    inv[1] = 1;
    for(int i = 2; i < maxn; ++i)
    {
        inv[i] = (LL)(MOD - MOD / i) * inv[MOD % i] % MOD;
    }
}

LL get_C(LL m, LL k)
{
    LL ans = 1;
    for(LL i = 1; i <= k; ++i)
    {
        ans = (ans * (m - i + 1) % MOD) * inv[i] % MOD;
    }
    return ans;
}

LL solve(LL n, LL m, LL k)
{
    LL flag;
    LL ans = get_C(m, k);
    LL tmp = 0;
    LL x = 1;
    if(k % 2 == 1)
    {
        flag = 1;
    }
    else
    {
        flag = -1;
    }
    for(LL i = 1; i <= k; ++i)
    {
        x = (x * (k - i + 1) % MOD * inv[i]) % MOD;
        tmp = (tmp + ((x * i % MOD * fast_pow(i - 1, n - 1) % MOD) * flag + MOD) % MOD) % MOD;
        flag = -flag;
    }
    ans = (ans * tmp) % MOD;
    return ans;
}

int main()
{
    #ifdef LOCAL
    freopen("test.txt", "r", stdin);
    #endif // LOCAL
    //ios::sync_with_stdio(false);

    cas = 0;
    Init();
    scanf("%d", &T);
    while(T--)
    {
        scanf("%I64d%I64d%I64d", &n, &m, &k);
        printf("Case #%d: %I64d\n", ++cas, solve(n, m, k));
    }

    return 0;
}

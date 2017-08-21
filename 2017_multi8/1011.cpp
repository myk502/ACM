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
#include <algorithm>
using namespace std;

#define LL long long
#define min(a, b) (a < b? a: b)
#define max(a, b) (a > b? a: b)
#define abs(x) (x >= 0? x: -x)

const LL MOD = 1000000000 + 7;
const int maxn = 2000 + 100;
int T;
int n, m;
LL ans;
LL C[maxn][maxn];
LL fac[maxn];
long long CC[maxn][maxn];
void Init() {
    fac[0] = 1;
    fac[1] = 1;
    for(int i = 2; i < maxn; ++i) {
        fac[i] = (fac[i - 1] * i) % MOD;
    }
    C[0][0] = 1;
    for(int i = 1; i < maxn; ++i) {
        for(int j = 0; j < i; ++j) {
            if(j == 0) {
                C[i][j] = 1;
            }
            else {
                C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
            }
        }
        C[i][i] = 1;
    }
}


LL dp(int i, int j) {
    return (C[i - 1][j - 1] * fac[j]) % MOD;
}

LL fast_pow(LL res, int n) {
    LL ans;
    for(ans = 1; n != 0; n >>= 1) {
        if((n & 1) == 1) {
            ans = (ans * res) % MOD;
        }
        res = (res * res) % MOD;
    }
    return ans;
}

int main() {
    #ifdef LOCAL
    freopen("test.txt", "r", stdin);
    #endif // LOCAL
    ios::sync_with_stdio(false);

    Init();
    scanf("%d", &T);
    while(T--) {
        ans = 0;
        scanf("%d%d", &n, &m);
        for(int i = 1; i < m; ++i) {
            ans += (((dp(n, i) * fast_pow(m - i, n)) % MOD) * C[m][i]) % MOD;
            ans %= MOD;
        }
        printf("%I64d\n", ans);
    }

    return 0;
}

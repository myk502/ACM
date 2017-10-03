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
#include <ctime>
#include <functional>
#include <iomanip>
using namespace std;

#define LL long long

const int maxn = 50000 + 100;
const LL MOD = 1000000007;
int T, n, k;
LL sum[maxn];
LL sum_pow[maxn][200];
char str[maxn];
LL num[maxn];
LL ssum[maxn][200];
LL C[200][200];

void Init() {
    C[0][0] = 1;
    for(int i = 1; i < 200; ++i) {
        for(int j = 0; j <= i; ++j) {
            if(j == 0 || j == i) {
                C[i][j] = 1;
            } else {
                C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
				/*
				if(i <= 20 && j <= 20)
					printf("C[%d][%d] = %lld\n",i,j,C[i][j]);
				*/
            }
        }
    }
}

LL fast_pow(LL res, LL n) {
    LL ans = 1;
    for(; n != 0; n >>= 1) {
        if((n & 1LL) == 1LL) {
            ans *= res;
            ans %= MOD;
        }
        res *= res;
        res %= MOD;
    }
    return ans;
}

int main() {
    #ifdef LOCAL
    freopen("test.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(false);

    Init();
    cin >> T;
    while(T--) {
        cin >> n >> k;
        cin >> str;
        sum[0] = 0;
        int len = strlen(str);
        for(int i = 0; str[i]; ++i) {
            num[i + 1] = str[i] - '0';
            sum[i + 1] = (sum[i] + num[i + 1]) % MOD;
			//printf("sum[%d] = %lld\n",i + 1,sum[i + 1]);
        }
        for(int i = 0; i <= len; ++i) {
            if(i == 0) {
                sum_pow[i][0] = 1;
            } else {
                sum_pow[i][0] = 1;
            }
            for(int j = 1; j <= k; ++j) {
                sum_pow[i][j] = sum_pow[i][j - 1] * sum[i] % MOD;
                sum_pow[i][j] %= MOD;
				//printf("sum_pow[%d][%d] = %lld\n",i,j,sum_pow[i][j]);
            }
        }
        for(int i = 0; i <= len; ++i) {
            ssum[i][0] = i + 1;
        }
        for(int j = 1; j <= k; ++j) {
            ssum[0][j] = 0;
            for(int i = 1; i <= len; ++i) {
                ssum[i][j] = ssum[i - 1][j] + sum_pow[i][j];
				//printf("ssum[%d][%d] = %lld\n",i,j,ssum[i][j]);
            }
        }
        LL f = 1;
        for(int i = 1; i <= len; ++i) {
			f = 1;
            LL ans = 0;
            for(int p = 0; p <= k; ++p) {
                ans += (f * ((C[k][p] * sum_pow[i][k - p] % MOD) * ssum[i - 1][p] % MOD) ) % MOD;
				ans += MOD;
                ans %= MOD;
                f *= -1;
            }
            if(i != 1) {
                cout << " ";
            }
            cout << ans;
        }
        cout << endl;
    }

    return 0;
}

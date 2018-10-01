#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <algorithm>
#include <functional>
#include <iomanip>
using namespace std;

#define LL long long
const int maxn = 2000 + 100;
struct Node {
    int l, r;
};
bool operator<(const Node &a, const Node &b) {
    if(a.l == b.l) {
        return a.r < b.r;
    }
    return a.l < b.l;
}
int T, n, m, k, x, rr;
Node node[maxn];
int dpr[maxn][maxn];
int dp[maxn][maxn];

int main() {
    #ifdef LOCAL
    freopen("test.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    #endif // LOCAL
//    ios::sync_with_stdio(false);


    scanf("%d", &T);
    int cas = 0;
    while(T--) {
        printf("Case #%d: ", ++cas);
        scanf("%d%d%d", &n, &m, &k);
        for(int i = 1; i <= m; ++i) {
            scanf("%d%d", &node[i].l, &node[i].r);
        }
        for(int i = 0; i <= m; ++i) {
            for(int j = 0; j <= k; ++j) {
                dp[i][j] = dpr[i][j] = 0;
            }
        }
        sort(node + 1, node + m + 1);
        for(int i = 1; i <= m; ++i) {
            for(int j = 1; j <= k; ++j) {
                if(node[i].l <= dpr[i - 1][j - 1]) {
                    if(node[i].r <= dpr[i - 1][j - 1]) {
                        x = 0;
                        rr = dpr[i - 1][j - 1];
                    } else {
                        x = node[i].r - dpr[i - 1][j - 1];
                        rr = node[i].r;
                    }
                } else {
                    x = node[i].r - node[i].l + 1;
                    rr = node[i].r;
                }
                if(dp[i - 1][j] > dp[i - 1][j - 1] + x) {
                    dp[i][j] = dp[i - 1][j];
                    dpr[i][j] = dpr[i - 1][j];
                } else if(dp[i - 1][j] == dp[i - 1][j - 1] + x) {
                    dp[i][j] = dp[i - 1][j];
                    dpr[i][j] = min(dpr[i - 1][j], rr);
                } else {
                    dp[i][j] = dp[i - 1][j - 1] + x;
                    dpr[i][j] = rr;
                }
//                printf("x = %d\n", x);
//                printf("dp[%d][%d] = %d\n", i, j, dp[i][j]);
//                printf("dpr[%d][%d] = %d\n", i, j, dpr[i][j]);
            }
        }
        printf("%d\n", dp[m][k]);
    }

    return 0;
}

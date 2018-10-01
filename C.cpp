#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

#define LL long long
int T;
int x, y, k;

int main() {
    #ifdef LOCAL
    freopen("test.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    #endif // LOCAL
//    ios::sync_with_stdio(false);

    int cas = 0;
    scanf("%d", &T);
    while(T--) {
        printf("Case #%d: ", ++cas);
        scanf("%d%d%d", &x, &y, &k);
        if(x > y) {
            printf("%d\n", k);
            continue;
        } else {
            printf("%d\n", (k * x * 11) / (2 * x + 11 * y));
        }
    }

    return 0;
}

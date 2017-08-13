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
#define For(i, a, b) for(int i = (a), _##i = (b); i <= _##i; ++i)
#define Rof(i, a, b) for(int i = (a), _##i = (b); i >= _##i; --i)
#define Mem(a, b) memset(a, b, sizeof(a))
#define Cpy(a, b) memcpy(a, b, sizeof(b))

const int maxn = 100000 + 100;
int T, n, m, num;
vector<int> ans;
map<int, int> mp, mptmp;
map<int, int>::iterator it;

int Log(int n) {
    int ret = 0;
    while(n % 2 == 0) {
        n /= 2;
        ++ret;
    }
    return ret;
}

int main() {
    #ifdef LOCAL
    freopen("test.txt", "r", stdin);
    #endif // LOCAL
    ios::sync_with_stdio(false);

    scanf("%d", &T);
    while(T--) {
        ans.clear();
        mp.clear();
        scanf("%d%d", &n, &m);
        scanf("%d", &num);
        mp[0] = num - 1;
        if(mp[0] != 0) {
            int tmp = Log(num);
            while(tmp--) {
                ans.push_back(0);
            }
        }
        For(i, 1, m) {
            scanf("%d", &num);
            while(mp[i] < num) {
//                printf("mp[%d] = %d\n", i, mp[i]);
                mptmp = mp;
                ans.push_back(i);
                for(it = mptmp.begin(); it != mptmp.end(); ++it) {
                    int tmp = it->first + i;
                    mp[tmp] += it->second;
                }
                ++mp[i];
            }
        }
        int len = ans.size();
        For(i, 0, len - 1) {
            if(i != 0) printf(" ");
            printf("%d", ans[i]);
        }
        printf("\n");
    }

    return 0;
}

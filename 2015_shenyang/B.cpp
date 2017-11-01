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

const int maxcnt = 500 * 2000 + 100;
const int Size = 30;
struct ac_auto {
    int cnt, root;
    int tree[maxcnt][Size], tr[maxcnt][Size], fail[maxcnt];
    int que[maxcnt];
    vector<int> val[maxcnt];
    int head, tail;

    int create() {
        ++cnt;
        memset(tree[cnt], 0, sizeof(tree[cnt]));
        memset(tr[cnt], 0, sizeof(tr[cnt]));
        fail[cnt] = 0;
        val[cnt].clear();
        return cnt;
    }

    void Init() {
        head  = tail = 0;
        cnt = 0;
        root = create();
    }

    inline int id(const char &ch) {
        return ch - 'a';
    }

    void add(char *s, int v) {
        int pos = root;
        for(int i = 1; s[i]; ++i) {
            int w = id(s[i]);
            if(!tree[pos][w]) {
                tree[pos][w] = create();
            }
            pos = tree[pos][w];
        }
        val[pos].push_back(v);
    }

    void build() {
        que[tail++] = root;
        fail[root] = 0;
        for(; head < tail; ++head) {
            int x = que[head];
            for(int i = 0; i < Size; ++i) {
                int it = tree[x][i];
                if(it > 0) {
                    int pos = fail[x];
                    while(pos > 0 && tree[pos][i] == 0) {
                        pos = fail[pos];
                    }
                    fail[it] = (pos > 0? tree[pos][i]: root);
                    que[tail++] = it;
                }
            }
        }
        for(int i = 0; i < Size; ++i) {
            tr[root][i] = (tree[root][i]? tree[root][i]: root);
        }
        for(int i = 1; i < tail; ++i) {
            int x = que[i];
            for(int j = 0; j < Size; ++j) {
                tr[x][j] = (tree[x][j]? tree[x][j]: tr[fail[x]][j]);
            }
        }
    }

    int query(char *s, int v) {
        int pos = root;
        int ret = 0;
        for(int i = 1; s[i]; ++i) {
            int w = id(s[i]);
            pos = tr[pos][w];
            int ptmp = pos;
            while(ptmp != root) {
                vector<int>::iterator it = lower_bound(val[ptmp].begin(), val[ptmp].end(), v);
                ret += it - val[ptmp].begin();
                ptmp = fail[ptmp];
            }
//            printf("%c = %d\n", s[i], ret);
        }
        return ret;
    }
};
const int maxn = 500 + 100;
const int maxm = 2000 + 100;
ac_auto t;
int T, ans, n, cas;
char str[maxn][maxm];

int main() {
    #ifdef LOCAL
    freopen("test.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    #endif // LOCAL
    ios::sync_with_stdio(false);

    scanf("%d", &T);
    while(T--) {
        ans = -1;
        t.Init();
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i) {
            scanf("%s", str[i] + 1);
            t.add(str[i], i);
//            printf("%s\n", str[i] + 1);
        }
        t.build();
        for(int i = 1; i <= n; ++i) {
            int tmp = t.query(str[i], i);
            if(tmp != i - 1) {
                ans = i;
//                printf("temp = %d   ans = %d\n", tmp, ans);
            }
        }
        printf("Case #%d: %d\n", ++cas, ans);
    }

    return 0;
}

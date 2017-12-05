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
const int maxn = 10000 + 100;
const LL MOD = 100000007;
int T;
char str[maxn];
int num[10][10];
int a[maxn];

int main() {
    #ifdef LOCAL
    freopen("test.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    #endif // LOCAL
    ios::sync_with_stdio(false);

    num[0][0] = 1;
    num[1][1] = 4;
    num[2][2] = 6;
    num[3][3] = 4;
    num[4][4] = 1;
    scanf("%d", &T);
    while(T--) {
        scanf("%s", str);
        int len = strlen(str);
        bool flag = true;
        for(int i = 0; i < len; ++i) {
            if(str[i] < '0' || str[i] > '6') {
                flag = false;
                break;
            }
        }
        if(!flag) {
            printf("0\n");
            continue;
        }
        if(len == 1) {
            if(str[0] == '0' || str[0] == '2') {
                printf("1\n");
            } else if(str[0] == '1') {
                printf("2\n");
            } else {
                printf("0\n");
            }
            continue;
        } else if(len == 2) {
            if(str[0] == str[1] && str[0] <= '4' && str[0] >= '0') {
                printf("%d\n", num[str[0] - '0'][str[1] - '0']);
            } else {
                printf("0\n");
            }
            continue;
        }
        LL ans = 0;
        for(int i = 0; i <= 2; ++i) {
            a[0] = i;
            a[1] = str[0] - '0' - a[0];
            bool flag = true;
            if(a[1] >= 0 && a[1] <= 2) {
                for(int j = 2; j < len; ++j) {
                    a[j] = str[j - 1] - '0' - a[j - 1] - a[j - 2];
                    if(a[j] < 0 || a[j] > 2) {
                        flag = false;
                        break;
                    }
                }
                if(a[len - 1] + a[len - 2] != str[len - 1] - '0') {
                    flag = false;
                }
            } else {
                flag = false;
            }
            if(flag) {
                LL tmp = 1;
                for(int i = 0; i < len; ++i) {
                    if(a[i] == 1) {
                        tmp = tmp * 2 % MOD;
                    }
                }
                ans = (ans + tmp) % MOD;
            }
        }
        printf("%d\n", (int)ans);
     }
    return 0;
}

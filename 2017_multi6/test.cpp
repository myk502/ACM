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
#define min(a, b) (a < b? a: b)
#define max(a, b) (a > b? a: b)

const int maxn = 5000 + 100;
int T, m, ans;
char str[maxn];
int dissum[maxn];

int main() {
    ios::sync_with_stdio(false);

    scanf("%d", &T);
    while(T--) {
        ans = 0;
        scanf("%d", &m);
        scanf("%s", str);
        int len = strlen(str);
//        printf("len = %d\n", len);
        // first type
        for(int i=0;i<len-1;i++)//The center is at the right position of i
		{
            int Len = min(len - i  - 1, i+1);
			int ll=i-Len+1;
            dissum[ll] = 0;
//            printf("i = %d\n", i);
            for(int j=ll;j<=i;j++)
			{
                dissum[j + 1] = dissum[j] + abs(str[j] - str[2*i+1-j]);
            }
//            For(j, 0, Len + 1) printf("%d\n", dissum[i]);
            for(int j=ll;j<=i;j++)//The start point
			{
                if(j + ans > i+1) break;
                if(dissum[j + ans] - dissum[j]> m) continue;
                int *it = upper_bound(dissum + j + 1, dissum + i + 2, dissum[j] + m);
                ans = max( (it - dissum) - j - 1, ans);
//                printf("ans = %d\n", ans);
            }
        }
        // 不算
        for(int i=1;i<len-1;i++)
		{
            int Len = min(i, len - i - 1);
			int ll=i-Len;
			dissum[ll]=0;
            for(int j=ll;j<i;j++)
			{
                dissum[j+1] = dissum[j] + abs(str[j] - str[2 * i - j]);
            }
			for(int j=ll;j<i;j++)
            {
                if(j + ans > i) break;
                if(dissum[j + ans] - dissum[j] > m) continue;
                int *it = upper_bound(dissum + j + 1, dissum + i + 1, dissum[j] + m);
                ans = max(it - dissum - 1 -j , ans);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}

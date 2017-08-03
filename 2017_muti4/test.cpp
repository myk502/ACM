
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

const LL maxn = 1000000 + 100;
const LL MOD = 998244353;
LL T;
LL l, r, k;
LL cnt;
LL prime[maxn];
bool vis[maxn];
LL num[maxn];
LL ans[maxn];
bool visit[maxn];

void Prime(LL n)
{
    cnt=0;
    memset(vis,0,sizeof(vis));
    for(LL i=2; i<n; i++)
    {
        if(!vis[i])
        {
            prime[cnt++]=i;
        }
        for(LL j=0; j<cnt&&i*prime[j]<n; j++)
        {
            LL k=i*prime[j];
            vis[k]=1;
            if(i%prime[j]==0)
            {
                break;
            }
        }
    }
}

int main() {
    #ifdef LOCAL
    freopen("test.txt", "r", stdin);
    #endif // LOCAL
    ios::sync_with_stdio(true);

    Prime(maxn);
    scanf("%I64d", &T);
    while(T--) {
        Mem(visit, 0);
        scanf("%I64d%I64d%I64d", &l, &r, &k);
        LL n = r - l + 1;
        for(LL i = 0; i < n; ++i) {
            num[i] = l + i;
            ans[i] = 1;
        }
        for(LL i = 0; i < cnt; ++i) {
            LL pos;
            if(l % prime[i] == 0) {
                pos = 0;
            } else {
                LL X = l / prime[i];
                pos = X * prime[i] + prime[i] - l;
                if(pos > r - l) {
                    continue ;
                }
            }
            for(LL j = pos; j < n; j += prime[i]) {
                LL Ans = 0;
                visit[j] = true;
                while(num[j] % prime[i] == 0) {
                    ++Ans;
                    num[j] /= prime[i];
                }
                ans[j] = (ans[j] * (Ans * k + 1) % MOD) % MOD;
            }
        }
        for(LL i = 0; i < n; ++i) {
            if(num[i] != 1) {
                ans[i] = (ans[i] * (1 * k + 1) % MOD) % MOD;
            }
        }
        LL aans = 0;
        For(i, 0, n - 1) {
            aans = (aans + ans[i]) % MOD;
        }
        printf("%I64d\n", aans);
    }

    return 0;
}



------------------ 原始邮件 ------------------
发件人: "东16孟永康";<525039107@qq.com>;
发送时间: 2017年8月3日(星期四) 下午4:00
收件人: "1595038502"<1595038502@qq.com>;
主题: Prime factor

http://blog.csdn.net/fanesemyk/article/details/52126758


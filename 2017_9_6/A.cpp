#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <string>
#include <climits>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
// 单点替换、增减、区间求和、最值
const int maxn = 100000+10;
const int INF = INT_MAX;
typedef long long LL;
LL n;

LL Max[maxn << 2], Min[maxn << 2], sum[maxn << 2];
// maxn 为原数组大小，数组下标从1 开始到n，树跟下标为1
void pushup(LL rt) {
    Max[rt] = max(Max[rt << 1LL], Max[rt << 1LL | 1LL]);
    Min[rt] = min(Min[rt << 1LL], Min[rt << 1LL | 1LL]);
    sum[rt] = sum[rt << 1LL] + sum[rt << 1LL | 1LL];
}
// 建立线段树
void build(LL l, LL r, LL rt) {
    if(l == r) {
        scanf("%lld", &sum[rt]);
        Max[rt] = Min[rt] = sum[rt];
        return ;
    }
    LL m = (l + r) >> 1LL;
    build(l, m, rt << 1LL);
    build(m + 1LL, r, rt << 1LL | 1LL);
    pushup(rt);
}

// 单[p]点更新值为tmp
void update(LL p, LL tmp, LL l, LL r, LL rt) {
    if(l == r) {
        sum[rt] = Min[rt] = Max[rt] = tmp;
        return ;
    }
    LL m = (l + r) >> 1LL;
    if(p <= m) update(p, tmp, l, m, rt << 1LL);
    else update(p, tmp, m + 1LL, r, rt << 1LL | 1LL);
    pushup(rt);
}

// 区间[L, R] 求和
LL query_sum(LL L, LL R, LL l, LL r, LL rt) {
    if(L <= l && r <= R) return sum[rt];
    LL m = (l + r) >> 1LL;
    LL ret = 0LL;
    if(L <= m) ret += query_sum(L, R, l, m, rt << 1LL);
    if(R > m) ret += query_sum(L, R, m + 1LL, r, rt << 1LL | 1LL);
    return ret;
}

LL quary(LL num, LL l, LL r, LL rt)
{
    if(l == r && num<= sum[rt])
    {
        return l;
    }
    LL m = (l+r) >> 1LL;
    LL sum1 = sum[rt<<1];
    if(sum1 >= num)
    {
        return quary(num, l, m, rt<<1LL);
    }
    else
    {
        return quary(num-sum1, m+1LL, r, rt<<1LL|1LL);
    }
}

int main()
{
    while(scanf("%lld",&n)!=EOF)
    {
        build(1LL,n,1LL);
        int m;
        scanf("%d",&m);
        for(int i=0; i<m; i++)
        {
            char str[10];
            scanf("%s",str);
            if(str[0] == 'p')
            {
                LL a,b;
                scanf("%lld%lld",&a,&b);
                update(a,b,1,n,1);
            }
            else
            {
                LL num;
                scanf("%lld",&num);
                LL ans = quary(num,1,n,1);
                printf("%lld\n",ans);
            }
        }
    }
    return 0;
}

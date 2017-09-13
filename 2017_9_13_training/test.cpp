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
using namespace std;

#define LL long long
#define min(a, b) (a < b? a: b)
#define max(a, b) (a > b? a: b)
#define abs(a) (a > 0? a: -a)

const int Log = 30;
const int maxn = 1500000+ 100;
LL num[maxn];
LL Min[maxn][Log];
LL Max[maxn][Log];
int n;
//LL ans;
vector<int> Index[maxn];
vector<int>::iterator it;

void Init() //建立： dp(i,j) = min{dp(i,j-1),dp(i+2^(j-1),j-1)   O(nlogn)
{
    for(int i = 1; i <= n; ++i)
    {
        Max[i][0] = Min[i][0] = num[i];
    }
    int k = floor(log((double)n) / log(2.0)); //C/C++取整函数ceil()大,floor()小
    for(int j = 1; j <= k; ++j)
    {
        for(int i = n; i >= 1; --i)
        {
            if(i + (1 << (j - 1)) <= n) //f(i,j) = min{f(i,j-1),f(i+2^(j-1),j-1)
            {
                Max[i][j] = max(Max[i][j - 1], Max[i + (1 << (j - 1))][j - 1]);
                Min[i][j] = min(Min[i][j - 1], Min[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
}

LL get_Min(int i, int j)  //查询：返回区间[i,j]的最小值     O(1)
{
    int k = floor(log((double)(j - i + 1))/log(2.0));
    return min(Min[i][k], Min[j - (1 << k) + 1][k]);
}

LL get_Max(int i, int j)
{
    int k = floor(log((double)(j - i + 1))/log(2.0));
    return max(Max[i][k], Max[j - (1 << k) + 1][k]);
}

void get_Index(int l, int r, LL &ret, int &dex, bool small, int NNN)
{
    if(small)
    {
        ret = get_Min(l, r);
    }
    else
    {
        ret = get_Max(l, r);
    }
    int len = Index[ret].size();
    it = lower_bound(Index[ret].begin(), Index[ret].end(), l);
    for(int i = it - Index[ret].begin(); i < len; ++i)
    {
        if(Index[ret][i] >= l && Index[ret][i] <= r && Index[ret][i] != NNN)
        {
            dex = Index[ret][i];
            return ;
        }
    }
}

LL dfs(int l, int r)
{
//    printf("l = %d  r = %d\n", l, r);
    if(l >= r)
    {
        return 0LL;
    }
    LL mmin, mmax;
    int maxindex, minindex;
    get_Index(l, r, mmin, minindex, true, -1);
    get_Index(l, r, mmax, maxindex, false, minindex);
//    printf("min = %I64d  max = %I64d\n", mmin, mmax);
//    printf("min index = %d\nmax index = %d\n", minindex, maxindex);
    if(minindex > maxindex)
    {
        swap(minindex, maxindex);
    }
//    printf("ans = %I64d\n\n", ans);
    LL ans1 = dfs(l, maxindex - 1);
    LL ans2 = dfs(minindex + 1, r);
    LL ans4 = dfs(minindex + 1, maxindex - 1);
    LL ans3 = (mmax - mmin) * (minindex - l + 1) * (r - maxindex + 1);
    return ans1 + ans2 + ans3 - ans4;
}

int main()
{
    #ifdef LOCAL
    freopen("test.txt", "r", stdin);
    #endif // LOCAL

    scanf("%d", &n);
    for(int i = 1; i <= n; ++i)
    {
        scanf("%lld", &num[i]);
        Index[num[i]].push_back(i);
    }
    for(int i = 1; i <= n; ++i)
    {
        sort(Index[i].begin(), Index[i].end());
    }
    Init();
    printf("%lld\n", dfs(1, n));

    return 0;
}

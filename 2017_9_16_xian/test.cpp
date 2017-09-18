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

const LL MOD = 19260817;
const int Log = 20;
const int maxn = 3000 + 100;
unsigned long long seed;
int n, q, u, v, cnt;
vector<int> G[maxn];
int fa[Log][maxn];
bool UpM[Log][maxn][65][65], DownM[Log][maxn][65][65];
bool M[maxn][65][65];
int id[maxn];
LL nine[66], six[66];
bool ans1[65][65], ans2[65][65];
bool tmp[65][65];

void Memcpy(bool m1[65][65], const bool m2[65][65])
{
    for(int i = 1; i < 65; ++i)
    {
        for(int j = 1; j < 65; ++j)
        {
            m1[i][j] = m2[i][j];
        }
    }
}

LL Cal(bool m[65][65])
{
    LL ret = 0;
    for(int i = 1; i < 65; ++i)
    {
        for(int j = 1; j < 65; ++j)
        {
            ret += ((m[i][j] * nine[i] % MOD) * six[j]) % MOD;
            ret %= MOD;
        }
    }
    return ret;
}

void mult(bool m1[65][65], bool m2[65][65], bool m3[65][65])
{
    for(int i = 1; i < 65; ++i)
    {
        for(int j = 1; j < 65; ++j)
        {
            tmp[i][j] = 0;
            for(int k = 1; k < 65; ++k)
            {
                tmp[i][j] = (tmp[i][j] + m1[i][k] * m2[k][j]) % 2;
            }
        }
    }
    Memcpy(m3, tmp);
}

void SetOne(bool m[65][65])
{
    for(int i = 1; i < 65; ++i)
    {
        for(int j = 1; j < 65; ++j)
        {
            if(i == j)
            {
                m[i][j] = 1;
            }
            else
            {
                m[i][j] = 0;
            }
        }
    }
}

void Init()
{
    nine[0] = six[0] = 1;
    for(int i = 1; i < 66; ++i)
    {
        nine[i] = nine[i - 1] * 19 % MOD;
        six[i] = six[i - 1] * 26 % MOD;
    }
}

void dfs(int f, int x)
{
    id[x] = ++cnt;
    Memcpy(DownM[0][x], M[x]);
    int len = G[x].size();
    for(int i = 0; i < len; ++i)
    {
        int pos = G[x][i];
        if(pos != f)
        {
            Memcpy(UpM[0][pos], M[x]);
            fa[0][pos] = x;
            dfs(x, pos);
        }
    }
}

void prepare_skip_table()
{
    cnt = 0;
    fa[0][1] = 1;
    SetOne(UpM[0][1]);
    dfs(1, 1);
    for(int j = 1; j < Log; ++j)
    {
        for(int i = 1; i <= n; ++i)
        {
            fa[j][i] = fa[j - 1][fa[j - 1][i]];
            mult(UpM[j - 1][i], UpM[j - 1][fa[j - 1][i]], UpM[j][i]);
            mult(DownM[j - 1][fa[j - 1][i]], DownM[j - 1][i], DownM[j][i]);
        }
    }
}

int Find(int x, int y)
{
    if(x == y)
    {
        return x;
    }
    if(id[x] > id[y])
    {
        swap(x, y);
    }
    for(int i = Log - 1; i >= 0; --i)
    {
        if(id[fa[i][y]] > id[x])
        {
            y = fa[i][y];
        }
    }
    return fa[0][y];
}

void Rand()
{
    for(int i = 1; i <= n; ++i)
    {
        for(int p = 1; p <= 64; ++p)
        {
            seed ^= seed * seed + 15;
            for(int q = 1; q <= 64; ++q)
            {
                M[i][p][q] = (seed >> (q - 1)) & 1;
            }
        }
    }
}

void solve(int x, int y)
{
    int f = Find(x, y);
    int xx = x;
    int yy = y;
    Memcpy(ans1, M[x]);
    for(int i = Log - 1; i >= 0; --i)
    {
        if(id[fa[i][xx]] >= id[f])
        {
            mult(ans1, UpM[i][xx], ans1);
            xx = fa[i][xx];
        }
    }
    SetOne(ans2);
    for(int i = Log - 1; i >= 0; --i)
    {
        if(id[fa[i][yy]] >= id[f])
        {
            mult(DownM[i][yy], ans2, ans2);
            yy = fa[i][yy];
        }
    }
    mult(ans1, ans2, ans1);
    cout << Cal(ans1) << endl;
}

int main()
{
#ifdef LOCAL
    freopen("test.txt", "r", stdin);
#endif // LOCAL

    Init();
    cin >> n >> q;
    for(int i = 1; i < n; ++i)
    {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    cin >> seed;
    Rand();
    prepare_skip_table();
    /*
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j < 65; ++j) {
            for(int k = 1; k < 65; ++k) {
                cout << M[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }*/
    for(int i = 0; i < q; ++i)
    {
        cin >> u >> v;
        solve(u, v);
    }

    return 0;
}

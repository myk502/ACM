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

LL k, ans;

int main()
{
    #ifdef LOCAL
    freopen("test.txt", "r", stdin);
//	freopen("test.out", "w", stdout);
    #endif // LOCAL
    ios::sync_with_stdio(false);

    cin >> k;
    LL sq = sqrt((double)k);
	ans=INT_MAX;
    for(LL i = 1; i <= sq + 1; ++i)
    {
        if(k % i == 0 )
        {
			if(i-1>=2)
			{
				ans=min(ans,i-1);
			}
			if(k/i-1>=2)
				ans=min(ans,k/i-1);
        }
    }
    cout << ans << endl;

    return 0;
}

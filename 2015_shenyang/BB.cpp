#include<cstdio>
#include<iostream>
#include<cmath>
#include<set>
#include<algorithm>
#include<vector>
#include <cstring>
using namespace std;
char a[510][2050];
int n, len[510];
set<int> s;
int Next[2050];

void get_next(char *s) {
    Next[0] = -1;
    int j = -1;
    for(int i = 1; s[i]; ++i) {
        while(j != -1 && s[i] != s[j + 1]) {
            j = Next[j];
        }
        if(s[i] == s[j + 1]) {
            ++j;
        }
        Next[i] = j;
    }
}

bool issubstring(int j, int i)//j is substring of i
{
    get_next(a[j]);
    int jj = -1;
    for(int ii = 0; a[i][ii]; ++ii) {
        while(jj != -1 && a[i][ii] != a[j][jj + 1]) {
            jj = Next[jj];
        }
        if(a[i][ii] == a[j][jj + 1]) {
            ++jj;
        }
        if(a[j][jj + 1] == '\0') {
            return true;
        }
    }
    return false;
}
vector<int> deleted;
int main(void)
{
	int T, ans;
	scanf("%d", &T);
	for(int ii = 1; ii <= T; ii++)
	{
		s.clear();
		scanf("%d", &n);
		ans = -1;
		for(int i = 1; i <= n; i++)
		{
			scanf("%s",a[i]);
			len[i] = strlen(a[i]);
		}
		for(int i = 1; i <= n; i++)
		{
			deleted.clear();
			for(auto j:s)
			{
				if(issubstring(j , i))//j is substring of i
					deleted.push_back(j);
				else
				{
					ans = max(ans, i);
					break;
				}
			}
			s.insert(i);
			for(auto it:deleted)
				s.erase(it);
		}
		printf("Case #%d: %d\n", ii,ans);
	}
	return 0;
}

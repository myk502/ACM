#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
int n, m;
const int maxn = 1000000 * 2;
long long dis_1[maxn], dis_n[maxn];
bool visit[maxn];
typedef pair<long long, int> pii;
vector<pii> G[maxn];
priority_queue<pii, vector<pii>, greater<pii> > que;

void dijkstra(int s, long long *dis) {
    memset(dis, 0x3f, sizeof(long long) * maxn);
    dis[s] = 0;
    que.push(make_pair(0LL, s));
    while(!que.empty()) {
        pii tmp = que.top();
        que.pop();
        int len = G[tmp.second].size();
        for(int i = 0; i < len; ++i) {
            int pos = G[tmp.second][i].second;
            long long d = G[tmp.second][i].first;
            if(dis[pos] > tmp.first + d) {
                dis[pos] = tmp.first + d;
                que.push(make_pair(dis[pos], pos));
            }
        }
    }
}
long long ans;
vector<int> ANS;
int main(void)
{
	int T, t, s, id;
	scanf("%d",&T);
	for(int ii = 1; ii <= T; ii++)
	{
		for(int i = 0; i < maxn; i++)
			G[i].clear();
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= m; i++)
		{
			scanf("%d%d", &t, &s);
			for(int j = 0; j < s; j++)
			{
				scanf("%d", &id);
				G[id].push_back(make_pair(t, n + i));
				G[n + i].push_back(make_pair(t, id));
			}
		}
		dijkstra(1, dis_1);
		dijkstra(n, dis_n);
		ans = -1;
		ANS.clear();
		for(int i = 1; i <= n; i++)
		{
			long long temp = max(dis_1[i], dis_n[i]);
			long long INF;
			memset(&INF, 0x3f, sizeof(long long));
			if(dis_1[i] == INF || dis_n[i] == INF)
				continue;
			if(ans == -1)
			{
				ans = temp;
				ANS.push_back(i);
				continue;
			}
			if(ans == temp)
			{
				ANS.push_back(i);
				continue;
			}
			if(temp < ans)
			{
				ANS.clear();
				ans = temp;
				ANS.push_back(i);
				continue;
			}
			
		}
		printf("Case #%d: ", ii);
		if(ans == -1)
			printf("Evil John\n");
		else
		{
			ans /= 2;
			sort(ANS.begin(), ANS.end());
			cout<<ans<<endl;
			bool firstflag = false;
			for(auto it:ANS)
			{
				if(!firstflag)
				{
					firstflag = true;
					printf("%d",it);
				}
				else
					printf(" %d", it);
			}
			cout<<endl;
		}
	}
	return 0;
}

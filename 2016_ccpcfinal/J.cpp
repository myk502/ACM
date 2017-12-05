#include<map>
#include<vector>
#include<set>
#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
int rnk[7], G;
set<string> s;
vector<string> a[7];
vector<string> ec;
string ss;
vector<string> ANS;
bool status[25];
int main(void)
{
	int cnt = 0;
	string temp;
	int T;
	scanf("%d", &T);
	for(int ii = 1; ii <= T; ii++)
	{
		memset(rnk, 0, sizeof(rnk));
		s.clear();
		ANS.clear();
		ec.clear();
		cnt = 0;
		for(int i = 1; i <= 5; i++)
			a[i].clear();
		scanf("%d", &G);
		cin>>ss;
		for(int i = 1; i <= 5; i++)
		{
			for(int j = 1; j <= 20; j++)
			{
				cin >> temp;
				a[i].push_back(temp);
			}
		}
		for(int j = 1; j <= 20; j++)
		{
			cin >> temp;
			ec.push_back(temp);
		}
		while(cnt <= 20)
		{
			for(int i = 1; i <= 5; i++)
			{
				int id = rnk[i];
				rnk[i]++;
				if(s.find(a[i][id]) != s.end())
					continue;
				ANS.push_back(a[i][id]);
				s.insert(a[i][id]);
				cnt++;
				if(cnt > 20)
					break;
			}
		}
		int idx = -1;
		for(int i = 0; i < 20; i++)
		{
			if(ANS[i] == ss)
				idx = i + 1;
		}
		memset(status, 0, sizeof(status));
		s.clear();
		for(int y = 0; y <= G; y++)
		{
			int x = G - y;
			if((idx != -1) && (idx <= x))
			{
				status[y] = true;
				continue;
			}
			for(int i = 0; i < x; i++)
				s.insert(ANS[i]);
			cnt = 0;
			for(int i = 0; (i < 20) && (cnt < y); i++)
			{
				if(s.find(ec[i]) != s.end())
					continue;
				cnt++;
				s.insert(ec[i]);
				if(ec[i] == ss)
					status[y] = true;
			}
		}
		bool flag = true;
		int ans = -1;
		for(int i = 0; i <= G; i++)
			if(!status[i])
			{
				flag = false;
				if(ans == -1)
					ans = i;
			}
		if(flag)
			printf("Case #%d: ADVANCED!\n", ii);
		else
			printf("Case #%d: %d\n", ii, ans);
	}
		
	return 0;
}

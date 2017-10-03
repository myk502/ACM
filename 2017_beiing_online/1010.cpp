#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
#include<functional>
#include<queue>
#include<climits>
#include<algorithm>
using namespace std;
string finish_status;
string change(int op,int &status,string input)
{
	int pos,len,cnt[10];
	char ANS[10];
	memset(cnt,0,sizeof(cnt));
	for(int i = 0;i < input.length();i++)
	{
		ANS[i] = input[i];
		if(input[i] == '*')
			pos = i;
		cnt[input[i] - 'a']++;
	}
	len = input.length();
	if(op == 1)
	{
		if(pos == 0)
			status = -1;
		else
			swap(ANS[pos],ANS[pos - 1]);
	}
	if(op == 2)
	{
		if(pos == len - 1)
			status = -1;
		else
			swap(ANS[pos],ANS[pos + 1]);
	}
	if(op == 3)
	{
		if(pos == len - 1)
			status = -1;
		else
		{
			cnt[ANS[pos + 1] - 'a']--;
			for(int i = pos + 1;i < len - 1;i++)
				ANS[i] = ANS[i + 1];
			len--;
		}
	}
	if(op == 4)
	{
		if(pos == 0)
			status = -1;
		else
		{
			cnt[ANS[pos - 1] - 'a']--;
			for(int i = pos - 1;i < len - 1;i++)
			{
				ANS[i] = ANS[i + 1];
			}
			len--;
		}
	}
	if(op > 4)
	{
		int val = op - 5;
		if(val >6)
		{
			status = -1;
			return input;
		}
		if(cnt[val] != 0)
			status = -1;
		else
		{
			if(len >= 8)
				status = -1;
			else
			{
				for(int i = len;i > pos;i--)
					ANS[i] = ANS[i - 1];
				ANS[pos] = 'a' + val;
				len++;
			}
		}
	}
	return string(ANS,ANS + len);
}

hash<string> myhash;
map<long long,string> mp;

int LCS(string A,string B)
{
	
	for(int i =  0; )
}

int cmp(int id1,int id2)
{
	string xx = mp[id1];
	string yy = mp[id2];
	return LCS(xx,finish_staus) > LCS(yy,finish_status);
}
int main(void)
{
	char start[10],stop[10],a[10];
	int k,len;
	string aa;
	while(scanf("%s%d%s",start,&k,stop)!=EOF)
	{
		mp.clear();
		len = strlen(start);
		finish_status = string(stop);
		for(int i = 0;i < k;i++)
			a[i] = start[i];
		a[k] = '*';
		for(int i = k + 1;i <= len; i++)
			a[i] = start[i-1];
		aa = string(a,a + len + 1);
		mp.insert(make_pair(myhash(aa),aa));
	}
	return 0;
}

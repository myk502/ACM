#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 200000 + 10;
char input[maxn];
int n,num[30],cnt_odd,cnt_even,ans;
vector<char> ANS;
int main(void)
{
	scanf("%s",input);
	n = strlen(input);
	memset(num,0,sizeof(num));
	cnt_odd = cnt_even = 0;
	for(int i = 0; i < n;i++)
	{
		num[input[i] - 'a']++;
	}
	for(int i = 0; i < 26;i++)
	{
		if(num[i] & 1)
			cnt_odd++;
		else
			cnt_even++;
	}
	ans = (cnt_odd - (n & 1) ) >> 1;
	int ll = 0 , rr = 25;
	while(ans--)
	{
		while(!(num[ll] & 1))
			ll++;
		while(!(num[rr] & 1))
			rr--;
		num[ll++]++;
		num[rr--]--;
	}
	char sp = ',';
	for(int i = 0; i < 26;i++)
	{
		if(num[i] & 1)
		{
			sp = 'a' + i;
			num[i]--;
		}
		{
			for(int j = 0; j < (num[i] >> 1);j++)
				ANS.push_back('a' + i);
		}
	}
	for(auto it:ANS)
		printf("%c",it);
	if(sp != ',')
		printf("%c",sp);
	for(int i = ANS.size() - 1;i >= 0;i--)
		printf("%c",ANS[i]);
	printf("\n");
	return 0;
}

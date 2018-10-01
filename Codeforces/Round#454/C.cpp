#include<bits/stdc++.h>
using namespace std;
bool flag[50];
int n;
bool check(void)//to check whether the answer is determined
{
	int cnt = 0;
	for(int i = 0; i < 26; i++)
		if(!flag[i])
		{
			cnt++;
			//printf("The possible character is %c\n", 'a' + i);
		}
	if(cnt == 1)
		return true;
	else
		return false;

}
char input[100000 + 100];
bool show[30];

int solve(int ii)
{
	int cnt = 0;
	for(int i = ii + 1; i <= n; i++)
	{
		//printf("i = %d\n", i);
		gets(input);
		if(input[0] == '!' || input[0] == '?')
			cnt++;
	}
	if(cnt == 0)
		return 0;
	return cnt - 1;
}

int main(void)
{
	int ans = 0;
	scanf("%d", &n);
	scanf("\n");
	memset(flag, 0, sizeof(flag));
	for(int ii = 1; ii <= n; ii++)
	{
		gets(input);
		int m = strlen(input);
		if(input[0] == '!')//guess a word and get shocked
		{
			memset(show, 0, sizeof(show));
			for(int i = 2; i < m; i++)
				show[input[i] - 'a'] = true;
			for(int i = 0; i < 26; i++)
				if(!show[i])
					flag[i] = 1;
			if(check())
			{
				printf("%d\n", solve(ii));
				return 0;
			}
		}
		if(input[0] == '.')//guess a word and not get shocked
		{
			memset(show, 0, sizeof(show));
			for(int i = 2; i < m; i++)
				show[input[i] - 'a'] = true;
			for(int i = 0; i < 26; i++)
				if(show[i])
					flag[i] = 1;
			if(check())
			{
				printf("%d\n", solve(ii));
				return 0;
			}
		}
		if(input[0] == '?')
		{
			char temp = input[2];
			flag[temp - 'a'] = 1;
			if(check())
			{
				printf("%d\n", solve(ii));
				return 0;
			}
		}
	}
	printf("0\n");
	return 0;
}


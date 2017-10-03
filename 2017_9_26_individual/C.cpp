#include<bits/stdc++.h>
using namespace std;
char s[1000000 + 10];
int a[1000000 + 10];
int n;
stack<int> S;
void init(void)
{
	int val;
	for(int i = 0; i < n;i++)
	{
		switch(s[i])
		{
			case '<':
				val = -1;
				break;
			case '>':
				val = 1;
				break;
			case '{':
				val = -2;
				break;
			case '}':
				val = 2;
				break;
			case '[':
				val = -3;
				break;
			case ']':
				val = 3;
				break;
			case '(':
				val = -4;
				break;
			case ')':
				val = 4;
				break;
		};
		a[i] = val;
	}
}
int main(void)
{
	int ans = 0;
	scanf("%s",s);
	n = strlen(s);
	init();
	for(int i = 0; i < n;i++)
	{
		if(a[i] < 0)
			S.push(a[i]);
		else
		{
			if(S.empty())
			{
				ans = -1;
				break;
			}
			int temp = S.top();
			S.pop();
			if(temp + a[i] != 0)
				ans++;
		}
	}
	if(!S.empty())
		ans = -1;
	if(ans == -1)
		printf("Impossible\n");
	else
		printf("%d\n",ans);
	return 0;
}

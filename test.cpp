#include<cstdio>
#include<stack>
#include<cstring>
#include<iostream>
#include<string>
#include<cmath>
#include<vector>
#include<cstdlib>
#include<algorithm>
using namespace std;
vector<char> output[6];
void printnumber(int x)//-1 for jiange
{
	if(x == -1)
	{
		for(int i = 0; i < 5; i++)
		{
			output[i].push_back('.');
			output[i].push_back('.');
		}
		return;
	}
	if(x == 0)
	{
		for(int i = 0; i < 5; i += 4)//2 rows
		{
			for(int j = 0; j < 5; j++)
				output[i].push_back('6');
		}
		for(int i = 1; i < 4; i++)
		{
			output[i].push_back('6');
			for(int j = 0; j < 3; j++)
				output[i].push_back('.');
			output[i].push_back('6');
		}
		return;
	}
	if(x == 1)
	{
		for(int i = 0; i < 5; i++)
		{
			for(int j = 0; j < 4; j++)
				output[i].push_back('.');
			output[i].push_back('6');
		}
		return;
	}
	if(x == 2)
	{
		for(int i = 0; i < 5; i += 2)
		{
			for(int j = 0; j < 5; j++)
				output[i].push_back('6');
		}
		int i = 1;
		for(int j = 0; j < 4; j++)
			output[i].push_back('.');
		output[i].push_back('6');
		i = 3;
		output[i].push_back('6');
		for(int j = 0; j < 4; j++)
			output[i].push_back('.');
		return;
	}
	if(x == 3)
	{
		for(int i = 0; i < 5; i += 2)
		{
			for(int j = 0; j < 5; j++)
				output[i].push_back('6');
		}
		int i = 1;
		for(int j = 0; j < 4; j++)
			output[i].push_back('.');
		output[i].push_back('6');
		i = 3;
		for(int j = 0; j < 4; j++)
			output[i].push_back('.');
		output[i].push_back('6');
		return;
	}
	if(x == 4)
	{
		for(int i = 0; i < 2; i++)
		{
			output[i].push_back('6');
			for(int j = 0; j < 3; j++)
				output[i].push_back('.');
			output[i].push_back('6');
		}
		int i = 2;
		for(int j = 0; j < 5; j++)
			output[i].push_back('6');
		for(int i = 3; i < 5; i++)
		{
			for(int j = 0; j < 4; j++)
				output[i].push_back('.');
			output[i].push_back('6');
		}
		return ;
	}
	if(x == 5)
	{
		
		for(int i = 0; i < 5; i += 2)
		{
			for(int j = 0; j < 5; j++)
				output[i].push_back('6');
		}
		int i = 3;
		for(int j = 0; j < 4; j++)
			output[i].push_back('.');
		output[i].push_back('6');
		i = 1;
		output[i].push_back('6');
		for(int j = 0; j < 4; j++)
			output[i].push_back('.');
		return;
	}
	if(x == 6)
	{
		for(int i = 0; i < 5; i += 2)
		{
			for(int j = 0; j < 5; j++)
				output[i].push_back('6');
		}
		int i = 1;
		output[i].push_back('6');
		for(int j = 0; j < 4; j++)
			output[i].push_back('.');
		i = 3;
		output[i].push_back('6');
		for(int j = 0; j < 3; j++)
			output[i].push_back('.');
		output[i].push_back('6');
		return;
	}
	if(x == 7)
	{
		int i = 0; 
		for(int j = 0; j < 5; j++)
			output[i].push_back('6');
		for(int i = 1; i < 5; i++)
		{
			for(int j = 0; j < 4; j++)
				output[i].push_back('.');
			output[i].push_back('6');
		}
		return;
	}
	if(x == 8)
	{
		for(int i = 0; i < 5; i += 2)
		{
			for(int j = 0; j < 5; j++)
				output[i].push_back('6');
		}
		for(int i = 1; i < 4; i += 2)
		{
			output[i].push_back('6');
			for(int j = 0; j < 3; j++)
				output[i].push_back('.');
			output[i].push_back('6');
		}
		return ;
	}
	if(x == 9)
	{
		for(int i = 0; i < 5; i += 2)
		{
			for(int j = 0; j < 5; j++)
				output[i].push_back('6');
		}
		for(int i = 1; i < 4; i += 2)
		{
			if(i == 1)
				output[i].push_back('6');
			else 
				output[i].push_back('.');
			for(int j = 0; j < 3; j++)
				output[i].push_back('.');
			output[i].push_back('6');
		}
		return ;
	}
}
void print(long long x)
{
	if(x == 0)
	{
		printnumber(0);
		return;
	}
	stack<int> s;
	while(x)
	{
		s.push((int) (x % 10LL));
		x /= 10LL;
	}
	int temp = s.top();
	s.pop();
	printnumber(temp);
	while(!s.empty())
	{
		int x = (int)s.top();
		s.pop();
		for(int i = 0; i < 5; i++)
		{
			output[i].push_back('.');
			output[i].push_back('.');
		}
		printnumber(x);
	}
}

long long eval(char* str)
{
	int len = strlen(str);
	stack<long long> num;
	stack<char> op;
	for(int i = 0; i < len; i++)
	{
		if(str[i] == '6')
			num.push(6);
		else
		{
			if(op.empty())
				op.push(str[i]);
			else 
			{
				if((str[i] == '*') && (op.top() != '*'))
					op.push(str[i]);
				else
				{
					int num1 = num.top();
					num.pop();
					int num2 = num.top();
					num.pop();
					char temp = op.top();
					op.pop();
					if(temp == '+')
						num.push(num1 + num2);
					if(temp == '-')
						num.push(num2 - num1);
					if(temp == '*')
						num.push(num1 * num2);
					op.push(str[i]);
				}
			}
		}
	}
	while(!op.empty())
	{
					int num1 = num.top();
					num.pop();
					int num2 = num.top();
					num.pop();
					char temp = op.top();
					op.pop();
					if(temp == '+')
						num.push(num1 + num2);
					if(temp == '-')
						num.push(num2 - num1);
					if(temp == '*')
						num.push(num1 * num2);
	}
	long long val = num.top();
	return val;
}
char input[10000];
int n;
int main(void)
{
	scanf("%d", &n);
	for(int ii = 0 ; ii < n; ii++)
	{
		for(int i = 0; i < 5; i++)
			output[i].clear();
		scanf("%s", input);
		long long ans = eval(input);
		print(ans);
		for(int i = 0; i < 5; i++)
		{
			for(auto it:output[i])
				cout  << it;
			cout << endl;
		}
	}
	return 0;
}


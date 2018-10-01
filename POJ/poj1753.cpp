#include <string>
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;
const size_t maxn = (1 << 16) + 10;
int a[maxn];
const unsigned int ans1 = 0;
const unsigned int ans2 = (1 << 16) - 1;
void set_zero(unsigned int& x, int k)
{
	if(k < 0 || k > 15)
		return;
	unsigned mask = ~(1 << k);
	x &= mask;
}

void set_one(unsigned int& x, int k)
{
	if(k < 0 || k > 15)
		return;
	unsigned mask = 1 << k;
	x |= mask;
}

void flip_kth_bit(unsigned int& x, int k)
{
	if(k < 0 || k > 15)
		return;
	unsigned mask = 1 << k;
	x ^= mask;
}
queue<unsigned int> q;
int main()
{
	memset(a, -1, sizeof(a));
	string input;
	int j = 0;
	unsigned int init_status = 0;
	for(int i = 0; i < 4; i++)
	{
		cin >> input;
		for(unsigned int id = 0; id < input.size(); ++id)
		{
			char it = input[id];
			if(it == 'b')
				set_one(init_status, j);
			else
				set_zero(init_status, j);
			++j;
		}
	}
	a[init_status] = 0;
	if(init_status == ans1 || init_status == ans2)
	{
		cout << 0 << endl;
		return 0;
	}
	q.push(init_status);
	while(!q.empty())
	{
		unsigned int status = q.front();
		q.pop();
		int new_step = a[status] + 1;
		for(int k = 0; k < 16; k++)
		{
			unsigned int new_status = status;
			flip_kth_bit(new_status, k);
			flip_kth_bit(new_status, k - 4);
			flip_kth_bit(new_status, k + 4);
			flip_kth_bit(new_status, k - 1);
			flip_kth_bit(new_status, k + 1);
			if(a[new_status] == -1)
			{
				if(new_status == ans1 || new_status == ans2)
				{
					cout << new_step << endl;
					return 0;
				}
				a[new_status] = new_step;
				q.push(new_status);
			}
		}
	}
	cout << "Impossible" << endl;
	return 0;
}

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>

using namespace std;

int main(void)
{
	int n, r, l;
	while (cin >> n && n >= 0)
	{
		while (n--)
		{
		cin >> l >> r;
		int k = 1;
		while (--l)
	    {
			if (r % 2)
				k = k << 1;
			else
				k = (k << 1) + 1;
			r = (r + 1) >> 1;
	    }
		cout << k << endl;
		}
    }
	return 0;
}

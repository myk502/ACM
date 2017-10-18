#include<bits/stdc++.h>
using namespace std;

int main(void)
{
	int x;
	while(cin >> x)
	{
		int ans = (5 ^ x) + (100 ^ x);
		cout<<ans<<endl;
	}
	return 0;
}

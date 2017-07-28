#include<bits/stdc++.h>
using namespace std;
int x;
int main(void)
{
	while(cin>>x)
	{
		int temp=32-__builtin_clz(x);
		cout<<(1<<(temp-1))<<endl;
	}

	return 0;
}

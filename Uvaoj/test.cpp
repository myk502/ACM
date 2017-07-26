#include<bits/stdc++.h>
using namespace std;

int main(void)
{
	list<int> a;
	auto it=a.end();
	a.insert(it,5);
	a.insert(it,3);
	for(auto i:a)
		cout<<i<<endl;
	return 0;
}

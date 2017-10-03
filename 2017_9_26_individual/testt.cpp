#include<bits/stdc++.h>
using namespace std;

set<int> s;
int main(void)
{
	set<int> s;
	for(int i = 1; i <= 5;i++)
		s.insert(i);
	auto it = s.find(5);
	it -= s.begin();
	return 0;
}

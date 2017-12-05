#include<bits/stdc++.h>
using namespace std;

int main(void)
{
	priority_queue<int, vector<int>, greater<int> > q;
	for(int i = 1; i <= 10; i++)
		q.push(i);
	while(!q.empty())
	{
		cout<<q.top();
		q.pop();
	}
	return 0;
}

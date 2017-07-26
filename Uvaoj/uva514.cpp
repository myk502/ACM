#include<cstdio>
#include<iostream>
#include<set>
#include<stack>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
int n;
const int maxn=1000+10;
int b[maxn];
stack<int> s;
int main(void)
{
	int i,j;
	ios::sync_with_stdio(false);
	while(cin>>n)
	{
		if(n==0)
			break;
		while(cin>>b[1])
		{
			
			if(b[1]==0)
			{
				cout<<endl;
				break;
			}
			for(int i=2;i<=n;i++)
				cin>>b[i];
			while(!s.empty())
				s.pop();
			i=j=1;
			while(1)
			{
				if(!s.empty() && j<=n && (s.top()==b[j]))
				{
					s.pop();
					j++;
				}
				else if(i<=n)
				{
					s.push(i);
					i++;
				}
				else
					break;
			}
			if(s.empty())
				cout<<"Yes"<<endl;
			else
				cout<<"No"<<endl;
			}
		
	}
	return 0;
}

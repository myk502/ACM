#include<list>
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

string input;
list<char> ANS;
int main(void)
{
	list<char>::iterator it;
	while(cin>>input)
	{
		ANS.clear();
		it=ANS.end();
		for(auto i:input)
		{
			if(i=='[')
				it=ANS.begin();
			else if(i==']')
				it=ANS.end();
			else
				ANS.insert(it,i);
		}
		for(auto i:ANS)
			cout<<i;
		cout<<endl;
	}
	return 0;
}

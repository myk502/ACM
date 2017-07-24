#include<cstdio>
#include<iostream>
#include<cstring>
#include<set>
#include<map>
#include<vector>
#include<climits>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
string s[5][6];
vector<int> ans;
void init(void)
{
	for(int i=0;i<5;i++)
		s[i][1]="***";
	s[0][2]=s[1][2]=s[3][2]="*.*";
	s[2][2]=s[4][2]="*..";
	s[0][3]=s[1][3]=s[4][3]="***";
	s[2][3]="*..";
	s[3][3]="*.*";
	s[0][4]=s[1][4]=s[3][4]="*.*";
	s[2][4]=s[4][4]="*..";
	s[0][5]="*.*";
	for(int i=1;i<5;i++)
		s[i][5]="***";
}
int main(void)
{
	int n;
	string input;
	init();
	cin>>n>>input;
	ans.clear();
	for(auto it:input)
	{
		ans.push_back(it-'A');
	}
	for(int j=1;j<=5;j++)
	{
		for(auto i:ans)
		{
			cout<<s[i][j];
		}
		cout<<endl;
	}
	return 0;
}

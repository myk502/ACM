#include<cstdio>
#include<stack>
#include<iostream>
#include<cmath>
#include<cmath>
#include<algorithm>
using namespace std;
int n;
struct Matrix
{
	int row,column;
	Matrix(int xx=0,int yy=0):row(xx),column(yy)
	{

	}
};
Matrix mat[30];
stack<Matrix> s;
int cal(void)
{
	Matrix B=s.top();
	s.pop();
	Matrix A=s.top();
	s.pop();
	if(A.column!=B.row)
		return -1;
	else
	{
		Matrix C(A.row,B.column);
		s.push(C);
		return A.row*A.column*B.column;
	}
}
int main(void)
{
	long long ans;
	bool flag;
	string input;
	int xx,yy;
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>input>>xx>>yy;
		int id=input[0]-'A';
		mat[id].row=xx;
		mat[id].column=yy;
	}
	while(cin>>input)
	{
		ans=0;
		while(!s.empty())
			s.pop();
		flag=true;
		for(auto it:input)
		{
			if(it=='(')
				continue;
			else if(it==')')
			{
				if(s.size()<2)
					continue;
				int temp=cal();
				if(temp!=-1)
					ans+=temp;
				else
					flag=false;
			}
			else
			{
				int id=it-'A';
				s.push(Matrix(mat[id].row,mat[id].column));
			}

		}
		while(s.size()>1)
		{
			int temp=cal();
			if(temp==-1)
				flag=false;
			else
				ans+=temp;
		}
		if(!flag)
			cout<<"error"<<endl;
		else
			cout<<ans<<endl;
	}
	
	return 0;
}

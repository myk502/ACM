#include<bits/stdc++.h>
using namespace std;
int c=5,n=5;
vector<string> money;
string rand_string(void)
{
	int x;
	int len=rand()%10+1;
	char temp[15];
	for(int i=0;i<len;i++)
	{
		int character=rand()%26;
		int is_upper=rand()%2;
		if(is_upper)
			x=character+65;
		else
			x=character+97;
		temp[i]=(char)x;
			
	}
	temp[len]='\0';
	string ANS(temp);
	return ANS;
}
double rand_double(void)
{
	int temp=rand()%100000+1;
	return (double)temp/100.0;
}
string rand_money(void)
{
	int _size=money.size();
	int id=rand()%_size;
	return money[id];
}
int main(void)
{
	string temp;
	freopen("in","w",stdout);
	cout<<2<<endl;
	srand((unsigned)time(NULL));
	for(int t=0;t<2;t++)
	{
		printf("3 5\n");
		money.push_back("JD");
		for(int i=0;i<3;i++)
		{
			temp=rand_string();
			while(find(money.begin(),money.end(),temp)!=money.end())
				temp=rand_string();
			double price=rand_double();
			cout<<temp<<" "<<price<<endl;
			money.push_back(temp);
		}
		for(int i=0;i<n;i++)
		{
			double temp=rand_double();
			cout<<temp<<" "<<rand_money()<<endl;
		}
	}

	return 0;
}

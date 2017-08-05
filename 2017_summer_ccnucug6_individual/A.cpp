#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n,a,b;
int num_single,num_double,num_x;
int main(void)
{
	int input,ans=0;
	cin>>n>>a>>b;
	num_single=a;
	num_double=b;
	num_x=0;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&input);
		if(input==1)
		{
			if(num_single>0)
				num_single--;
			else if(num_double>0)
			{
				num_double--;
				num_x++;
			}
			else if(num_x>0)
				num_x--;
			else
				ans++;
			
		}
		else
		{
			if(num_double>0)
				num_double--;
			else
				ans+=2;
		}
	}
	cout<<ans<<endl;
	return 0;
}

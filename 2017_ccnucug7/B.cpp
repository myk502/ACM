#include<cstdio>
#include<iostream>
#include<cstring>
#include<cctype>
#include<string>
using namespace std;
string input;
int main(void)
{
	int	n,ans=-1,cnt;
	scanf("%d",&n);
	while(cin>>input)
	{
		cnt=0;
		for(auto it:input)
		{
			if(isupper(it))
				cnt++;
		}
		ans=max(ans,cnt);
	}
	cout<<ans<<endl;
	return 0;
}

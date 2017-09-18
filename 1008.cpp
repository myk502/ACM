#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<map>
#include<algorithm>
using namespace std;
map<string,int> a;
int main(void)
{
	string input1,input2;
	int id1,id2,ans;
	int T;
	cin>>T;
	int id = 0;
	a["rat"] = id++;
	a["ox"] = id++;
	a["tiger"] = id++;
	a["rabbit"] = id++;
	a["dragon"] = id++;
	a["snake"] = id++;
	a["horse"] = id++;
	a["sheep"] = id++;
	a["monkey"] = id++;
	a["rooster"] = id++;
	a["dog"] = id++;
	a["pig"] = id++;
	while(T--)
	{
		cin>>input1>>input2;
		id1 = a[input1];
		id2 = a[input2];
		ans = id2 -id1;
		if(ans<=0)
			ans += 12;
		if(ans>12)
			ans -= 12;
		cout<<ans<<endl;
	}
	return 0;
}

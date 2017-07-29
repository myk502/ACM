#include<bits/stdc++.h>
using namespace std;
bool cnt[1000];
int main(void)
{
	int a[100];
	for(int i=0;i<100;i++)
		a[i]=i;
	auto it=lower_bound(a,a+100,5.7);
	cout<<it-a<<endl;
	return 0;
}

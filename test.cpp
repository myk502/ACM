#include<bits/stdc++.h>
using namespace std;

int main(void)
{
	int a[]={2,3,4,5,1,2,3,8,10};
	nth_element(a,a,a+8);
	for(int i=0;i<8;i++)
		cout<<a[i]<<endl;
}

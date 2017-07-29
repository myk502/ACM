#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
long long n;
long long pow2[64];
long long k;
int main(void)
{
	long long ans=0;
	cin>>n;
	/*
	if(n==0)
	{
		cout<<0<<endl;
		return 0;
	}
	*/
	long long ll,rr;
	ll=0;
	rr=100000000;
	while(rr-ll>1LL)
	{
		long long mid=(ll+rr)/2;
		//printf("ll=%lld,rr=%lld\n",ll,rr);
		long long temp1=mid*mid+2*mid;
		long long temp2=mid*mid+4*mid+3;
		if(n<temp1)
			rr=mid;
		if(n>=temp2)
			ll=mid;
		
		if((n>=temp1)&&(n<temp2))
			ll=mid;
		
	}	
	k=ll;
	if(n-(k*k+2*k)>0)
	{
		ans+=n-(k*k+2*k)-1;
	}
	ans+=k*k+k;
	cout<<ans<<endl;
	return 0;
}

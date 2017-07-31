#include<cstdio>
#include<iostream>
#include<cmath>
#include<map>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int c,n;
char input[15];
double price;
double ans;
typedef pair<long long,long long> pii;
map<pii,double> a;
long long myhash(int id,char* str)
{
	long long mod,pow=1,ans=0;
	if(id==1)
		mod=1000000000+7;
	else
		mod=1000000000+9;
	int n=strlen(str);
	for(int i=n-1;i>=0;i--)
	{
		long long character=str[i]-'A';
		ans+=(character*pow)%mod;
		pow=(pow*58)%mod;
	}
	return ans%mod;
}

int main(void)
{
	char origin[]="JD";
	long long hash1,hash2;
	double xx;
	int T;
	cin>>T;
	while(T--)
	{
		a.clear();
		hash1=myhash(1,origin);
		hash2=myhash(2,origin);
		a[make_pair(hash1,hash2)]=1;
		ans=0;
		cin>>c>>n;
		for(int i=0;i<c;i++)
		{
			scanf("%s%lf",input,&price);
			hash1=myhash(1,input);
			hash2=myhash(2,input);
			if(a.find(make_pair(hash1,hash2))!=a.end())
			{
				while(1)
				{

				}
			}
			a[make_pair(hash1,hash2)]=price;
			//printf("The string is %s and hash=(%lld,%lld)\n",input,hash1,hash2);
		}
		/*
		for(auto it:a)
		{
			cout<<it.first<<" "<<it.second<<endl;
		}
		*/
		for(int i=0;i<n;i++)
		{
			scanf("%lf%s",&xx,input);
			hash1=myhash(1,input);
			hash2=myhash(2,input);

			//printf("The string is %s and hash=(%lld,%lld)\n",input,hash1,hash2);
			ans+=xx*a[make_pair(hash1,hash2)];
		}
		printf("%.6lf\n",ans);
	}
	return 0;
}

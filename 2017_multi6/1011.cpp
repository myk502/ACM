#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
int x1,x2,x3,x4,x5,x6,x7,a,b,c,d,e,f,g;
int max(int a,int b)
{
	if(a<b)
		return b;
	else
		return a;
}
int main(void)
{
	int ans,T,n;
	bool flag;
	scanf("%d",&T);
	while(T--)
	{
		ans=-1;
		scanf("%d",&n);
		for(int ii=1;ii<=n;ii++)
		{
			flag=true;
			scanf("%d%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f,&g);
			x1=a-d-f+g;
			x2=b-d-e+g;
			x3=c-e-f+g;
			x4=d-g;
			x5=e-g;
			x6=f-g;
			x7=g;
			if(x1<0)
				flag=false;
			if(x2<0)
				flag=false;
			if(x3<0)
				flag=false;
			if(x4<0)
				flag=false;
			if(x5<0)
				flag=false;
			if(x6<0)
				flag=false;
			if(x7<0)
				flag=false;
			if(flag)
				ans=max(ans,x1+x2+x3+x4+x5+x6+x7);
		}
		printf("%d\n",ans);

	}
	return 0;
}

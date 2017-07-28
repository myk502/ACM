#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
bool rreverse;
const int maxn=100000+10;
int left[maxn],right[maxn],n,m;
void link(int x,int y)//y is to the right of x
{
	right[x]=y;
	left[y]=x;
}
void operation(int op,int x,int y)
{
	if((op!=3) && rreverse)
		op=3-op;
	if((op==3) && (left[x]==y))
		std::swap(x,y);//suggested by lrj's code
	int x_left,x_right,y_left,y_right;
	x_left=left[x];
	x_right=right[x];
	y_left=left[y];
	y_right=right[y];
	if(op==1)
	{
		if(right[x]==y)
			return ;
		link(x_left,x_right);
		link(y_left,x);
		link(x,y);
	}
	if(op==2)
	{
		if(right[y]==x)
			return ;
		link(x_left,x_right);
		link(y,x);
		link(x,y_right);
	}
	if(op==3)
	{
		if(x_right==y)
		{
			link(x_left,y);
			link(y,x);
			link(x,y_right);
			return ;
		}
		link(x_left,y);
		link(y,x_right);
		link(y_left,x);
		link(x,y_right);
		//std::swap(left[x],left[y]);
		//std::swap(right[x],right[y]);
	}
	/*
	for(int i=0;i<=n+1;i++)
	{
		std::cout<<"left["<<i<<"]= "<<left[i]<<"  right= "<<right[i]<<std::endl;
	}
	*/
}
int main(void)
{
	long long ans;
	std::ios::sync_with_stdio(false);
	int opt,xx,yy;
	int cas=0;
	while(std::cin>>n>>m)
	{
		ans=0;
		rreverse=false;
		right[n+1]=left[0]=-1;
		for(int i=0;i<=n;i++)
			right[i]=i+1;
		for(int i=1;i<=n+1;i++)
			left[i]=i-1;
		while(m--)
		{
			//std::cout<<"Now m equals to "<<m<<std::endl;
			std::cin>>opt;
			if(opt==4)
				rreverse=!rreverse;
			else
			{
				std::cin>>xx>>yy;
				operation(opt,xx,yy);
			}
		}
		std::cout<<"Case "<<++cas<<": ";
		int cnt=0,id;
		/*
		for(int i=0;i<=n+1;i++)
			std::cout<<"right["<<i<<"]= "<<right[i]<<std::endl;
		*/
		if(!rreverse)
		{
			id=0;
			for(int ii=0;ii<n;ii++)
			{
				//std::cout<<id<<" ";
				id=right[id];
				cnt++;
				if(cnt%2==1)
					ans+=id;
			}
		}
		else
		{
			id=n+1;
			for(int ii=0;ii<n;ii++)
			{
				//std::cout<<id<<" ";
				id=left[id];
				cnt++;
				if(cnt%2==1)
					ans+=id;
			}
			//std::cout<<std::endl;
		}
		std::cout<<ans<<std::endl;


	}
	return 0;
}

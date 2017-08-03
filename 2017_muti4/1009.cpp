#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int main(void)
{
	int n,T,cnt_odd,cnt_even,temp;
	cin>>T;
	while(T--)
	{
		cin>>n;
		cnt_odd=cnt_even=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&temp);
			if(temp%2)
				cnt_odd++;
			else
				cnt_even++;
		}
		if(cnt_odd>=cnt_even)
			printf("%d %d\n",2,1);
		else
			printf("%d %d\n",2,0);

	}
	return 0;
}

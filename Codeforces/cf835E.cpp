#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
using namespace std;
int n,x,y,bits[20];
bool isequal[20];
int ans[20],bit_notequal;
vector<int> TEMP;
bool output_zero_on_kth_bit(int k)
{
	vector<int> OUTPUT;
	for(int i = 1 ; i <= n;i++)
		if(i & bits[k]) 
			OUTPUT.push_back(i);
	if(OUTPUT.size() == 0U)
		return false;
	printf("? ");
	printf("%d ",(int)OUTPUT.size());
	for(auto it:OUTPUT)
		printf("%d ",it);
	printf("\n");
	fflush(stdout);
	return true;
}
int main(void)
{
	int input;
	scanf("%d%d%d",&n,&x,&y);
	bits[0] = 1;
	for(int i = 1; i < 20; i ++)
		bits[i] = bits[i - 1] << 1;
	for(int i = 0 ; i < 10; i++)
	{
		bool tempflag;
		tempflag = output_zero_on_kth_bit(i);
		if(!tempflag)
		{
			isequal[i] = true;
			continue;
		}
		scanf("%d",&input);
		if(input == y || input == (x^y))
		{
			bit_notequal = i;
			isequal[i] = false;
		}
		else
			isequal[i] = true;
	}
	/*
	for(int i = 0 ; i < 10; i++)
		printf("isequal[%d] = %d\n",i,isequal[i]);
	printf("bit_notequal = %d\n",bit_notequal);
	*/
	for(int i = 1; i <= n; i++)
	{
		if(i & bits[bit_notequal])
		{
			TEMP.push_back(i);
			//printf("Now we are adding %d to TEMP.\n",i);
		}
	}//Now in vector TEMP, there must exist a special y
	ans[bit_notequal] = 1;
	for(int i = 0 ; i < 10;i++)
	{
		vector<int> OUTPUT;
		if(i == bit_notequal)
			continue;
		for(auto it:TEMP)
			if(it & bits[i])// it has 1 on i-th bit
				OUTPUT.push_back(it);
		if(OUTPUT.size() == 0U)
		{
			ans[i] = 0;
			continue;
		}
		printf("? ");
		printf("%d ",(int)OUTPUT.size());
		for(auto it:OUTPUT)
			printf("%d ",it);
		printf("\n");
		fflush(stdout);
		scanf("%d",&input);
		if(input == y || input == (x ^ y))
			ans[i] = 1;
		else
			ans[i] = 0;
		//printf("ans[%d] = %d\n",i,ans[i]);
	}
	int ans1,ans2;
	ans1 = ans2 = 0;
	for(int i = 0; i < 10;i++)
		ans1 += ans[i] << i;
	for(int i = 0 ; i < 10;i++)
		if(!isequal[i])
			ans[i] = !ans[i];
	for(int i = 0 ; i < 10;i++)
		ans2 += ans[i] << i;
	if(ans1 > ans2)
		swap(ans1,ans2);
	printf("! %d %d\n",ans1,ans2);
	fflush(stdout);
	return 0;
}

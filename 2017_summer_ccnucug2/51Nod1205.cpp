#include<cstdio>
#include<vector>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
struct Task
{
	int atime,btime;
	Task(int x,int y):atime(x),btime(y)
	{
	}
};
int n;
vector<Task> t1,t2;
bool cmp1(Task X,Task Y)
{
	return X.atime<=Y.atime;
}
bool cmp2(Task X,Task Y)
{
	return X.btime>=Y.btime;
}
int main(void)
{
	int aa,bb;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&aa,&bb);
		if(aa<bb)
			t1.push_back(Task(aa,bb));
		else
			t2.push_back(Task(aa,bb));
	}
	sort(t1.begin(),t1.end(),cmp1);
	sort(t2.begin(),t2.end(),cmp2);
	for(auto it:t2)
		t1.push_back(it);
	//Now t1 is the answer task list
	int ans=t1[0].atime+t1[0].btime;
	int sum=t1[0].atime;

	for(int i=1;i<n;i++)
	{
		sum+=t1[i].atime;
		int temp=max(ans,sum);
		ans=temp+t1[i].btime;
	}
	cout<<ans<<endl;

	return 0;
}

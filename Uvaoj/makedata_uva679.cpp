#include<bits/stdc++.h>
using namespace std;
int T,n,depth;
int main(void)
{
	freopen("in","w",stdout);
	T=50;
	srand((unsigned)time(NULL));
	cout<<T<<endl;
	for(int ii=0;ii<T;ii++)
	{
		depth=rand()%19+2;
		n=rand()%524289+1;
		printf("%d %d\n",depth,n);
	}
	cout<<-1<<endl;
	return 0;
}

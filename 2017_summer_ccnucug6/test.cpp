#include<bits/stdc++.h>
using namespace std;
int run(string s)
{
	return system(s.c_str());
}
int main(void)
{
	for(int i=0;i<100000;i++)
	{
		printf("Test %d:\n",i);
		run("./make_data.out");
		run("./correct.out <in >out_correct");
		run("./wrong.out <in >out_wrong");
		if(run("diff out_wrong out_correct"))
		{
			printf("Wrong Answer!\n");
			break;
		}
		else
			printf("Accepted!\n");
	}
	return 0;
}

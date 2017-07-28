#include<bits/stdc++.h>
using namespace std;

int run(string s)
{
	return system(s.c_str());
}

int main(void)
{
	for(int i=1;i<=100;i++)
	{
		printf("Test %d:\n",i);
		run("./makedata");
		run("./correct.out <in >out_correct");
		run("./wrong.out <in >out_wrong");
		if(run("diff out_correct out_wrong"))
		{
			printf("Error!\n");
			break;
		}
		else
			printf("Accepted!\n");
	}
	return 0;
}

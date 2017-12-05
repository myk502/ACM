#include<cstdio>
using namespace std;
char input;
int num;
int cas = 0;
int main(void)
{
	while(scanf("%c", &input) != EOF)//keep reading character 
	{
		if(input == ' ' || input == '\n')//if we have read a blank character, continue
			continue;
		if(input == '@')//@ means the end of input
			break;
		if(cas == 0)//This statement is for the separation lines between cases(because if we just print an empty line after each case
		//we will get a Presentation Error
			cas++;
		else
			printf("\n");
		scanf("%d", &num);
		for(int i = 1; i < num; i++)
			printf(" ");
		printf("%c\n", input);//The first row
		int num_space = 1;
		for(int i = num - 2; i > 0; i--)//The second till the last but one row
		{
			for(int j = 0; j < i; j++)
				printf(" ");
			printf("%c", input);
			for(int j = 0; j < num_space; j++)
				printf(" ");
			printf("%c\n", input);
			num_space += 2;
		}
		if(num > 1)//The last row
		{
			for(int i = 0; i < 2 * num - 1; i++)
				printf("%c",input);
			printf("\n");
		}
	}
	return 0;
}

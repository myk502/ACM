#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<string>
#include<sstream>
#include<set>
#include<queue>
#include<algorithm>
using namespace std;

char s[100][100];
int main(void)
{
    for(int i=0;i<2;i++)
        scanf("%s",s[i]);
    printf("%s\n%s\n",s[0],s[1]);
    return 0;
}

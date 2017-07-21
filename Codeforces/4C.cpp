#include<stdio.h>
#include<map>
#include<string>
#include<string.h>
#include<algorithm>
using namespace std;
char temp[33];
map <string,int> myk;
int main(void)
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%s",temp);
        if(myk.count(temp)==0)//这个注册名没有出现过
            myk[temp]=0;
        else
            myk[temp]+=1;
        if(myk[temp]==0)
            printf("OK\n");
        else
            printf("%s%d\n",temp,myk[temp]);
    }
    return 0;
}

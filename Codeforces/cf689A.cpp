#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<queue>
#include<cmath>
#include<climits>
#include<sstream>
#include<algorithm>
using namespace std;
int n,status[10];
char input[15];
int main(void)
{
    int x,temp;
    cin>>n;
    memset(status,0,sizeof(status));
    scanf("%s",input);
    for(int i=0;i<n;i++)
    {
        x=input[i]-'0';
        status[x]++;
    }
    int flag=0;
    if((status[1]+status[2]+status[3]==0)||(status[1]+status[4]+status[7]+status[0]==0)||(status[6]+status[9]+status[3]+status[0]==0)||(status[7]+status[9]+status[0]==0))
        flag=1;
    if(flag==1)
        printf("NO");
    else
        printf("YES");
    return 0;
}

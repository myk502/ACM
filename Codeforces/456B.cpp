#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
#define zuida 100000
using namespace std;
char a[zuida+10];
int main(void)
{
    int ans,length,temp;
    scanf("%s",a);
    length=strlen(a);
    if(length<5)
    {
        temp=atoi(a);
        if(temp%4==0)
            ans=4;
        else
            ans=0;
    }
    else
    {
        temp=10*(a[length-2]-'0')+(a[length-1]-'0');
        if(temp%4==0)
            ans=4;
        else
            ans=0;
    }
    printf("%d",ans);
    return 0;

}

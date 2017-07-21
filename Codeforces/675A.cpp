#include<stdio.h>
#include<string.h>
#include<math.h>
#include<limits.h>
#include<vector>
#include<set>
#include<ctype.h>
#include<algorithm>
using namespace std;

int main(void)
{
    int a,b,c;
    int ans=1,temp;
    scanf("%d%d%d",&a,&b,&c);
    if(c==0)
    {
        if(a!=b)
            ans=0;
    }
    else
    {
        temp=b-a;
        if(temp%c!=0)
            ans=0;
        else
        {
            if(temp/c<0)
                ans=0;
        }
    }
    if(ans==1)
        printf("YES");
    else
        printf("NO");
    return 0;
}

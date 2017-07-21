#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>
using namespace std;
int status[100];
int main(void)
{
    int cnt,n,temp,num;
    memset(status,0,sizeof(status));
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&temp);
        status[temp]=1;
    }
    cnt=0;
    for(num=1;num<=90;num++)
    {
        if(status[num]==1)
            cnt=0;
        else
        {
            cnt++;
            if(cnt>=15)
                break;
        }
    }
    if(num==91)
        num=90;
    printf("%d",num);
    return 0;
}

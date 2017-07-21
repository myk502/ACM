#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int aa[100000+10],num[10];
char temp[10];
int main(void)
{
    int length,status,t,a,b,ans;
    memset(aa,0,sizeof(aa));
    for(int i=1;i<=100000;i++)
    {
        sprintf(temp,"%d",i);
        memset(num,0,sizeof(num));
        status=1;
        length=strlen(temp);
        for(int i=0;i<length;i++)
        {
            num[temp[i]-'0']++;
        }
        for(int i=0;i<10;i++)
        {
            if(num[i]>1)
                status=0;
        }
        aa[i]=status;
    }
    scanf("%d",&t);
    while(t--)
    {
        ans=0;
        scanf("%d%d",&a,&b);
        for(int i=a;i<=b;i++)
            if(aa[i]==1)
                ans++;
        printf("%d\n",ans);
    }
    return 0;
}

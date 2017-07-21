#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
int status[6010];
int main(void)
{
    int n,temp,num=0;
    memset(status,0,sizeof(status));
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&temp);
        status[temp]++;
    }
    for(int i=1;i<=6000;i++)
    {
        while(status[i]>1)
        {

            status[i]--;
            for(int j=i+1;j<=6005;j++)
                if(status[j]==0)
                {
                    num+=j-i;
                    status[j]++;
                    break;
                }
        }
    }
    printf("%d",num);
    return 0;
}

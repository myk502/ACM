#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;

int x,y;
int status[1010];

int main(void)
{
    cin>>x>>y;
    memset(status,0,sizeof(status));
    int temp=min(x,y);
    while(x>=1)
    {
        status[x]++;
        x/=2;
    }
    //printf("status[2]=%d\n",status[2]);
     while(y>=1)
    {
        //printf("y=%d\n",y);
        status[y]++;
        y/=2;
    }

    //printf("temp=%d\n",temp);
    //printf("status[2]=%d\n",status[2]);
    for(int i=temp;i>=1;i--)
    {
        if(status[i]>=2)
        {
            printf("%d",i);
            break;

        }
    }
    return 0;
}

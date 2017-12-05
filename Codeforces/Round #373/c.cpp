#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=200000+10;
char s[maxn];
int n,pos,length,pos_end,time,a[maxn],cost[maxn];
int main(void)
{
    cin>>n;
    cin>>time;
    scanf("%s",s);

    memset(cost,-1,sizeof(cost));
    length=strlen(s);
    for(int i=0;i<length;i++)
    {
        if(s[i]=='.')
        {
            pos=i;
            break;
        }

    }
    for(int i=length-2;i>pos;i--)
    {
        if(s[i+1]>='5')
            cost[i]=1;
        if((s[i+1]=='4')&&(cost[i+1]!=-1))
            cost[i]=1+cost[i+1];
    }
    if(s[pos+1]>='5')
        cost[pos-1]=1;
    if((s[pos+1]=='4')&&(cost[pos+1]!=-1))
        cost[pos-1]=1+cost[pos+1];
    pos_end=-1;
    for(int i=pos-1;i<length;i++)
    {
        if(i==pos)
            continue;
        if((cost[i]!=-1)&&(cost[i]<=time))
        {
            pos_end=i;
            break;
        }
    }
    //printf("pos_end=%d\n",pos_end);
    if(pos_end==-1)
    {
        printf("%s",s);
    }
    else
    {
        if(s[pos_end]=='9')
        {
            int endposition=-1;
            for(int i=pos_end;i>=0;i--)
            {
                if(i==pos)
                    continue;
                if(s[i]=='9')
                    continue;
                else
                {
                    endposition=i;
                    break;
                }
            }
            if((endposition==-1)&&(s[0]=='9'))
            {
                printf("1");
                for(int i=0;i<=pos_end;i++)
                {
                    if(i==pos)
                        printf(".");
                    else
                        printf("0");
                }

            }
            else
            {
                for(int i=0;i<endposition;i++)
                {
                    printf("%c",s[i]);
                }
                printf("%c",s[endposition]+1);
                for(int i=endposition+1;i<=pos_end;i++)
                {
                    if(i==pos)
                        printf(".");
                    else
                        printf("0");
                }
            }



        }
        else
        {
            s[pos_end]++;
            for(int i=0;i<=pos_end;i++)
                printf("%c",s[i]);
        }
    }
    return 0;
}

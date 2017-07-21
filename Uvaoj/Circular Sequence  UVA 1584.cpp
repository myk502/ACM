#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
char input[110],zuixiao[110],temp[110];
void zhuanhuan(int k)
{
    int n,i,j=0;
    n=strlen(input);
    for(i=k;i<n;i++)
        temp[j++]=input[i];
    for(i=0;i<k;i++)
        temp[j++]=input[i];
    temp[j]='\0';

}
int bijiao(void)
{
    int length_temp,length_zuixiao;
    length_temp=strlen(temp);
    length_zuixiao=strlen(zuixiao);
    int i;
    for(i=0;i<min(length_temp,length_zuixiao);i++)
    {
        if(temp[i]==zuixiao[i])
            continue;
        if(temp[i]<zuixiao[i])
            return 1;
        if(temp[i]>zuixiao[i])
            return 0;
    }
    if(length_temp<length_zuixiao)
        return 1;
    else
        return 0;
}
int main(void)
{
    int i,t,length;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",input);
        length=strlen(input);
        strcpy(zuixiao,input);
        for(i=1;i<length;i++)
        {
            zhuanhuan(i);
            if(bijiao()==1)
                strcpy(zuixiao,temp);
        }
        printf("%s\n",zuixiao);
    }
    return 0;
}

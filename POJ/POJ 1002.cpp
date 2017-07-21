#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
#define zuida 100000
char temp1[300],temp2[100],temp3[]="A2B2C2D3E3F3G4H4I4J5K5L5M6N6O6P7R7S7T8U8V8W9X9Y9";
int n,a[zuida+10];
int chazhao(char input)
{
    int i;
    for(i=0;i<strlen(temp3);i++)
    {
        if(temp3[i]==input)
            return(i);
    }
}
int converse(void)
{
    int length,j,k=0,temp_weizhi;
    length=strlen(temp1);
    for(j=0;j<length;j++)
    {
        if(isdigit(temp1[j]))
            temp2[k++]=temp1[j];
        if((temp1[j]=='-')||(temp1[j]=='Q')||(temp1[j]=='Z'))
            continue;
        if(isupper(temp1[j]))
        {
            temp_weizhi=chazhao(temp1[j]);
            temp_weizhi++;
            temp2[k++]=temp3[temp_weizhi];
        }
    }
    temp2[k]='\0';
    return(atoi(temp2));

}
bool cmp(int a,int b)
{
    return(a>b);
}
void shuchu(int input,int number)
{
    char mykn[10];
    sprintf(mykn,"%07d",input);
    int i;
    for(i=0;i<3;i++)
        printf("%c",mykn[i]);
    printf("-");
    for(i=3;i<7;i++)
        printf("%c",mykn[i]);
    printf(" %d\n",number);
}
int main(void)
{
    int i,j,tempn,num=1,numm=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%s",temp1);
        a[i]=converse();
    }
    sort(a,a+n);
    tempn=a[0];
    for(i=1;i<n;i++)
    {
        if(a[i]==tempn)
            num++;
        else
        {

            if(num>1)
            {
                numm++;
                shuchu(tempn,num);
            }
            num=1;
            tempn=a[i];
        }
     }
     if(num>1)
     {
         numm++;
         shuchu(tempn,num);
     }
    if(numm==0)
            printf("No duplicates.\n");
    return 0;

}

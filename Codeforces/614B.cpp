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
int n,ans_0,temp,iszero,length_input,isugly;
char input[100000+10];
char ans[100000+10];
bool isbeautiful(void)
{
   //char temp[20];
    int length,num_1=0,num_others=0;
    //sprintf(temp,"%d",x);
    length=length_input;
    for(int i=0;i<length;i++)
    {
        if(input[i]=='1')
            num_1++;
        if(input[i]>'1')
            num_others++;
    }
    if((num_others!=0)||(num_1>1))
        return false;
    else
        return true;
}
int find_0(void)
{
    int length,num_0=0;
    //sprintf(temp,"%d",x);
    length=length_input;
    num_0=length-1;
    return num_0;
}
int main(void)
{
    int temp_0;
    cin>>n;
    ans_0=0;
    iszero=0;
    //ans=1;
    isugly=0;
    while(n--)
    {

        scanf("%s",input);
        length_input=strlen(input);
        if((length_input==1)&&(input[0]=='0'))
        {
            iszero=1;
            break;
        }
        if((length_input==1)&&(input[0]=='1'))
            continue;
        {
            if(isbeautiful())
            {
                temp_0=find_0();
                ans_0+=temp_0;
            }
            else
            {
                for(int j=0;j<length_input;j++)
                    ans[j]=input[j];
                ans[length_input]='\0';
                isugly=1;
            }
        }

    }
    if(iszero)
        printf("0");
    else
    {
        if(isugly)
            printf("%s",ans);
        else
            printf("1");
        for(int i=0;i<ans_0;i++)
            printf("%d",0);

    }

    return 0;
}

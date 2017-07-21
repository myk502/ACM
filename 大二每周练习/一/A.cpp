#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
char expression[20];
int ans1,ans2,input,temp,length;
int main(void)
{
    scanf("%s%d",expression,&input);
    length=strlen(expression);
    {
        temp=expression[0]-'0';
        for(int i=1;i<length-1;i+=2)
        {
            if(expression[i]=='+')
            {
                temp+=expression[i+1]-'0';
            }
            else
            {
                temp*=expression[i+1]-'0';
            }
        }
        ans1=temp;
    }//to calculate ans1 which is the left-to-right result
    {
        ans2=0;
        int temp2=expression[0]-'0';
        int i=1;
        while(i<length-1)
        {
            if(expression[i]=='*')
            {
                //ans2+=temp2;
                temp=expression[i-1]-'0';
                for(i+=2;(i<length-1)&&(expression[i]=='*');i+=2)
                {
                    temp*=expression[i-1]-'0';
                }
                temp*=expression[i-1]-'0';
                temp2=temp;
                i-=2;
            }
            else
            {
                ans2+=temp2;
                temp2=expression[i+1]-'0';
            }
            i+=2;
        }
        ans2+=temp2;

    }//to calculate ans2 which is the multiplication-first result
    //printf("ans1=%d\nans2=%d\n",ans1,ans2);
    if(ans1==input)
    {
        if(ans2==input)
        {
            printf("U");
        }
        else
        {
            printf("L");
        }
    }
    else
    {
        if(ans2==input)
        {
            printf("M");
        }
        else
        {
            printf("I");
        }
    }
    return 0;
}

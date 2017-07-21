#include<bits/stdc++.h>
using namespace std;
char key[3000];
int temp_input[100];
int readnum(int x)
{
    int ans=0,cns=1;
    for(int i=0;i<x;i++)
    {
        char temp=getchar();
        while((temp!='0')&&(temp!='1'))
            temp=getchar();
        temp_input[i]=temp-'0';

    }
    for(int i=x-1;i>=0;i--)
    {
        ans+=temp_input[i]*cns;
        cns<<=1;
    }
    return ans;
}
int main(void)
{
    //freopen("in.txt","r",stdin);
    int weishu,j,x;
    char ans;
    while(gets(key)!=NULL)
    {
        //printf("The key is %s\n",key);
        //printf("Step1\n");
        while(weishu=readnum(3))
        {
            //printf("Step2\n");
            while(true)
            {
                //printf("Step3\n");
                j=readnum(weishu);
                if((j+1)==(1<<weishu))
                {
                    break;
                }
                //printf("Step4\n");
                //printf("weishu=%d and j=%d\n",weishu,j);
                x=(1<<weishu)-weishu-1+j;
                //printf("x=%d\n",x);
                ans=key[x];
                printf("%c",ans);
            }
        }
        printf("\n");
        scanf(" ");
    }
    return 0;
}

#include<stdio.h>
#include<string.h>
#include<iostream>
#include<limits.h>
#include<math.h>
#include<algorithm>
#include<ctype.h>
using namespace std;
char temp[20];
char temp_bijiao[20];
int input[20];
int a[30];
int main(void)
{
    int t,length;
    long long x,bijiao;
    cin>>t;
    while(t--)
    {
        scanf("%I64d",&x);

        sprintf(temp,"%I64d",x);
        length=strlen(temp);

        if(length%2==1)
        {
            for(int i=1;i<=(length+1)/2;i++)
                printf("4");
            for(int i=1;i<=(length+1)/2;i++)
                printf("7");
            printf("\n");
        }
        else
        {
            int hehe=0;
            bijiao=0;
            for(int i=0;i<length/2;i++)
                a[i]=4;
            for(int i=length/2;i<length;i++)
                a[i]=7;
            /*
            for(int i=0;i<length;i++)
                printf("%d",a[i]);
            printf("\n");
            */
            for(int i=0;i<length;i++)
                temp_bijiao[i]=a[i]+'0';
            temp_bijiao[length]='\0';
            if(strcmp(temp,temp_bijiao)<=0)
            {
                printf("%s\n",temp_bijiao);
                hehe=1;
            }
            if(hehe==0)
                while(next_permutation(a,a+length))
                {
                    for(int i=0;i<length;i++)
                        temp_bijiao[i]=a[i]+'0';
                    temp_bijiao[length]='\0';
                    if(strcmp(temp,temp_bijiao)<=0)
                    {
                        printf("%s\n",temp_bijiao);
                        hehe=1;
                        break;
                    }
                }
            if(hehe==0)
            {
                for(int i=0;i<length/2+1;i++)
                printf("4");
                for(int i=length/2+1;i<length+2;i++)
                printf("7");
                printf("\n");
            }
        }

    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int a[110],b[110],n,num1[30],num2[30];
bool flag;
char input_a[110],input_b[110];
int main(void)
{
    while(scanf("%s%s",input_a,input_b)!=EOF)
    {
        memset(num1,0,sizeof(num1));
        memset(num2,0,sizeof(num2));
        n=strlen(input_a);
        for(int i=0;i<n;i++)
        {
            a[i]=input_a[i]-'A';
            num1[a[i]]++;
        }
        for(int i=0;i<n;i++)
        {
            b[i]=input_b[i]-'A';
            num2[b[i]]++;
        }
        sort(num1,num1+26);
        sort(num2,num2+26);
        flag=true;
        for(int i=0;i<26;i++)
        {
            if(num1[i]!=num2[i])
                flag=false;
        }
        if(flag)
            printf("YES\n");
        else
            printf("NO\n");
    }
}

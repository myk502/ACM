#include<bits/stdc++.h>
using namespace std;
const int maxn=100000+10;
char a[maxn],b[maxn];
int length_a,length_b,N[maxn];
int* buildNext(char *P)
{
    int m=strlen(P),j=0;
    int *N=new int[m];
    int t=N[0]=-1;
    while(j<m-1)
    {
        if(0>t||P[j]==P[t])
        {
            j++;
            t++;
            N[j]=t;
        }
        else
            t=N[t];
    }
    return N;
}
int match(char *P,char *T)
{
    int *next=buildNext(P);
    int n=strlen(T);
    int m=strlen(P);
    int i=0,j=0;
    while(j<m&&i<n)
        if(0>j||T[i]==P[j])
    {
        i++;
        j++;
    }
    else
        j=next[j];
    delete []next;
    if(i==n)//如果i指针到了文本串末尾，说明此时j为i的后缀匹配个数
        return j;
    else
        return 0;
}
int main(void)
{
     while(scanf("%s%s",a,b)!=EOF)
     {
         length_a=strlen(a);
         length_b=strlen(b);
         int x=match(a,b),y=match(b,a);
         if(x==y)
         {
             if(strcmp(a,b)<=0)
                printf("%s%s\n",a,b+x);
             else
                printf("%s%s\n",b,a+x);
         }
         if(x>y)//b to a
         {
             printf("%s",b);
             for(int i=x;i<length_a;i++)
                printf("%c",a[i]);
             printf("\n");
         }
         if(x<y)
         {
             printf("%s",a);
             for(int i=y;i<length_b;i++)
                printf("%c",b[i]);
             printf("\n");
         }

     }
    return 0;
}

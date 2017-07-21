#include<iostream>
#include<cstdio>
#include<algorithm>
#include<stack>
#include<cstring>
using namespace std;
const int maxn=400000+10;
char s[maxn];
int n,N[maxn];
stack<int> ANS;
void buildNext(void)
{
    int j=0,t=-1;
    N[0]=-1;
    while(j<n-1)
        if(0>t||(s[j]==s[t]))
        {
            j++;
            t++;
            N[j]=t;
        }
        else
            t=N[t];
}
int main(void)
{
    int x;
    while(scanf("%s",s)!=EOF)
    {
        while(!ANS.empty())
            ANS.pop();
        n=strlen(s);
        s[n]='0';
        s[n+1]='\0';
        n++;
        buildNext();
        n--;
        /*
        for(int i=0;i<n;i++)
            printf("next[%d]=%d\n",i,N[i]);
        */
        ANS.push(n);
        x=n;
        while(x!=-1)
        {
            x=N[x];
            if(x==0)
                break;
            ANS.push(x);
        }
        while(!ANS.empty())
        {
            printf("%d ",ANS.top());
            ANS.pop();
        }
        printf("\n");
    }
    return 0;
}



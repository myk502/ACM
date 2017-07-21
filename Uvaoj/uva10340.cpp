#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
char s[100000+10],t[100000+10];
int main(void)
{
    int flag,length_s,length_t;
    while(scanf("%s%s",s,t)!=EOF)
    {
        length_s=strlen(s);
        length_t=strlen(t);
        flag=0;
        for(int i=0;i<length_t;i++)
        {
            if(t[i]==s[flag])
            {
                flag++;
            }
        }
        if(flag==length_s)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}

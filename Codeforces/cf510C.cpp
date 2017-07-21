#include<stdio.h>
#include<string.h>
#include<queue>
#include<math.h>
#include<algorithm>
using namespace std;
int n,status=1;
char temp1[110],temp2[110];
int a[30][30],indegree[30],b[30],bnum=0;
queue <int> q;
int zhuanhuan(char x)
{
    return(x-96);
}
void paint(void)
{
    int str1,str2,str,statusn=0;
    str1=strlen(temp1);
    str2=strlen(temp2);
    str=min(str1,str2);
    for(int i=0;i<str;i++)
    {
        int x1=zhuanhuan(temp1[i]);
        int x2=zhuanhuan(temp2[i]);
        if(x1!=x2)
        {
            statusn=1;
            if(a[x1][x2]==1)//ÖØÒª£¡£¡£¡£¡£¡
            {
                break;
            }
            a[x1][x2]=1;
            indegree[x2]++;
            //printf("%c - %c\n",temp1[i],temp2[i]);
            break;
        }
    }
    if(statusn==0)
    {
        if(str1>str2)
        {
            status=0;
        }
    }
}

void kahn(void)
{
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        b[bnum++]=x;
        for(int j=1;j<=26;j++)
        {
            if(a[x][j]==1)
            {
                a[x][j]=0;
                indegree[j]--;
                if(indegree[j]==0)
                    q.push(j);
            }
        }
    }
    for(int i=1;i<=26;i++)
    for(int j=1;j<=26;j++)
    {
        if(a[i][j]>0)
            status=0;
    }
}
int main(void)
{
    memset(a,0,sizeof(a));
    memset(indegree,0,sizeof(indegree));
    status=1;
    scanf("%d",&n);
    scanf("%s",temp1);
    for(int i=1;i<n;i++)
    {
        scanf("%s",temp2);
        paint();
        int j;
        for(j=0;j<strlen(temp2);j++)
            temp1[j]=temp2[j];
        temp1[j]='\0';
    }
    for(int i=1;i<=26;i++)
        if(indegree[i]==0)
            q.push(i);
    kahn();
    if(status==0)
        printf("Impossible");
    else
    {
        for(int i=0;i<bnum;i++)
            printf("%c",b[i]+96);
    }
    return 0;
}

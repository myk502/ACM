#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int a[1010][5],b[1010];//a stands for the frequency each alphabet occurs in each position,b stands for the answer string
//a b starts from 1
int n,m,ans;
char temp[1010];
int chartonum(char x)
{
    switch (x)
    {
        case 'A':return 1;
        case 'C':return 2;
        case 'G':return 3;
        case 'T':return 4;
    }
}
char numtochar(int x)
{
    switch (x)
    {
        case 1:return 'A';
        case 2:return 'C';
        case 3:return 'G';
        case 4:return 'T';
    }
}
void duru(void)
{
    int temp_num;
    scanf("%s",temp);
    for(int i=0;i<n;i++)
    {
        temp_num=chartonum(temp[i]);
        a[i+1][temp_num]++;
    }


}
void bijiao(int x)
{
    int temp_zuida=a[x][1];
    int index_zuida=1;
    for(int i=2;i<=4;i++)
    {
        if(a[x][i]>temp_zuida)
        {
            temp_zuida=a[x][i];
            index_zuida=i;
        }
    }
    ans+=a[x][1]+a[x][2]+a[x][3]+a[x][4]-a[x][index_zuida];
    b[x]=index_zuida;
}
int main(void)
{
    int casenum;
    scanf("%d",&casenum);
    while(casenum--)
    {
        memset(a,0,sizeof(a));

        ans=0;
        scanf("%d%d",&m,&n);
        for(int i=0;i<m;i++)
            duru();
        for(int i=1;i<=n;i++)
        {
            bijiao(i);
        }
        for(int i=1;i<=n;i++)
        {
            printf("%c",numtochar(b[i]));
        }
        printf("\n%d\n",ans);

    }
    return 0;
}

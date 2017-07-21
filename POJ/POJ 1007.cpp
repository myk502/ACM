#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int n,m;
struct myk{
int num;
char yuansu[51];
};
myk a[101];
bool cmp(myk a,myk b)
{
    return(a.num<b.num);
}
int chazhao(int input)
{
    int i,j,temp=0;
    for(i=0;i<n;i++)
        for(j=i+1;j<n;j++)
        if(a[input].yuansu[i]>a[input].yuansu[j])
            temp++;
    return(temp);
}
int main(void)
{

    scanf("%d%d",&n,&m);
    int i,j;
    for(i=0;i<m;i++)
    {
        scanf("%s",a[i].yuansu);
        a[i].num=chazhao(i);
    }
    sort(a,a+m,cmp);
    for(i=0;i<m;i++)
        printf("%s\n",a[i].yuansu);
    return 0;



}

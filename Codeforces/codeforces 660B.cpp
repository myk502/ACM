#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<limits.h>
#include<ctype.h>
int n,m,index_a=0,index_b=0,index_c=0,index_d=0,num=0,max_index;
using namespace std;
int a[110]={0},b[110]={0},c[110]={0},d[110]={0};
void shuru(void)
{
    int temp_num=m;
    while((num<2*n)&&(num<m))
    {
        if(num%2==0)
        {
            a[++index_a]=num+1;
            num++;
        }
        else
        {
            d[++index_d]=num+1;
            num++;
        }
    }
    while(num<m)
    {
        if(num%2==0)
        {
            b[++index_b]=num+1;
            num++;
        }
        else
        {
            c[++index_c]=num+1;
            num++;
        }
    }

}
void shuchu(void)
{

    for(int i=1;i<=max_index;i++)
    {
        if(b[i]!=0)
            printf("%d ",b[i]);
        if(a[i]!=0)
            printf("%d ",a[i]);
        if(c[i]!=0)
           printf("%d ",c[i]);
        if(d[i]!=0)
            printf("%d ",d[i]);
    }



}
int main(void)
{
    scanf("%d%d",&n,&m);
    shuru();
    max_index=max(index_a,index_b);
    max_index=max(max_index,index_c);
    max_index=max(max_index,index_d);
    shuchu();
    return 0;
}

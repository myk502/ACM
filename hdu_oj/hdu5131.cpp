#include<iso646.h.>
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
struct myk
{
  int data;
  char name[60];
};
myk a[300];
int chong,m,n,i,j,weizhi,temp1;
char temp[60];
bool panduan(myk u,myk v)
{
    if(strcmp(u.name,v.name)<0)
        return true;
    else return false;
}
bool compare(myk u,myk v)
{
    if(u.data==v.data)
    {
        if(panduan(u,v))
            return true;
        else return false;
    }
    else
        return(u.data>v.data);
}
int xunzhao(void)
{
    int i=0;
    while(strcmp(temp,a[i].name)!=0)
      i++;
    return i;

}
int main(void)
{
    while(scanf("%d",&n) &&(n!=0))
    {
        for(i=0;i<n;i++)
            scanf("%s%d",a[i].name,&a[i].data);
        sort(a,a+n,compare);
        for(i=0;i<n;i++)
        {
            printf("%s %d\n",a[i].name,a[i].data);
        }
        scanf("%d",&m);
        for(i=0;i<m;i++)
        {
            scanf("%s",temp);
            weizhi=xunzhao();
            temp1=chong=0;
            for(j=0;j<weizhi;j++)
            {
                if(a[j].data==a[weizhi].data)
                  chong++;
                else temp1++;

            }
            if(chong==0)
                printf("%d\n",temp1+1);
            else printf("%d %d\n",temp1+1,chong+1);

        }

    }
    return 0;
}

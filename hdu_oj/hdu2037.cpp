#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<iso646.h>
using namespace std;
#define PI 3.1415927
 struct myk{
 int start;
 int stop;};
 myk a[101];
 int sum;
 bool cmp(myk a,myk b)
 {
     return (a.stop<b.stop);
 }
void nidongde(int i,int n)
 {
     int j;
     for(j=i+1;j<n;j++)
     {
         if(a[i].stop<=a[j].start)
         {
             sum++;
             nidongde(j,n);
             break;
         }
     }

 }
 int main(void)
 {
     int i,n;
     while((scanf("%d",&n)!=EOF) and (n!=0))
     {
         for(i=0;i<n;i++)
            scanf("%d %d",&a[i].start,&a[i].stop);

     sort(a,a+n,cmp);
     sum=1;
     nidongde(0,n);
     printf("%d\n",sum);



     }
     return 0;
 }

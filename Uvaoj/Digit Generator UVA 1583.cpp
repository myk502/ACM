#include<stdio.h>
#include<string.h>
int a[100010];
int yunsuan(int input)
{
    char temp[10];
    sprintf(temp,"%d",input);
    int sum=0,i,length;
    length=strlen(temp);
    for(i=0;i<length;i++)
      sum+=(temp[i]-'0');
    sum+=input;
    return sum;

}
int chazhao(int input)
{
    int i;
    for(i=1;i<=100000;i++)
      if(a[i]==input)
        return i;
    return 0;

}
int main(void)
{
    int ans,i,n,input;
    scanf("%d",&n);
    for(i=1;i<=100000;i++)
        a[i]=yunsuan(i);
    printf("a[198]=%d\n",a[198]);
    for(i=0;i<n;i++)
    {
        scanf("%d",&input);
        ans=chazhao(input);
        printf("%d\n",ans);
    }
    return 0;
}

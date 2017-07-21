#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+100;
char a[maxn],b[maxn];
int length_a,length_b,pre[maxn],suf[maxn];
void print_ans(int i,int j)
{
    for(int k=1;k<=i;k++)
        printf("%c",b[k]);
    for(int k=length_b-j+1;k<=length_b;k++)
        printf("%c",b[k]);
}
bool check(int i,int j)
{
    if(pre[i]+suf[j]<=length_a)
        return true;
    else
        return false;
}
int main(void)
{
    int j;
    int ans=0,ans_i=-1,ans_j=-1;
    scanf("%s%s",a+1,b+1);
    length_a=strlen(a+1);
    length_b=strlen(b+1);
    pre[0]=suf[0]=0;
    j=1;
    for(int i=1;i<=length_b;i++)
    {
        while((j<=length_a)&&(b[i]!=a[j]))
            j++;
        if(j<=length_a)
        {
            pre[i]=j;
            j++;
        }
        else
            pre[i]=1e6;
    }
    j=0;
    for(int i=0;i<length_b;i++)
    {
        while((j<length_a)&&(a[length_a-j]!=b[length_b-i]) )
            j++;
        if(j<length_a)
        {
            suf[i+1]=j+1;
            j++;
        }
        else
            suf[i+1]=1e6;
    }
    /*
    for(int i=1;i<=length_b;i++)
        printf("pre[%d]=%d   suf[%d]=%d\n",i,pre[i],i,suf[i]);
    */
    for(int i=0;i<=length_b;i++)//calculate max j for each i
    {
        int *pos=upper_bound(suf+1,suf+(length_b+1-i),length_a-pre[i]);
        j=pos-suf;
        if((j>=0)&&(pre[i]+suf[j-1]<=length_a)&&(i+j>ans))
        {
            ans=i+j-1;
            ans_i=i;
            ans_j=j-1;
            //cout<<i<<" "<<j-1<<endl;
        }
    }
    if(ans==0)
        printf("-");
    else
        print_ans(ans_i,ans_j);
    return 0;
}

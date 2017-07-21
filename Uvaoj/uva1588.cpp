#include<stdio.h>
#include<iostream>
#include<string.h>
#include<limits.h>
#include<math.h>
#include<algorithm>
using namespace std;
int a[300],b[300];
char aa[210],bb[210];
int main(void)
{
    //freopen("in.txt","r",stdin);
    //freopen("out2.txt","w",stdout);
    int ans,ans1,ans2,length_a,length_b,index_a,index_b,status=1;
    while(scanf("%s%s",aa,bb)!=EOF)
    {
        status=1;
        ans1=ans2=INT_MAX;
        length_a=strlen(aa);
        length_b=strlen(bb);
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        for(int i=0;i<length_a;i++)
            a[i]=aa[i]-'0';
        for(int i=0;i<length_b;i++)
            b[i]=bb[i]-'0';

        for(int i=0;i<=length_a;i++)
        {
            status=1;
            for(index_a=i,index_b=0;index_b<100;index_a++,index_b++)
            {
                if(a[index_a]+b[index_b]>3)
                {
                    status=0;
                    break;
                }
            }
            if(status==1)
            {
                ans1=max(length_a,i+length_b);
                break;
            }
        }
        for(int i=0;i<=length_b;i++)
        {
            status=1;
            for(index_b=i,index_a=0;index_a<100;index_a++,index_b++)
            if(a[index_a]+b[index_b]>3)
            {
                status=0;
                break;
            }
                if(status==1)
                {
                    ans2=max(i+length_a,length_b);
                    //printf("Now ans2=%d and i=%d\n",ans2,i);
                    break;
                }

        }
        ans=min(ans1,ans2);
        cout<<ans<<endl;
    }
    return 0;
}

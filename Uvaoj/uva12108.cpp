#include<bits/stdc++.h>
using namespace std;
int n,num_awake,num_sleep;
int status[11],a[11],b[11];
bool check(int i)//if the student No.1 is asleep return false,else return true
{
    status[i]++;
    //printf("a[%d]=%d,b[%d]=%d,status[%d]=%d\n",i,a[i],i,b[i],i,status[i]);
    status[i]%=(a[i]+b[i]);
    if(status[i]<a[i])//continue to be awaken
    {
        return true;
    }
    if(status[i]==a[i])//the check point
    {
        if(num_sleep>num_awake)//choose to sleep
        {
            return false;
        }
        else
        {
            status[i]=0;//choose not to sleep,hang on for another a seconds
            return true;
        }

    }
    if(status[i]>a[i])
        return false;
}
int main(void)
{
    int cas=0,ans,temp_awake,temp_sleep;
    //freopen("in","r",stdin);
    while(cin>>n)
    {
        if(n==0)
            break;
        cas++;
        ans=-1;
        num_awake=num_sleep=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d%d",&a[i],&b[i],&status[i]);
            status[i]--;//easy to take mod,now status[i] is from 0 to a+b(exclusive)
            if(status[i]<a[i])//this student is awake
                num_awake++;
            else
                num_sleep++;
        }
        if(num_sleep==0)
        {
            printf("Case %d: %d\n",cas,1);
            continue;
        }
        for(int t=2;t<=1000000;t++)
        {
            temp_awake=temp_sleep=0;
            for(int i=1;i<=n;i++)
            {
                if(check(i))//he will be awaken
                    temp_awake++;
                else
                    temp_sleep++;

            }
            if(temp_sleep==0)
            {
                ans=t;
                break;
            }
            num_awake=temp_awake;
            num_sleep=temp_sleep;
        }
        printf("Case %d: %d\n",cas,ans);

    }
    return 0;
}

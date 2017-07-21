#include<cstdio>
#include<cstring>
#include<cmath>
#include<climits>
#include<iostream>
#include<algorithm>
using namespace std;
int a[100000+10];
int main(void)
{
    int t,n,s,sum,length,ans;
    cin>>t;
    while(t--)
    {
        cin>>n>>s;
        ans=INT_MAX;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);

        }
        int j,k;
        j=k=0;
        sum=0;
        if(1)
        {
             while((k<n)&&(sum<s))
            {
                sum+=a[k];
                k++;
            }
        }
        //printf("sum=%d\n",sum);
        if((k==n)&&(sum<s))
        {
            cout<<0<<endl;
            continue;//important!
        }
        length=k-j;
        //printf("length=%d\n",length);
        ans=min(length,ans);
        while(1)
        {
            while((k<n)&&(sum<s))
            {
                sum+=a[k];
                k++;
            }
            if((k==n)&&(sum<s))
            {
                //length=k-j;
                //ans=min(length,ans);
                break;
            }
            length=k-j;
            ans=min(length,ans);
            sum-=a[j];
            j++;
        }
        cout<<ans<<endl;


    }
    return 0;
}

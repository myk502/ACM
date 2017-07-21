#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int a[25];
int main(void)
{
    int j,n,k,m,num_a,num_b,num,temp;
    while(cin>>n>>k>>m)
    {
        if((n==0)&&(k==0)&&(m==0))
            break;
        memset(a,-1,sizeof(0));
        num=0;
        num_a=-1;
        num_b=n;
        for(int i=0;i<n;i++)
            a[i]=i+1;
        while(1)
        {

            if(num==n)
                break;
            if(num!=0)
                printf(",");
            j=0;
            temp=num_a;
            while(j<k)
            {
                temp=(temp+1)%n;
                if(a[temp]!=-1)
                    j++;
            }
            //printf("Now temp=%d\n",temp);
            {
                num++;
                printf("%3d",a[temp]);
                //a[temp]=-1;
                num_a=temp;
            }
            if(num==n)
                break;
            temp=num_b;

            j=0;
            while(j<m)
            {
                temp=temp-1;
                if(temp<0)
                    temp+=n;
                if(a[temp]!=-1)
                    j++;
            }
            num_b=temp;
            if(num_b!=num_a)
            {
                num++;
                printf("%3d",a[temp]);
                a[temp]=-1;
                num_b=temp;
            }
            a[num_a]=-1;

        }
        printf("\n");
    }
    return 0;
}

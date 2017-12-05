#include<bits/stdc++.h>
using namespace std;
int n,a[100000+10],num_ji=0,num_ou=0;
int main(void)
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]%2==1)
            num_ji++;
        else
            num_ou++;
        if(num_ou%2==0)
            printf("2\n");
        else
            printf("1\n");
    }
    return 0;
}

#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
long long a[10];
int main(void)
{
    a[0]=0;
    a[1]=2;
    a[2]=11;
    a[3]=18;
    a[4]=30;
    cout<<upper_bound(a,a+4,20)-a;
    return 0;
}

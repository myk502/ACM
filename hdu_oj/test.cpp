#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int a=1<<30;
    int b=1e9;
    if(a>b)
        printf("1<<30 > b\n");
    else
        printf("1<<30 < b\n");
    return 0;
}

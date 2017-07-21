#include<bits/stdc++.h>
using namespace std;
int d,l,v1,v2;
int main(void)
{
    cin>>d>>l>>v1>>v2;
    double ans=(double)(l-d)/(double)(v1+v2);
    printf("%.10f",ans);
    return 0;
}

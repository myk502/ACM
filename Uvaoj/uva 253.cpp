#include<bits/stdc++.h>
using namespace std;
char input[20];
int a[10],b[10];
int change(char x)
{
    switch (x)
    {
        case 'r':return -1;
                 break;
        case 'g':return 0;
                 break;
        case 'b':return 1;
                 break;
    }
}
struct pir
{
    int first;
    int second;
    pir(int x,int y)
    {
        first=min(x,y);
        second=max(x,y);
    }
    pir()
    {

    }
    bool operator ==(const pir &X)
    {
        return((first==X.first)&&(second==X.second));
    }
};
pir aa[5],bb[5];
bool cmp(pir x,pir y)
{
    if(x.first!=y.first)
        return x.first<y.first;
    else
        return x.second<y.second;
}
int main(void)
{
    while(scanf("%s",input)!=EOF)
    {
        int x=0;
        for(int i=1;i<=6;i++,x++)
            a[i]=change(input[x]);
        for(int i=1;i<=6;i++,x++)
            b[i]=change(input[x]);
        aa[0]=pir(a[1],a[6]);
        aa[1]=pir(a[2],a[5]);
        aa[2]=pir(a[3],a[4]);
        bb[0]=pir(b[1],b[6]);
        bb[1]=pir(b[2],b[5]);
        bb[2]=pir(b[3],b[4]);
        sort(aa,aa+3,cmp);
        sort(bb,bb+3,cmp);
        if((aa[0]==bb[0])&&(aa[1]==bb[1])&&(aa[2]==bb[2]))
            printf("TRUE\n");
        else
            printf("FALSE\n");

    }
    return 0;
}

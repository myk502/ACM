#include<bits/stdc++.h>

using namespace std;

#define NMAX 1000
#define LMAX 100

char str[2][LMAX+10];
vector<int> c[NMAX+10];
int d[NMAX+10];

int main(void)
{
    int n=0,m,k,p;
    int tmp1,tmp2;
    int s;
    int i,j;
    int ne,pc;

    while(true){
        memset(d,0,sizeof(d));
        for(i=0;i<=n;i++)c[i].clear();
        scanf("%d%d%d",&n,&m,&k);
        if(n==0&&m==0&&k==0)break;
        scanf("%d",&p);
        for(i=0;i<p;i++){
            scanf("%s%d%s%d",str[0],&tmp1,str[1],&tmp2);
            if(str[0][0]=='c')c[tmp1].push_back(tmp2);
            else d[tmp1]++;
        }
        for(i=1;i<=n;i++)sort(c[i].begin(),c[i].end());
        s=0;
        for(i=1;i<=n;i++){
            ne=c[i].size();
            pc=0;
            for(j=1;j<=m;j++){
                if(pc<ne&&c[i][pc]==j){
                    pc++;
                    continue;
                }
                s+=k-d[j];
            }
        }
        printf("%d\n",s);
    }
    return 0;
}

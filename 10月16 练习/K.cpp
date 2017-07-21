#include <cstdio>

using namespace std;

typedef long long ll;

int n;

struct rab{
    int d0,v,it;
};

rab r[2];
char str[10];

int ctod(char c){
    switch(c){
        case 'E':return 0;
        case 'N':return 1;
        case 'W':return 2;
        case 'S':return 3;
    }
}

struct pos{
    int x,y;
};

struct cond{
    int t;
    pos p[2];

    cond next()const{
        int
    }
};

int main(){
    int n,k;
    cond tc;
    int i;

    while(true){
        scanf("%d",&n);
        for(i=0;i<2;i++){
            scanf("%s%d%d",str,&rab[i].v,&rab[i].it);
            rab[i].d0=ctod(str[0]);
        }
        scanf("%d",&k);
        tc.t=0;
        for(i=0;i<k;i++)tc=tc.next();
    }
}

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

#define NMAX 1100

struct xp{
    int c,p;
    bool operator < (const xp &b)const{
        return (p==b.p)?(c<b.c):(p>b.p);
    }
};

struct ad{
    vector<xp> x;

    void s(){sort(x.begin(),x.end());}
    bool operator < (const ad &b)const{
        (x[0].p==b.x[0].p)?(x[0].c<b.x[0].c):(x[0].p<b.x[0].p);
    }
};

struct mu{
    vector<ad> f;

    void s(){
        int ne=f.size(),i;
        for(i=0;i<ne;i++)f[i].s();
        sort(f.begin(),f.end());
    }
};

void gen(int n,bool b,int op,mu &p){
    if(b){
        if(n%2){
            ad a;
            a.x.push_back((xp){1,1});
            a.x.push_back((xp){-1,0});
            p.f.push_back(a);
            a.x.clear();
            for(i=n-1;i>=0;i--)
                a.x.push_back((xp){((i%2)?-1:1),i});
            p.f.push_back(a);
        }else{
            int q,num=0;
            int i;
            for(q=n;!(q%2);q/=2)num++;
            gen(q,true,num*op,p);
        }
    }else{
        if(n%2){
            ad a;
            a.x.push_back((xp){1,1});
            a.x.push_back((xp){-1,0});
            p.f.push_back(a);
            a.x.clear();
            for(i=n-1;i>=0;i--)
                a.x.push_back((xp){1,i});
            p.f.push_back(a);
        }else{
            gen(n/2,true,op,p);
        }
    }
    p.s();
}

mu p;

int main(){
    int n;
    int i,j;

    while(true){
        scanf("%d",&n);
        if(n==0)break;
        gen(n,false,1,p);
        for(i=0;i<p.x.size();i++){
            vector<xp> &x=p.f[i].x;
            for(j=0;j<x.size();j++){
                if(x[j].c>0)putchar('+');
                else putchar('-');
                printf("%d ",x[j].p);
            }
            putchar('\n');
        }
        p.f.clear();
    }
}

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
        if(x[0].p!=b.x[0].p)return x[0].p<b.x[0].p;
        //if(x.size()!=b.x.size())return x.size()<b.x.size();
        int i;
        for(i=0;i<x.size();i++)
            if(x[i].c!=b.x[i].c)return x[i].c<b.x[i].c;
    }
};

struct mu{
    vector<ad> f;

    void s(){
        int ne=f.size();
        int i;
        for(i=0;i<ne;i++)f[i].s();
        sort(f.begin(),f.end());
    }
};

void gen(int n,bool b,int op,mu &p){
    if(b){
        if(n%2){
            ad a;
            int i;

            a.x.push_back((xp){1,op});
            a.x.push_back((xp){1,0});
            p.f.push_back(a);
            a.x.clear();
            for(i=n-1;i>=0;i--)
                a.x.push_back((xp){((i%2)?-1:1),i*op});
            p.f.push_back(a);
        }else{
            int q,ndq;
            for(q=n;!(q%2);q/=2);
            ndq=n/q;
            gen(q,true,ndq*op,p);
        }
    }else{
        if(n%2){
            ad a;
            int i;

            a.x.push_back((xp){1,op});
            a.x.push_back((xp){-1,0});
            p.f.push_back(a);
            a.x.clear();
            for(i=n-1;i>=0;i--)
                a.x.push_back((xp){1,i*op});
            p.f.push_back(a);
        }else{
            gen(n/2,true,op,p);
            gen(n/2,false,op,p);
        }
    }
}

int n;
mu p;

void output(){
    int i,j;

    p.s();
    int sp=p.f.size();
    for(i=0;i<sp;i++){
        vector<xp> &x=p.f[i].x;
        int sx=x.size();

        if(x[0].p==0)continue;
        if(n!=1)putchar('(');

        for(j=0;j<sx;j++){
            if(j!=0&&x[j].c>0)putchar('+');
            if(x[j].c<0)putchar('-');

            if(x[j].p==0)putchar('1');
            else if(x[j].p==1)putchar('x');
            else{
                printf("x^%d",x[j].p);
            }
        }
        if(n!=1)putchar(')');
    }
    putchar('\n');
}

int main(){
    int i,j;

    //freopen("f.out","w",stdout);

    while(true){
        scanf("%d",&n);
        if(n==0)break;
        gen(n,false,1,p);
        output();
        p.f.clear();
    }
}

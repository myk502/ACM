#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<map>
#include<set>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m;
string a[10000+10][10+2];
char input[100];
typedef pair<string,string> Pair;
map<Pair,int> s;
int main(void)
{
    char* ptr;//take care!
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        bool flag=true;
        for(int i=0;i<n;i++)//for each row
        {
            int j=0;
            scanf("\n");
            gets(input);
            ptr=strtok(input,",");
            while(ptr!=nullptr)
            {
                a[i][j++]=string(ptr);
                //printf("%s\n",ptr);
                ptr=strtok(nullptr,",");
            }
   
        }
        for(int aa=0;aa<m;aa++)
            for(int bb=aa+1;bb<m;bb++)
            {
                s.clear();
                if(flag==false)
                    break;
                for(int i=0;i<n;i++)
                {
                    Pair mypair=make_pair(a[i][aa],a[i][bb]);
                    if(s.count(mypair)==1)//This is not a PNF
                    {
                        printf("NO\n");
                        printf("%d %d\n",s[mypair]+1,i+1);
                        printf("%d %d\n",aa+1,bb+1);
                        flag=false;
                        break;
                    }
                    else
                    {
                        s[mypair]=i;
                    }
                }
            }
        if(flag)
            printf("YES\n");
    

    }
    return 0;
}

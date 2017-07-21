#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int maxhp[2005];
int hp[2005];
int hd[2005];
int n,a,b,x;
int solve(int type)
{
    if(type == 1) return x;
    else return a;
}
int main()
{
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d%d",&n,&x,&a,&b);
        int boss;
        memset(maxhp,-1,sizeof(maxhp));
        memset(hd,0,sizeof(hd));
        for(int i=0;i<n;i++)
        {
            int wi,hi;
            scanf("%d%d",&wi,&hi);
            wi+=1000;
            if(i == 0) boss = wi;
            hp[wi] = maxhp[wi] = hi;
        }
        int now = boss;
        int attack = x;
        int type = 1;
        int q;
        scanf("%d",&q);
        while(q--)
        {
            char s[15];
            scanf("%s",s);
            if(strcmp(s,"jihuo") == 0)
            {
                int k;
                scanf("%d",&k);
                k+=1000;
                if(maxhp[k] == -1)
                {
                    printf("nitemezaidouwo\n");
                    continue;
                }
                if(now == k)
                {
                    printf("shoudao\n");
                    continue;
                }
                now = k;
                attack = solve(type);
                printf("shoudao\n");
                continue;
            }
            if(strcmp(s,"gongji") == 0)
            {
                if(now == 2001)
                {
                    printf("womeiyoumubiao\n");
                    continue;
                }
                printf("ok\n");
                if(hd[now] != 0) hd[now]--;
                else
                {
                    hp[now] -= attack;
                    if(hp[now] <= 0)
                    {
                        maxhp[now] = -1;
                        hp[now] = 0;
                        if(maxhp[boss] == -1) now = 2001;
                        else now = boss;
                        attack = solve(type);
                        continue;
                    }
                }
                if(type == 0) attack += b;
            }
            else if(strcmp(s,"qiehuan") == 0)
            {
                type = !type;
                attack = solve(type);
            }
            else if(strcmp(s,"kill") == 0)
            {
                if(now != boss && now != 2001)
                {
                    printf("chenggong\n");
                    hd[now] = 0;
                    hp[now] = 0;
                    maxhp[now] = -1;
                    if(maxhp[boss] == -1) now = 2001;
                    else now = boss;
                    attack = solve(type);
                    continue;
                }
                printf("shibai\n");
                continue;
            }
            else if(strcmp(s,"huixue") == 0)
            {
                int k,h;
                scanf("%d%d",&k,&h);
                k+=1000;
                if(maxhp[boss] == -1) continue;
                if(maxhp[k] == -1) continue;
                else hp[k]=min(maxhp[k],hp[k]+h);
            }
            else if(strcmp(s,"hudun") == 0)
            {
                int k;
                scanf("%d",&k);
                k+=1000;
                if(maxhp[boss] == -1) continue;
                if(maxhp[k] == -1) continue;
                else hd[k] = 3;
            }
            else if(strcmp(s,"shuaguai") == 0)
            {
                int k,h;
                scanf("%d%d",&k,&h);
                k += 1000;
                if(maxhp[boss] == -1) continue;
                if(maxhp[k] != -1) continue;
                maxhp[k] = hp[k] = h;
            }
        }
        bool flag = 0;
        for(int i = 0;i <= 2000;i++)
        {
            if(maxhp[i] != -1)
            {
                if(!flag) flag = 1;
                else printf(" ");
                printf("%d",hp[i]);
            }
        }
        if(!flag) printf("wozhenshitailihaile");
        printf("\n");
    }
}

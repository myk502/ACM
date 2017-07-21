#include<stdio.h>
#include<algorithm>
using namespace std;
int hp_y,attack_y,defend_y,hp_m,attack_m,defend_m,aa,h,d,i,j,k,hp_jia,num;
struct myk{
int hp;
int attack;
int defend;
long long cost;};
myk a[2000000*2];
long long cnt;
int panduan(int hpy,int attacky,int defendy)
{
    if(attacky<=defend_m)
        return(0);
    else
        if(attack_m<=defendy)
            return(1);
        else
        {
            int tempy,temp_m;
            tempy=attack_m-defendy;
            temp_m=attacky-defend_m;
            int roundy,round_m;
            roundy=(hpy%tempy==0)?(hpy/tempy):(hpy/tempy+1);
            round_m=(hp_m%temp_m==0)?(hp_m/temp_m):(hp_m/temp_m+1);
            if(roundy<=round_m)
                return(0);
            else
                return(1);
        }
}
bool cmp(myk a,myk b)
{
    return(a.cost<b.cost);
}
int main(void)
{
    scanf("%d%d%d%d%d%d%d%d%d",&hp_y,&attack_y,&defend_y,&hp_m,&attack_m,&defend_m,&h,&aa,&d);

    if(panduan(hp_y,attack_y,defend_y))
        printf("0");
    else
    {
        while(attack_y<=defend_m)
        {
            cnt+=aa;
            attack_y++;
        }
        if(panduan(hp_y,attack_y,defend_y))
            printf("%d",cnt);
        else
        {
            //printf("defend_y=%d\n",defend_y);
            for(hp_jia=0;panduan(hp_y+hp_jia,attack_y,defend_y)==0;hp_jia++)
            {
                continue;
            }
            num=0;
            //printf("defend_y=%d\n",defend_y);
            for(i=0;i<=hp_jia;i++)
            for(j=0;j<=hp_m+defend_m-attack_y;j++)
            for(k=0;k<=attack_m-defend_y;k++)
            {
                a[num].hp=hp_y+i;
                a[num].attack=attack_y+j;
                a[num].defend=defend_y+k;
                a[num].cost=cnt+h*i+aa*j+d*k;
                num++;
                if(panduan(a[num-1].hp,a[num-1].attack,a[num-1].defend))
                    break;
            }
            sort(a,a+num,cmp);
            for(i=0;i<num;i++)
            {
                if(panduan(a[i].hp,a[i].attack,a[i].defend))
                {
                    printf("%I64d",a[i].cost);
                    break;
                }
            }

        }

    }
    return 0;
}



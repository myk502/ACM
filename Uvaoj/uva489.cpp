#include<bits/stdc++.h>
using namespace std;
set<char> S;
char ans[10000],guess[10000];
int indexx,length_ans,length_guess,cnt,flag;//flag为-1代表输了，0代表弃权，1代表赢了
int main(void)
{
    // freopen("d:\\out.txt","w",stdout);
    while(scanf("%d",&indexx))
    {
        S.clear();
        cnt=0;
        flag=1;//初始化能赢
        if(indexx==-1)
            break;
        else
            printf("Round %d\n",indexx);
        scanf("%s",ans);
        scanf("%s",guess);
        length_ans=strlen(ans);
        length_guess=strlen(guess);
        for(int i=0;i<length_ans;i++)
        {
            S.insert(ans[i]);
        }
        for(int i=0;i<length_guess;i++)
        {
            if(S.empty())
            {
                break;
            }
            if(S.count(guess[i]))
            {
                S.erase(guess[i]);
            }
            else
            {
                cnt++;
            }
            if(cnt>=7)
            {
                flag=-1;
                break;
            }
        }
        if((flag==1)&&(!S.empty()))
           flag=0;
        if(flag==1)
            printf("You win.\n");
        if(flag==0)
            printf("You chickened out.\n");
        if(flag==-1)
            printf("You lose.\n");
    }
    return 0;
}

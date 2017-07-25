#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
string input;
int n;
vector<string> a;
const long long Mod=1000000000+7;
struct balala
{
    int digit[100010];
    int character;
    balala()
    {
        memset(digit,0,sizeof(digit));
    }
    void clear(void)
    {
        memset(digit,0,sizeof(digit));
    }

    void normalize(void)
    {
        for(int i=0;i<=100000+5;i++)
        {
            digit[i+1]+=digit[i]/26;
            digit[i]%=26;
        }
    }
};
bool cmp(balala X,balala Y)
{
    for(int i=100000+5;i>=0;i--)
    {
        if(X.digit[i]==Y.digit[i])
            continue;
        else
            return X.digit[i]>Y.digit[i];
    }
    return false;//if X==Y
}

balala cnt[26];
int duiying[26],ans[100010];
bool notzero[26], zero_used;
int main(void)
{
    int cas=0;
    long long final_ans;
    int len;
    ios::sync_with_stdio(false);
    while(cin>>n)
    {
        final_ans=0;
        a.clear();
        zero_used = false;
        memset(ans,0,sizeof(ans));
        memset(notzero, 0, sizeof(notzero));
        for(int i=0;i<26;i++)
        {
            cnt[i].clear();
            cnt[i].character=i;
        }
        for(int i=0;i<n;i++)
        {
            cin>>input;
            if(input.length() > 1) {
                notzero[input[0] - 'a'] = true;
            }
            a.push_back(input);
            len=input.length();
            for(int j=len-1;j>=0;j--)
            {
                int id=input[j]-'a';
                cnt[id].digit[len-1-j]++;
            }

        }
        for(int i=0;i<26;i++)
            cnt[i].normalize();

        sort(cnt,cnt+26,cmp);
        //cout<<"mark1"<<endl;
//        for(int i=0;i<26;i++)//number is 25-i
//        {
//            duiying[cnt[i].character]=25-i;
//        }
        int cntt=1;
        for(int i = 25; i >= 0; --i) {
            int id=cnt[i].character;
            if(!zero_used && !notzero[id]) {
                duiying[id] = 0;
                zero_used = true;
                continue;
            }
            duiying[id] = cntt++;
        }
        /*
        for(int i=0;i<26;i++)
            printf("duiying[%d]=%d\n",i,duiying[i]);
        */

        for(int ii=0;ii<a.size();ii++)//for every string in a
        {
            string it=a[ii];
            int len=it.length();
            for(int j=len-1;j>=0;j--)
            {
                int id=it[j]-'a';
                //printf("id=%d\n",id);
                ans[len-1-j]+=duiying[id];
                //printf("ans[%d] now =%d\n",len-1-j,ans[len-1-j]);
            }
        }
        /*
        for(int i=0;i<26;i++)
            printf("ans[%d]=%d\n",i,ans[i]);
        */
        long long exp=1;
        for(int i=0;i<=100000+5;i++)
        {
            final_ans+=ans[i]*exp % Mod;
            final_ans%=Mod;
            exp*=26;
            exp%=Mod;
        }
        cout<<"Case #"<<++cas<<": ";
        cout<<final_ans<<endl;
    }
    return 0;
}

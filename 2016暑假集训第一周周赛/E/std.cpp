#include<iostream>

#define NMAX 100005
using namespace std;

long long fight_power[NMAX];

int main(){
    int T, n;
    long long WH;
//    freopen("stdin.txt", "r", stdin);
//    freopen("stdout.txt", "w", stdout);
    while(scanf("%d", &n) != EOF){
        scanf("%lld", &WH);
        for(int i = 1; i < n; i++){
            scanf("%lld", &fight_power[i]);
        }
        sort(fight_power + 1, fight_power + n);
        int mark = 0;
        for(int i = 1; i < n; i++){
            if(fight_power[i] > WH){
                printf("-1\n");
                mark = 1;
                break;
            }
            else{
                if(fight_power[i] <= WH / 2){
                    WH += fight_power[i];
                }
                else{
                    WH += fight_power[i] / 2;
                }
            }
        }
        if(mark == 0){
            printf("%lld\n", WH);
        }
    }

    return 0;
}

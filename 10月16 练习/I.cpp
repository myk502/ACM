#include<bits/stdc++.h>

int main(void)
{
    int n;
    int tmp,s;
    int i;

    while(true){
        scanf("%d",&n);
        if(n==0)break;
        s=0;
        for(i=0;i<n;i++){
            scanf("%d",&tmp);
            s+=tmp*tmp;
        }
        printf("%d\n",s);
    }
    return 0;
}

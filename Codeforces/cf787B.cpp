#include<bits/stdc++.h>
using namespace std;
int n,m;
int existed[200000+20];
int main(void)
{
    cin>>n>>m; 
    bool flag=false;//at first there is no need to cancel 
    for(int i=0;i<m;i++)
    {
	memset(existed,0,sizeof(existed));  
        int k,input;
        bool temp_flag=false;//at first,consider this group as unsafe
        scanf("%d",&k);
        for(int j=0;j<k;j++)
        {
            scanf("%d",&input);
            if(input>0)
		existed[input]++;
	    else
		existed[(-input)+10000]++;
        }
        for(int j=1;j<=n;j++)
        {
            if(existed[j]>0 && existed[j+10000]>0)//exist 2 people from the same universe
                temp_flag=true;
        }
        if(temp_flag==false)//the group is indeed unsafe
            flag=true;//we need to cancel it

    }
    if(flag)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}

#include<stdio.h>
#include<iso646.h>
#include<limits.h>
#include<algorithm>
#include<math.h>
#include<string.h>
#include<ctype.h>
char mark[5];
int credit_sum,credit[1010];
double chengji_sum,mark_num[1010];
double conversion(char mark[])
{
    switch(mark[0]){
    case 'A':if(mark[1]=='-')
                return 3.7;
             else return 4.0;
             break;
    case 'B':if(mark[1]=='-')
               return 2.7;
             else if(mark[1]=='+')
                  return 3.3;
                  else return 3.0;
             break;
    case 'C':if(mark[1]=='-')
               return 1.7;
             else if (mark[1]=='+')
                  return 2.3;
                  else 2.0;
             break;
    case 'D':if(mark[1]=='-')
               return 1.0;
             else return 1.3;
             break;
    case 'F':return 0;
             break;
    default:return 0;
            break;
    }

}
int main(void)
{
    int i,j,n;
    while(scanf("%d",&n)!=EOF)
    {
        credit_sum=0;
        chengji_sum=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&credit[i]);
            scanf("%s",mark);
            if((mark[0]=='N') or(mark[0]=='P'))
                continue;
            mark_num[i]=conversion(mark);
            chengji_sum+=credit[i]*mark_num[i];
            credit_sum+=credit[i];
        }
        if(credit_sum==0)
            printf("0.00\n");
        else printf("%.2lf\n",(double)chengji_sum/(double)credit_sum);
    }
    return 0;
}

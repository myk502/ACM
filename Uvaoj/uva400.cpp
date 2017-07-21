#include<cstring>
#include<string>
#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n,length;
string a[100];
void print_ans(int x,int y)
{
    for(int i=0;i<60;i++)
        printf("-");
    printf("\n");
    for(int i=0;i<y;i++)
    {
        for(int j=i,cnt=1;j<n;j+=y,cnt++)
        {
            if(cnt==x)//This is the last file of this row
            {
                cout<<a[j];
                for(int k=0;k<length-a[j].length();k++)
                    printf(" ");
                printf("\n");
            }
            else
            {
                cout<<a[j];
                for(int k=0;k<length-a[j].length()+2;k++)
                    printf(" ");
                if(j+y>=n)//This is the last file of the last row
                    printf("\n");
            }
        }
    }
}
int main(void)
{
    int x,num_row,y;//x is the number of file names in a row
    while(cin>>n)
    {
        length=-1;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            length=max(length,(int)a[i].length());
        }
        x=62/(length+2);
        sort(a,a+n);
        if(n%x==0)
            num_row=n/x;
        else
            num_row=n/x+1;
        y=num_row;
        print_ans(x,y);
    }

    return 0;
}

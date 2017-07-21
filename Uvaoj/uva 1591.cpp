#include<iostream>
#include<climits>
#include<cstdio>
using namespace std;
unsigned long long n,sp,sq;
int main(void)
{
    while(cin>>n>>sp>>sq)
    {
        //cout<<n<<"+"<<sp<<"+"<<sq<<endl;
        unsigned long long p_last_offset=(n-1)*sp;
        unsigned long long ans_k=~0UL;
        unsigned long long ans_a,ans_b;
        for(unsigned long long a=0;a<32UL;a++)
            for(unsigned long long b=0;b<32UL;b++)
            {
                unsigned long long k=(p_last_offset+(p_last_offset<<a))>>b;
                k+=sq;

                if(k>=n*sq)//the requirement in the text
                {
                    if(ans_k>k)
                    {
                        ans_k=k;
                        ans_a=a;
                        ans_b=b;
                    }
                    if(ans_k==k)
                    {
                        if(a<ans_a)
                        {
                            ans_a=a;
                            ans_b=b;
                        }
                        if(a==ans_a)
                        {
                            if(b<ans_b)
                                ans_b=b;
                        }
                    }
                }
            }
        cout<<ans_k<<" "<<ans_a<<" "<<ans_b<<endl;

    }
    return 0;
}

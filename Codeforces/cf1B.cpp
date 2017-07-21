#include<cstdio>
#include<iostream>
#include<cmath>
#include<cctype>
#include<cstring>
#include<vector>
#include<string>
using namespace std;
int char2int(string input)
{
    int len=input.length();
    int ans=0,weight=1;
    for(int i=len-1;i>=0;i--,weight*=26)
    {
        ans+=(input[i]-'A'+1)*weight;
    }
    return ans;
}
string int2char(int x)
{
    vector<int> a;
    string ANS;
    while(x)
    {
        if(x%26!=0)
            a.push_back(x%26);
        else
        {
            a.push_back(26);
            x-=26;
        }
        x/=26;
    }
    for(auto it=a.rbegin();it!=a.rend();it++)
        ANS=ANS+(char)(*it+'A'-1);
    return ANS;
}
string input;
bool judge(void)//if the form is like R23C55 return true,else return false
{
    if(input[0]!='R')
        return false;
    bool there_is_digit=false;
    for(int i=1;i<input.length();i++)
    {
        if(isdigit(input[i]))
            there_is_digit=true;
        if(input[i]=='C' && there_is_digit)
            return true;
    }
    return false;
}
void get_num_from_string(int& x,int& y)
{
    int pos;
    for(int i=0;i<input.length();i++)
        if(input[i]=='C')
        {
            pos=i;
            break;
        }
    x=stoi(string(input,1,pos-1));
    y=stoi(string(input,pos+1,input.length()-pos-1));
}
string get_string_from_string(int& x)
{
    string temp;
    int i;
    for(i=0;i<input.length();i++)
        if(isdigit(input[i]))
        {
             temp= string(input,0,i);
             break;
        }
    x=stoi(string(input,i,input.length()-i));
    return temp;

}    
int main(void)
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int row,col;
        cin>>input;
        if(judge())
        {
            get_num_from_string(row,col);
            cout<<int2char(col)<<row<<endl;
        }
        else
        {
            string COL=get_string_from_string(row);
            col=char2int(COL);
            cout<<'R'<<row<<'C'<<col<<endl;
        }
    }
    return 0;
}

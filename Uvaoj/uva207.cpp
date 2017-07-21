#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<sstream>
#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
const double eps=1e-8;
double total,percentage[71];
bool rank_has_t[150];

int n,num_make_the_cut;
class Player
{
public:
    string name;
    int rd[6]={-1,-1,-1,-1,-1,-1},total=-6,total_12=-6,rank=-1,rank_money=-1;
    bool is_amateur;
    double money;
    
    string output_rank(void)
	{
        for(int i=1;i<=4;i++)
            if(rd[i]==-1)
                return "";//This is man is DQ and has no rank
		stringstream ss;
		ss<<rank;
		if(rank_has_t[rank] && rank_money!=-1)
		ss<<'T';//Only those who earn money could got a 'T'
		return ss.str();
	}
    friend istream& operator >>(istream& in,Player& X)
    {
        string input,input_score;
        getline(in,input);
        X.name=string(input,0,20);
        X.is_amateur=false;
        int id=19;
        while(X.name[id]==' ')
            id--;
        if(X.name[id]=='*')
            X.is_amateur=true;
        string score(input,20,12);
        stringstream ss(score);
        int cnt=1;
        while(ss>>input_score)
        {
            if(input_score[0]=='D')
                break;
            else
            {
                X.rd[cnt]=stoi(input_score);
                cnt++;
            }
        }
        if(cnt!=5)
            for(;cnt<5;cnt++)
                X.rd[cnt]=-1;
        //This part can not be deleted for the sake of we use cin 
        X.total_12=X.rd[1]+X.rd[2];
        X.total=X.total_12+X.rd[3]+X.rd[4];
        return in;
    }
};
Player P[150];
void readin(void)
{
    cin>>total;
    for(int i=1;i<=70;i++)
        cin>>percentage[i];
    cin>>n;
    scanf("\n");
    Player temp;
    for(int i=1;i<=n;i++)
    {
        cin>>temp;
        P[i]=temp;
    }
        

}
bool  cmp_first_2_round(Player X,Player Y)
{
    bool X_isdisqualified=false,Y_isdisqualified=false;
    for(int i=1;i<=2;i++)
    {
        if(X.rd[i]==-1)
            X_isdisqualified=true;
        if(Y.rd[i]==-1)
            Y_isdisqualified=true;
    }
    if(X_isdisqualified && Y_isdisqualified)
        return false;
    if(X_isdisqualified)
        return false;
    if(Y_isdisqualified)
        return true;
    int X_rd=X.total_12,Y_rd=Y.total_12;//if both X and Y is not disqualified,then
    //calculate their sum score of round1 and round2
    return X_rd < Y_rd;
}

bool cmp_last_2_round(Player X,Player Y)
{
    int X_round=0,Y_round=0;
       for(int i=1;i<=4;i++)
    {
        if(X.rd[i]!=-1)
            X_round++;
        if(Y.rd[i]!=-1)
            Y_round++;
    }
    if(X_round!=Y_round)
       return X_round>Y_round;
    //If the program runs to this part,then X_round==Y_round
    //let us suppose X_round==Y_round!=4,there exists some lesson
    //whose grade is -1,but that does not affect our program
    if(X.total!=Y.total)
        return X.total<Y.total;
    //sort by alphabetic order(name)
    return X.name<Y.name;
}

double calc_money(int i,int j,int cnt)//if rank_money is from i to j(the same total score)
{
    double total_percent=0;
    for(int k=i;k<=j;k++)
        total_percent+=percentage[k];
    total_percent/=cnt;
    return (total*total_percent)/100.0+eps;
}

void output(void)
{
    printf("Player Name          Place     RD1  RD2  RD3  RD4  TOTAL     Money Won\n");
	printf("-----------------------------------------------------------------------\n");
	for(int i=1;i<=num_make_the_cut;i++)
    {
		bool flag=true;
    	printf("%-21s%-10s",P[i].name.c_str(),P[i].output_rank().c_str()); 
		for(int j=1;j<=4;j++)	
		{
			if(P[i].rd[j]==-1)//DQ
				flag=false;
			if(flag)
				printf("%-5d",P[i].rd[j]);
			else
				printf("     ");
		}
		if(!flag)
			printf("DQ");
		else
        {
            if(P[i].rank_money!=-1)
                printf("%-10d",P[i].total);
            else
                printf("%d",P[i].total);//here,used to be -3d
        }
        if(P[i].rank_money==-1)
            printf("\n");
        else 
			printf("$%9.2lf\n",P[i].money);


    }
}
int main(void)
{
    int T;
    cin>>T;
    while(T--)
    {
        memset(rank_has_t,0,sizeof(rank_has_t));
        readin();
        sort(P+1,P+1+n,cmp_first_2_round);
        num_make_the_cut=0;
        while( num_make_the_cut<n && num_make_the_cut<=70)
        {
            int id=num_make_the_cut+1;
            if( (P[id].rd[1]!=-1) && (P[id].rd[2]!=-1) )
                num_make_the_cut++;
            else
                break;
        }
        if(num_make_the_cut>70 && n>70)//the loop exits because num_make_the_cut>70
        {
			num_make_the_cut=70;
            while( num_make_the_cut<n && P[num_make_the_cut+1].total_12==P[70].total_12 )
        	{
           		int id=num_make_the_cut+1;
            	if( (P[id].rd[1]!=-1) && (P[id].rd[2]!=-1) )
               		num_make_the_cut++;
            	else
                	break;
        	}
		}

                
        sort(P+1,P+num_make_the_cut+1,cmp_last_2_round);
        int rank=2,rank_money=2;
        P[1].rank=1;
        if(P[1].rd[3]!=-1 && P[1].rd[4]!=-1 && !P[1].is_amateur)
            P[1].rank_money=1;
        else
        {
            P[1].rank_money=-1;
            rank_money--;
        }
        int id_rank_money_70=-1;//This is the id of people whose rank_money is 70
        for(int i=2;i<=num_make_the_cut;i++,rank++)//calculate the rank
        {
            if(P[i].total==P[i-1].total)
                P[i].rank=P[i-1].rank;
            else
                P[i].rank=rank;
            if(!P[i].is_amateur &&(P[i].rd[3]!=-1) &&(P[i].rd[4]!=-1)&& rank_money<=70 )//here ,I delete the setence rank_money<=70
            {
                P[i].rank_money=rank_money;
                if(rank_money==70)
                    id_rank_money_70=i;
                rank_money++;
            }
            else
                P[i].rank_money=-1;
                
        }
        if(id_rank_money_70!=-1)
        {
            for(int i=id_rank_money_70;(i<=num_make_the_cut)&&(P[i].rank==P[id_rank_money_70].rank);i++)
                if(!P[i].is_amateur)
                    P[i].rank_money=70;
        }
        int cnt=0,id=1,offset=0,rank_money_min,rank_money_max;//number of the same rank
        while(id<=num_make_the_cut)
        {
            cnt=offset=0;//cnt is the number of players who got the money
            rank_money_min=500;
            rank_money_max=-100;
            while(id+offset<=num_make_the_cut && P[id+offset].rank==P[id].rank)
            {
                if(P[id+offset].rank_money!=-1)//
                {
                    cnt++;
                    rank_money_min=min(rank_money_min,P[id+offset].rank_money);
                    rank_money_max=max(rank_money_max,P[id+offset].rank_money);
                } 
                offset++;
            }
            for(int i=id;i<id+offset;i++)
            {
                if(P[i].rank_money!=-1)
                    P[i].money=calc_money(rank_money_min,rank_money_max,cnt);
                else
                    P[i].money=-1;
            }
            if(cnt>1)
                rank_has_t[ P[id].rank ]=true;
            id+=offset;
            
        }
        output();

        
            
         
        if(T)
            printf("\n");
    }
    return 0;
}

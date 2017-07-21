#include<stdio.h>
#include<string.h>
#include<math.h>
#include<limits.h>
#include<vector>
#include<set>
#include<ctype.h>
#include<algorithm>
using namespace std;
struct TreeNode
{
	int key;//frep纪录此值出现的次数
	int lson,rson;
};
const int maxn=100000+10;
TreeNode tree[maxn];
int A[maxn];
int root=1,n,m,x,tot;//root为1 空结点用0表示
//插入操作
void insert(int k,int x)
{
	//插入为左儿子
	if((x<tree[k].key)&&(tree[k].lson==0)){
		tot++;
		tree[k].lson=tot;
		tree[tot].key=x;
		printf("%d ",tree[k].key);
		return;
	}

	//插入为右儿子
	if((x>tree[k].key)&&(tree[k].rson==0)){
		tot++;
		tree[k].rson=tot;
		tree[tot].key=x;
		printf("%d ",tree[k].key);
		return;
	}

	if(x<tree[k].key)insert(tree[k].lson,x);
	else insert(tree[k].rson,x);
}
int main(void)
{

    scanf("%d",&n);
    for(int i=0;i<=n;i++)
    {

        tree[i].lson=tree[i].rson=0;
    }
    tot=1;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
        if(i==0)
        {
            tree[1].key=A[i];
        }
        else
        {
            insert(1,A[i]);
        }
    }
    return 0;
}


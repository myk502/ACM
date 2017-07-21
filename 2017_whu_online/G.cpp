#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int n;
int a[maxn];
long long cnt;
int A[maxn],B[maxn];
void merge(int i,int x,int j)
{
    int length_a=x-i,length_b=j-x;
    for(int k=0;k<length_a;k++)
        A[k]=a[i+k];
    for(int k=0;k<length_b;k++)
        B[k]=a[x+k];
    A[length_a]=B[length_b]=INT_MAX;
    int ii=0,jj=0;
    while((ii<length_a)||(jj<length_b))
    {
        if(A[ii]<=B[jj])
        {
             a[i+ii+jj]=A[ii];
             ii++;
        }
        else
        {
            a[ii+jj+i]=B[jj];
            //printf("We are now merging(%d,%d,%d),A[%d]=%d,B[%d]=%d\n",i,x,j,ii,A[ii],jj,B[jj]);
            jj++;
            if(A[ii]!=INT_MAX)
            cnt+=length_a-ii;
        }
    }

}
void mergeSort(int i,int j)
{
    int mid=(i+j)/2;
    if(j-i==1)//平凡情况，只有一个数
        return ;
    mergeSort(i,mid);
    mergeSort(mid,j);
    merge(i,mid,j);
}

int main(void)
{
    cin>>n;
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    cnt=0;
    mergeSort(0,n);
    cout<<cnt;
    return 0;
}

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(void)
{
    int *ptr=NULL;
    ptr=(int *)malloc(sizeof(int)*5);
    ptr[2]=6;
    printf("%d\n",ptr[2]);
    free(ptr);
    ptr=NULL;
    return 0;
}



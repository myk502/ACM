#include <stdio.h>
#define MAXLEN 80
#define MAXLINE 200
char buffer[MAXLEN],fname[120];
char *lineptr[MAXLINE];
FILE *fp;
void edit(),replace(),insert(),delete(),quit();
char comch[]="EeRrIiDdQq";/*�����*/
void(*comfun[])()={edit,replace,insert,delete,quit};/*��Ӧ��������*/
int modified=0,/*���ı��޸ı�־*/
    last;/*��ǰ��������*/
char *chpt;/*�����������ַ�ָ��*/

main()
{
    int j;

    last=0;
    while(1)
    {
        printf("\nInput a command:[e,r,i,d,q].\n");
        gets(buffer);/*����������*/
        for(chpt=buffer;*chpt=='\0'||*chpt=='\t';chpt++);/*�ӹ��հ׷�*/
        if(*chpt=='\0') continue;/*������������*/
        for(j=0;comch[j]!='\0'&&comch[j]!=*chpt;j++);/*�������*/
        if(comch[j]=='\0') continue;/*�Ƿ������*/
        chpt++;/*�ӹ��������ָ�����*/
        (*comfun[j/2])();/*ִ�ж�Ӧ����*/
        fprintf(stdout,"The text is:\n");
        for(j=0;j<last;j++)/*��ʾ����*/
            fputs(lineptr[j],stdout);
    }
}
void quit()
{
    int c;
    if(modified)/* �����ı��޸� */
    {
        printf("Save? (y/n)");
        while(!(((c=getchar())>='a'&&c<='z')||(c>='A'&&c<='Z')));
        if(c=='y'||c=='Y')
            save(fname); /* ���汻�޸Ĺ������� */
    }
    for(c=0;c<last;c++)
        free(lineptr[c]);   /* �ͷ��ڴ� */
    exit(0);
}

void insert()
{
    int k,m,i;
    sscanf(chpt,"%d%d",&k,&m);  /* ������� */
    if(m<0||m>last||last+k>=MAXLINE)/* ������������ */
    {
        printf("Error!\n");
        return;
    }
    for(i=last;i>m;i--)/* ���������� */
        lineptr[i+k-1]=lineptr[i-1];
    for(i=0;i<k;i++)   /* ����k�����ģ������� */
    {
        fgets(buffer,MAXLEN,stdin);
        lineptr[m+i]=(char *)malloc(strlen(buffer)+1);
        strcpy(lineptr[m+i],buffer);
    }
    last+=k;    /* ������������ */
    modified=1; /* ���ı��޸� */
}

void delete()
{
    int i,j,m,n;
    sscanf(chpt,"%d%d",&m,&n);  /* ������� */
    if(m<=0||m>last||n<m)   /* ������������ */
    {
        printf("Error!\n");
        return;
    }
    if(n>last)
        n=last;     /* �������� */
    for(i=m;i<=n;i++)   /* ɾ������ */
        free(lineptr[i-1]);
    for(i=m,j=n+1;j<=last;i++,j++)
        lineptr[i-1]=lineptr[j-1];
    last=i-1;   /* ������������ */
    modified=1; /* ���ı��޸� */
}

void replace()
{
    int k,m,n,i,j;
    sscanf(chpt,"%d%d%d",&k,&m,&n); /* ������� */
    if(m<=0||m>last||n<m||last-(n-m+1)+k>=MAXLINE)/* ������������ */
    {
        printf("Error!\n");
        return;
    }
    /* �����ɾ�� */
    if(n>last)
        n=last;     /* �������� */
    for(i=m;i<=n;i++)   /* ɾ������ */
        free(lineptr[i-1]);
    for(i=m,j=n+1;j<=last;i++,j++)
        lineptr[i-1]=lineptr[j-1];
    last=i-1;
    /* ������ɲ��� */
    for(i=last;i>=m;i--)
        lineptr[i+k-1]=lineptr[i-1];
    for(i=0;i<k;i++)
    {
        fgets(buffer,MAXLEN,stdin);
        lineptr[m+i-1]=(char *)malloc(strlen(buffer)+1);
        strcpy(lineptr[m+i-1],buffer);
    }
    last+=k;    /* ������������ */
    modified=1; /* ���ı��޸� */
}

save(char *fname)   /* �����ļ� */
{
    int i;
    FILE *fp;
    if((fp=fopen(fname,"w"))==NULL)
    {
        fprintf(stderr,"Can't open %s.\n",fname);
        exit(1);
    }
    for(i=0;i<last;i++)
    {
        fputs(lineptr[i],fp);
        free(lineptr[i]);
    }
    fclose(fp);
}

void edit() /* �༭���� */
{
    int i;
    FILE *fp;
    i=sscanf(chpt,"%s",fname);  /* �����ļ��� */
    if(i!=1)
    {
        printf("Enter file name.\n");
        scanf("%s",fname);
    }
    if((fp=fopen(fname,"r"))==NULL) /* ���� */
    {
        fp=fopen(fname,"w");    /* �粻���ڣ��򴴽��ļ� */
        fclose(fp);
        fp=fopen(fname,"r");    /* ���¶��� */
    }
    i=0;
    while(fgets(buffer,MAXLEN,fp)==buffer)
    {
        lineptr[i]=(char *)malloc(strlen(buffer)+1);
        strcpy(lineptr[i++],buffer);
    }
    fclose(fp);
    last=i;
}
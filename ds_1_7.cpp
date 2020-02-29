#include<stdio.h>
#include<stdlib.h>
void show(int,int[]);
void show2(int[],int);
int main()
{
	int i,j,k,s=0,p,n,l[10],r[10];
	printf("Enter a 4 digit prime number:");
	scanf("%d",&n);
	for(i=0;i<10;i++)
	{
		j=n*(rand()%100+1)+i;
		printf("%d %d\n",i+1,j);
		l[i]=j;
	}
	int x[7];
	for(i=0;i<7;i++)
	{
		show(x[i],l);
	}
}
void show(int n,int l[])
{
	printf("for %d\n",n);
	int i;
	for(i=0;i<10;i++)
	{
		printf("%d %d\n",l[i],l[i]%n);
	}
}


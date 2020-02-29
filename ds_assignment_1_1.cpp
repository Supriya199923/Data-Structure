#include<stdio.h>
long int ite(int);
long int rec(int);
int main()
{
	int n,x;
	long int r;
	printf("\nEnter the number:");
	scanf("%d",&n);
	printf("\nFor iteration press 1 for recursion press 2:");
	scanf("%d",&x);
	if(x==1)
	{
		r=ite(n);
		printf("\nResult= %d",r);
	}
	else if(x==2)
	{
		r=rec(n);
		printf("\nResult= %d",r);
	}
}
long int ite(int n)
{
	long int i,p=1;
	for(i=1;i<=n;i++)
	{
		p=p*i;
	}
	return p;
}
long int rec(int n)
{
	if(n==1 || n==0)
	{
		return 1;
	}
	return(n*rec(n-1));
}

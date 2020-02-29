#include<stdio.h>
long int ite(int);
long int rec(int);
int main()
{
	int n,x;
	long int r;
	printf("\nEnter the number:");
	scanf("%d",&n);
	printf("\nFor ite press 1 for rec press 2:");
	scanf("%d",&x);
	if(x==1)
	{
		r=ite(n);
		printf("\nResult=%d",r);
	}
	else if(x==2)
	{
		r=rec(n);
		printf("\nResult=%d",r);
	}
}
long int ite(int n)
{
	long int a=0,b=1,i,c;
	if(n==0)
	return 0;
	else if(n==1)
	{
		return 1;
	}
	else
	{
		for(i=2;i<=n;i++)
		{
			c=a+b;
			a=b;
			b=c;
		}
		return c;
	}
}
long int rec(int n)
{
	if(n==0)
	return 0;
	else if(n==1)
	return 1;
	else
	return(rec(n-1)+rec(n-2));
}

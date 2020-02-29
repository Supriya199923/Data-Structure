#include<stdio.h>
int ls(int[],int,int);
int bs(int[],int,int);
int main()
{
	int p,q,i,j,n,x;
	printf("\nEnter the size of array:");
	scanf("%d",&n);
	int a[n];
	printf("\nEnter the numbers in ascending order:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("\nEnter the number to find:");
	scanf("%d",&x);
	printf("\nFor linear search press 1 for binery search press 2:");
	scanf("%d",&p);
	if(p==1)
	{
		ls(a,x,n);
	}
	else if(p==2)
	{
		bs(a,x,n);
	}
}	
int ls(int a[],int x,int n)
{
	int i,j,p=0;
	for(i=0;i<n;i++)
	{
		if(a[i]==x)
		{
			p=1;
			break;
		}
	}
	if(p==1)
	{
		printf("\nfound.");
	}
	else
	{
		printf("\nnot found.");
	}
}
int bs(int a[],int x,int n)
{
	int i,j,k,p=0,beg,mid,last;
	beg=0;
	last=n-1;
	while(beg<=last)
	{
		mid=(beg+last)/2;
		if(a[mid]==x)
		{
			p=1;
			break;
		}
		else if(a[mid]<x)
		{
			beg=mid+1;
			last=last;
		}
		else if(a[mid]>x)
		{
			beg=beg;
			last=mid-1;
		}
	}
	if(p==1)
	printf("\nfound.");
	else
	printf("\nNot found.");
}

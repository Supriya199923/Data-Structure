#include<stdio.h>
#include<conio.h>
int main()
{
	int a[30],i,n,size;                               //error
	printf("\nEnter the size:");
	scanf("%d",&size);
	printf("Enter the array elements:");
	for(i=0;i<size;i++)
	{
		scanf("%d",&n);
	}
	if(a[0]<a[1])
	{
		for(i=1;i<size-1;i++)
		{
			if(a[i]>a[i+1])
			{
				printf("\nThe array is not sorted.1");
				return 0;
			}
		}
		printf("\nThe array is sorted in ascending order.1");
	}
	else if(a[0]>a[1])
	{
		for(i=1;i<size-1;i++)
		{
			if(a[i]<a[i+1])
			{
				printf("\nThe array is not sorted.2");
				break;
			}
		}
		printf("\nThe array is sorted in descending order.2");
	}
	return 0;
}

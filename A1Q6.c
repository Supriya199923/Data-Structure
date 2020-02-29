#include<stdio.h>
#include<conio.h>
#include<string.h>
void main()
{
	int i,j,k,n,r,m=0,x=10;
	char str[10],arr[10],pp[10],temp[10];
	FILE *fp1,*fp2;
	fp1=fopen("data.txt","w");
    printf("enter the no of students:");
	scanf("%d",&n);
	char he[n][10];
	int lon,sor;
	printf("enter the roll and name respectively:");
		for(i=0;i<n;i++)
	{
		scanf("%d",&r);
		scanf("%s",str);
		strcpy(he[i],str);
		fprintf(fp1,"%d   %s\n",r,str);
		lon=strlen(str);
		sor=strlen(str);
		
		if(lon>=m)
		{m=lon;
		strcpy(arr,str);
		}
		if(sor<=x)
		{
			x=sor;
			strcpy(pp,str);
		}
		
	}
	printf("shortest will be %s  \n",pp);
	printf("longest will be %s  ",arr);
	fclose(fp1);
	fp2=fopen("data1.txt","w");
	for(i=0;i<(n-1);i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(strcmp(he[i],he[j])>0)
			{strcpy(temp,he[i]);
			strcpy(he[i],he[j]);
			strcpy(str[j],temp);
			}
		}
	}
	for(i=0;i<n;i++)
	{
		fprintf(fp2,"%s\n",he[i]);
	}
	
}

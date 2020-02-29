#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  char nume[18];
  char name[20];
  char surname[20];
  char fullname[40]={"\0"};

  printf("Enter the name in NAME SURNAME format ::\n");
  scanf("%s %s",name,surname);

  strcpy(fullname,name);
  strcat(fullname,surname);

  int num=0,i,j;
  for(i=0,j=0;i<18,j<strlen(fullname);j++)
  {
    num=fullname[j];
    while(num!=0&&i<18){
      nume[i]=num%10+'0';
      num=num/10;
      i++;
    }
  }

  /*for(i=0;i<18;i++)
    if(nume[i]<'0')
      nume[i]='0';*/
  long long int number1=0;
  long long int number2=0;
  for(i=0;i<(strlen(nume)/2);i++)
  {
    number1 += nume[i]-'0';
    number2 += nume[i+(strlen(nume)/2)]-'0';
    number1*=10;
    number2*=10;
  }



  printf("nume = %s\n",nume);
  printf("num_add = %lld\n",(number1+number2)/10 );
  printf("num_rem = %lld\n",((number1+number2)/10)%1009);
}

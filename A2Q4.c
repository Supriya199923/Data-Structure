#include<stdio.h>
#include<stdlib.h>
#include "set.h"

int main() {
	struct SET *set;
	char ch;
	int x , old , new;
	init(&set);
	printf("\tMENU : \n");
	printf("1. Insert element\n2. Remove element\n3. Modify set\n4. Find size of set\n5. Print set\n\n");
	do {
		int option;
		printf("Choose any option : ");
		scanf("%d" , &option);
		switch(option) {
			case 1:
				printf("\nEnter the element to be inserted : ");
				scanf("%d" , &x);
				insert(&set , x);
				break;
			case 2:
				printf("\nEnter the element to be removed : ");
				scanf("%d" , &x);
				_remove(&set , x);
				break;
			case 3:
				printf("\nEnter the number to be replaced and the number with which it is to be replaced : \n");
				scanf("%d %d" , &old , &new);
				modify(&set , old , new);
				break;
			case 4:
				printf("The size of the set is : %d\n" , size(set));
				break;
			case 5: 
				printset(set);
				break;
		}
		printf("Do you wish to continue : ");
		getchar();
		scanf("%c" , &ch);
	}while(ch == 'y' || ch == 'Y');

	return 0;
}

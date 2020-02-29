#include<stdio.h>
#include<stdlib.h> 
#include "cstring.h"

int main() {
    int maxmlen , option , len , index , l , r;
    struct String *str;
    char choice , *s;
    printf("Enter the maximum length of string : ");
    scanf("%d" , &maxmlen);
    init(&str , maxmlen);
    printf("Menu:\n\n1. Insert new string\n2. Join two strings(2nd to 1st)\n3. Get character at index\n4. Erase character at index\n5. Get substring(l to r)\n6. Show String.\n\n");
    do {
        printf("Enter any option : ");
        scanf("%d" , &option);
        switch(option) {
            case 1:
                printf("Enter maxm length of input string(<= 999999) : ");
                scanf("%d" , &len);
                s = (char *)malloc((len+1)*sizeof(char));
                printf("Enter the string : \n");
                getchar();
                scanf("%[^\n]s" , s);
                getchar();
                insert(s , &str);
                free(s);
                break;
            case 2:
                printf("Enter maxm length of input string(<= 999999) : ");
                scanf("%d" , &len);
                s = (char *)malloc((len+1)*sizeof(char));
                printf("Enter the string : \n");
                getchar();
                scanf("%[^\n]s" , s);
                getchar();
                join(&str , s);
                free(s);
                break;
            case 3:
                printf("Enter the index for character retrieval (<= 999999): ");
                scanf("%d" , &index);
                printf("Charcter at index %d is : %c\n" , index , at(index , str));
                getchar();
                break;
            case 4:
                printf("Enter the index for character erase (<= 999999): ");
                scanf("%d" , &index);
                getchar();
                eraseAt(index , &str);
                break;
            case 5:
                printf("Enter the range (l to r) for substring(l <= r && r <= 999999) : ");
                scanf("%d %d" , &l , &r);
                substr(l , r , str , &s);
                printf("The Substring is : \n");
                for(int i = 0; s[i]; i++) printf("%c" , s[i]);
                printf("\n");
                getchar();
                free(s);
                break;
            case 6:
                printf("The string is : \n");
                showString(str);
                getchar();
                break;
            default:
                printf("Enter valid option and try again.\n");
                getchar();
                break;
        }
        printf("Do you wish to try again (Y/N) : ");
        scanf("%c" , &choice);
    }while(choice == 'y' || choice == 'Y');
    
    destruct(&str);

    return 0;
}

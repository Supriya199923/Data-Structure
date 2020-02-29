#include <stdio.h>

#define IS_EQUAL 0
#define IS_GREATER 2
#define IS_LESSER 1

#define ARR_SIZE 10

int determine_order(int *arr){
    int is_in_order = IS_EQUAL,i;
    for(i=1; i<ARR_SIZE; i++)
	{
        if(arr[i] == arr[i-1])
            is_in_order = is_in_order|IS_EQUAL;
        else if(arr[i] > arr[i-1])
            is_in_order = is_in_order|IS_GREATER;
        else is_in_order = is_in_order|IS_LESSER;
    }

    return is_in_order;
}

int main(){
    int arr[ARR_SIZE] = {0},i;

    printf("Enter %d elements for your array :: \n",ARR_SIZE);
    for(i=0; i<ARR_SIZE; i++)
        scanf("%d",&arr[i]);

    int res = determine_order(arr);

    if(res == IS_EQUAL) printf("All equal\n");
    else if(res == IS_GREATER) printf("Is Increasing\n");
    else if(res == IS_LESSER)  printf("Is Decreasing\n");
    else printf("No order as such\n");

    return 0;
}

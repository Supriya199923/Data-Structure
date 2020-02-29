#include <stdio.h>

#define SIZE_ARR1 10
#define SIZE_ARR2 10
#define SIZE_MARR 20

void merge(int* marr, int* arr1, int* arr2){
    int in_arr1 = 0;
    int in_arr2 = 0;
	int i;
    for(i=0; i<SIZE_MARR; i++){
        if(in_arr1 == SIZE_ARR1){
            marr[i] = arr2[in_arr2];
            in_arr2 += 1;
        }
        else if(in_arr1 == SIZE_ARR2){
            marr[i] = arr1[in_arr1];
            in_arr1 += 1;
        }
        else if(arr1[in_arr1] < arr2[in_arr2]){
            marr[i] = arr1[in_arr1];
            in_arr1 += 1;
        }
        else{
            marr[i] = arr2[in_arr2];
            in_arr2 += 1;
        }
    }
    return;
}

int main(){
    int arr1[SIZE_ARR1] = {0};
    int arr2[SIZE_ARR2] = {0};
	int i;
    printf("Enter %d elements for 1st array :: \n", SIZE_ARR1);
    for(i=0;i<SIZE_ARR1; i++)
        scanf("%d",&arr1[i]);

    printf("Enter %d elements for 2nd array :: \n", SIZE_ARR2);
    for(i=0;i<SIZE_ARR2; i++)
        scanf("%d",&arr2[i]);

    int marr[SIZE_MARR] = {0};
    printf("Here's the merged array :: \n");
    merge(marr,arr1,arr2);

    for(i=0; i<SIZE_MARR; i++)
        printf("%d  ",marr[i]);

    printf("\n");
    return 0;
}

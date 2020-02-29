#include <stdio.h>

#define MAX_ELEMS 10
#define SLIDER_MAX 5

typedef struct out_char{
    float average;
    int max;
    int min;
    int median;
} out;

typedef struct slider_tag{
    int val;
    int index;
}slider_elem;

void add_remove(slider_elem slider[SLIDER_MAX],slider_elem add_elem, int rmv_index){
    int i,j;
    for(i=0 ;i<SLIDER_MAX; i++)
        if(slider[i].index == rmv_index){
            slider[i].index = add_elem.index;
            slider[i].val = add_elem.val;
            break;
        }

    for(i=0; i<SLIDER_MAX; i++)
        for(j = i+1; j<SLIDER_MAX; j++){
            if(slider[i].val > slider[j].val){
                slider_elem temp;
                temp = slider[i];
                slider[i] = slider[j];
                slider[j] = temp;
            }
        }
        return;
}

void slider_mmma(int input[MAX_ELEMS], out output[MAX_ELEMS - SLIDER_MAX+1]){
	int i;
    slider_elem slider[SLIDER_MAX];
    for(i=0; i<SLIDER_MAX; i++){
        slider[i].index = 0;
        slider[i].val = input[0];
    }

    int average = 0;
    for(i=0; i<MAX_ELEMS; i++){
        slider_elem S;
        S.val = input[i];
        S.index = i;
        if(i<SLIDER_MAX-1){
                add_remove(slider,S,0);
                average += input[i];
            }
        else{
            if(i == SLIDER_MAX-1){
                add_remove(slider,S,0);
                average += input[i];
            }
            else{
                 add_remove(slider,S,i-SLIDER_MAX);
                 average = average - input[i-SLIDER_MAX] + input[i];
             }

            output[i-SLIDER_MAX+1].min = slider[0].val;
            output[i-SLIDER_MAX+1].max = slider[SLIDER_MAX-1].val;
            output[i-SLIDER_MAX+1].median = slider[(SLIDER_MAX-1)/2].val;
            output[i-SLIDER_MAX+1].average = average/(SLIDER_MAX + 0.0);
        }
    }
    return;
}

int main(){
    int input[MAX_ELEMS] = {0},i;
    printf("Enter %d elements below :: \n",MAX_ELEMS);

    for(i=0; i<MAX_ELEMS; i++)
        scanf("%d",&input[i]);

    out output[MAX_ELEMS-SLIDER_MAX+1];

    slider_mmma(input,output);

    for(i=0; i<MAX_ELEMS-SLIDER_MAX+1; i++)
        printf("Max = %d\t Min = %d\t Median = %d\t Average = %f\n",output[i].max, output[i].min, output[i].median, output[i].average);

    return 0;
}

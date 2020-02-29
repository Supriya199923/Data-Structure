#include "2_1.h"

int main()
{
    struct Polynomial p1, p2;
    p1 = create();
    p2 = create();

    int num_terms = 0;
    float coeff = 0;
    int index = 0;

    printf("Enter the number of terms for input :: ");
    scanf("%d",&num_terms);


    while(num_terms--){
        printf("coeff = ");
        scanf("%f", &coeff);
        printf("index = ");
        scanf("%d", &index);
        printf("\n");
        add_term(&p1,coeff,index);
    }

    printf("Enter the number of terms for input :: ");
    scanf("%d",&num_terms);
    while(num_terms--){
        printf("coeff = ");
        scanf("%f", &coeff);
        printf("index = ");
        scanf("%d", &index);
        printf("\n");
        add_term(&p2,coeff,index);
    }

    struct Polynomial p;
    p = mul(p1,p2);

    print_polynomial(p);

    return 0;
}

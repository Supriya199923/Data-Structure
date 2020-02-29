#include <stdio.h>
#include <stdlib.h>

#define SENTINEL_INDEX -1
#define MAX_TERMS      20
/*coeff -> 0 if the term does not exist
  index -> can be anything you want*/

struct term{
    float coeff;
    int index;
};

/*num_term   -> number of terms to be included
                in a Polynomial
  last_index -> index from where space is free
  terms      -> array containing the Polynomial terms */

struct Polynomial{
  int num_term;
  struct term terms[2*MAX_TERMS];
};

/*create -> Create a Polynomial with the desired number of terms,
            Also, initialize all the terms to 0*/

struct Polynomial create()
{
  struct Polynomial p;
  int i;
  p.num_term = 0;
  for(i=0;i<2*MAX_TERMS;i++){
    p.terms[i].index = SENTINEL_INDEX;
    p.terms[i].coeff = 0.0;
  }
  return p;
}

void print_polynomial(struct Polynomial p)
{
	int i;
    if(p.num_term == 0) printf("0");

    for(i=0;i<p.num_term;i++){
        if(p.terms[i].index!=0)
            printf("%fx^(%d)",p.terms[i].coeff,p.terms[i].index);
        else printf("%f",p.terms[i].coeff);
        if(i != p.num_term-1) printf(" + ");
    }
    printf("\n");

    return;
}

int add_term(struct Polynomial* p,float coeff, int index)
{
  if(p->num_term < MAX_TERMS && index>SENTINEL_INDEX){
    (p->terms)[p->num_term].coeff = coeff;
    (p->terms)[p->num_term].index = index;
    p->num_term++;
    return 1;
  }
  else return 0;
}

void sort_polynomial(struct Polynomial* p)
{
	int i,j;
  for(i=0;i<(p->num_term);i++){
    for(j=i+1;j<p->num_term;j++){
      if((p->terms[i]).index < (p->terms[j]).index){
        struct term t;
        t = p->terms[i];
        p->terms[i] = p->terms[j];
        p->terms[j] = t;
      }
    }
  }
  return;
}

struct Polynomial cmult(struct Polynomial p, float c)
{
	int i;
    if(c == 0) p.num_term = 0;
    for(i=0;i<p.num_term;i++)
        p.terms[i].coeff = p.terms[i].coeff * c;

    return p;
}

void merge_terms(struct Polynomial *p)
{
	int i;
    sort_polynomial(p);
    int term_dec = 0;
    for(i=0; i<(p->num_term-1); i++){
      if((p->terms[i]).index == (p->terms)[i+1].index){
        (p->terms)[i+1].coeff += (p->terms)[i].coeff;
        (p->terms[i]).index = SENTINEL_INDEX;
        term_dec++;
      }
    }
    sort_polynomial(p);
    p->num_term = p->num_term - term_dec;
    return ;
}

struct Polynomial add(struct Polynomial P1, struct Polynomial P2)
{
	int i,j;
    struct Polynomial p;
    p = create();

    sort_polynomial(&P1);
    sort_polynomial(&P2);

    int visit_P1[MAX_TERMS] = {0};
    int visit_P2[MAX_TERMS] = {0};

    for(i=0;i<P1.num_term;i++){
        for(j=0; j<P2.num_term; j++){
            if(P1.terms[i].index == P2.terms[j].index){
                visit_P1[i] = 1;
                visit_P2[j] = 1;
                p.terms[p.num_term].index = P1.terms[i].index;
                p.terms[p.num_term].coeff = P1.terms[i].coeff + P2.terms[j].coeff;
                p.num_term++;

                if(p.num_term > 2*MAX_TERMS){
                    printf("Terms exceeded!Abort!!\n");
                    exit(1);
                }
            }
        }
    }

    merge_terms(&p);
    
    //Terms which couldn't be added
    for(i=0;i<P1.num_term;i++){
        if(visit_P1[i] == 0){
            p.terms[p.num_term].index = P1.terms[i].index;
            p.terms[p.num_term].coeff = P1.terms[i].coeff;
            p.num_term++;

            if(p.num_term > 2*MAX_TERMS){
                printf("Terms exceeded!Abort!!\n");
                exit(1);
            }
        }
    }

    for(i=0;i<P2.num_term;i++){
        if(visit_P2[i] == 0){
            p.terms[p.num_term].index = P2.terms[i].index;
            p.terms[p.num_term].coeff = P2.terms[i].coeff;
            p.num_term++;

            if(p.num_term > 2*MAX_TERMS){
                printf("Terms exceeded!Abort!!\n");
                exit(1);
            }
        }
    }

    if(p.num_term>MAX_TERMS){
        printf("Terms exceeded! Abort!!\n");
        exit(1);
    }

    return p;
}

struct Polynomial mul(struct Polynomial P1, struct Polynomial P2)
{
	int i,j;
  struct Polynomial p;
  p = create();

  for(i=0; i<P1.num_term; i++){
    for(j=0; j<P2.num_term; j++){
      p.terms[p.num_term].coeff = P1.terms[i].coeff*P2.terms[j].coeff;
      p.terms[p.num_term].index = P1.terms[i].index + P2.terms[j].index;
      p.num_term++;

      if(p.num_term > 2*MAX_TERMS){
          printf("Terms exceeded!Abort!!\n");
          exit(1);
      }
    }
  }

  merge_terms(&p);

  return p;
}

int coeff_search(struct Polynomial p, int exp)
{
    int i=0;
    if(exp == SENTINEL_INDEX){
        printf("Invalid Index!Abort!!\n");
        exit(1);
    }
    while(i != p.num_term){
        if(p.terms[i].index == exp)
            return i;
        i++;
    }
    return i;
}

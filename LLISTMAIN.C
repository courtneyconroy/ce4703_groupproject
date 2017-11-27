#include "llist.h"
#include <stdio.h>
#include <stdlib.h>
#define MAXNUM 10
int main()
      {
      struct term *p1, *p2, *sum, *diff, *product, *quotient, *normal;
      double multiplier, devisor;
      int i;

      printf("Creating polynomials\n");
      p1 = createPoly(p1);
      p2 = createPoly(p2);

      printf("Display Polynomials:\n");

      display(p1);
      display(p2);
      printf("Display sum of Polynomials\n");
      sum = addPoly(p1, p2);
      display(sum);

      printf("Display diff of Polynomials\n");
      diff = subPoly(p1, p2);
      display(diff);

      printf("Display multiply Polynomial\n");
      multiplier = rand()%MAXNUM*20;
      printf("Multiple is %lf\n", multiplier);
      product = mulPoly(p1, &multiplier);
      display(product);

	  printf("Display divsion Polynomial\n");
      devisor = rand()%MAXNUM*20;
      printf("Devisor is %lf\n", devisor);
      quotient = divPoly(p1, &devisor);
      display(quotient);

	  printf("Display order of Polynomials\n");
	  i = orderPoly(p1);
	  printf("The order of the polynomial is: %d \n",i );

	  printf("Nornalize Polynomial\n");
	  normal = normPoly(p1);
	  display(normal);

      return(0);
}

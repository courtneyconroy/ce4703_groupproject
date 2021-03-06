////////////////////////////////////////
/* 
 llist.h
 This is a header file which contains the links for simple linked list implementation.
authors: Panos Brennan, Sean Ryan Tobin, Sinead O' Dowd, Courtney Conroy
date modified: 26/11/2017
*/
////////////////////////////////////////

#include "llist.h"
#include <stdlib.h>
#include <stdio.h>
#define MAXNUM 10
struct term  *createPoly(struct term  *poly){
  int iNode;
  int numNode;

 struct term *now;

    //create a random number of nodes
  numNode= rand()%(MAXNUM);   // Add 1 because order is 1 greater than the number of coefficients
  now = (struct term *)malloc(sizeof(struct term));
  poly = now; // Don't lose the head of the list

  now->num = rand()%(MAXNUM*10)-1;
  now->ptr = NULL; // incase there are no more elements


      //create the required number of nodes
    for(iNode=1; iNode<numNode; iNode++)
       {
       now->ptr = (struct term *)malloc(sizeof(struct term ));
       now->ptr->ptr = NULL;
       now->ptr->num = rand()%(MAXNUM*10)-1;
       now = now->ptr;
       }

    return(poly);
   }
void display(struct term *head)
{
  struct term *now; // current node on linked list
    const char *pad = "";
    int i = 0;
    now = head;
    while (now != NULL)
    {
       printf("%s%.2lf x ^ %d", pad, now->num, i);// replaces temp values with real values entered by user
        now = now->ptr;
        pad = " + ";
        i++;
    }
    putchar('\n');
}
struct term *addPoly(struct term *p1, struct term *p2)
   {
   struct term *now1, *now2, *head, *sum;
   now1 = p1;
   now2 = p2;
   sum = (struct term *)malloc(sizeof(struct term));
   head = sum;

   while (now1 != NULL || now2 != NULL)
      {
      sum->ptr = (struct term *)malloc(sizeof(struct term));
      sum->ptr->ptr = NULL;
      if (now1 != NULL && now2 != NULL)
        {
        sum->num = now1->num + now2->num;
        now1 = now1->ptr;
        now2 = now2->ptr;
        }
      else
        if (now1 == NULL)
            {
            sum->num = now2->num;
            now2 = now2->ptr;
            }
         else
            {
            sum->num = now1->num;
            now1 = now1->ptr;

            }
    	 sum = sum->ptr;
      }
   return(head);
   }

struct term *subPoly(struct term *p1, struct term *p2)
   {
   struct term *now1, *now2, *head, *diff;
   now1 = p1;
   now2 = p2;
   diff = (struct term *)malloc(sizeof(struct term));
   head = diff;

   while (now1 != NULL || now2 != NULL)
      {
      diff->ptr = (struct term *)malloc(sizeof(struct term));
      diff->ptr->ptr = NULL;
      if (now1 != NULL && now2 != NULL)
        {
        diff->num = now1->num - now2->num;
        now1 = now1->ptr;
        now2 = now2->ptr;
        }
      else
        if (now1 == NULL)
            {
            diff->num = -now2->num;
            now2 = now2->ptr;
            }
         else
            {
            diff->num = now1->num;
            now1 = now1->ptr;

            }
    	 diff = diff->ptr;
      }

   return(head);
   }

struct term *mulPoly(struct term *p1, double *multiplier)
   {
   struct term *now, *head, *product;
   now = p1;
   product= (struct term *)malloc(sizeof(struct term));
   head = product;

   while (now != NULL)
      {
      product->ptr = (struct term *)malloc(sizeof(struct term));
      product->ptr->ptr = NULL;
      product->num = now->num *  (*multiplier);
      now = now->ptr;
      product = product->ptr;
      }
   return(head);
   }

struct term *divPoly(struct term *p1, double *devisor)
   {
   struct term *now, *head, *quotient;
   now = p1;
   quotient = (struct term *)malloc(sizeof(struct term));
   head = quotient;

   while (now != NULL)
      {
      quotient->ptr = (struct term *)malloc(sizeof(struct term));
      quotient->ptr->ptr = NULL;
      quotient->num = now->num /  (*devisor);
      now = now->ptr;
      quotient = quotient->ptr;
      }
   return(head);
   }

int orderPoly (struct term *p1)
	{
	struct term *now;
   now = p1;
   int i =0;
   	while (now != NULL)
		{
			now = now->ptr;
			i++;
		}
		i=i-1;
		return (i);
	}

struct term *normPoly (struct term *p1)
{
	struct term *now;
	now = p1;
	double maxValue;
	maxValue = now->num;
	while (now != NULL)
		{
		if (now->num > maxValue)
			{
			maxValue = now->num;
			}
		now = now->ptr;
		}
	now = divPoly(p1, &maxValue);
	return(now);
}

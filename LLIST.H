 ////////////////////////////////////////
/* 
 llist.h
 This is a header file which contains the links for simple linked list implementation.
authors: Panos Brennan, Sean Ryan Tobin, Sinead O' Dowd, Courtney Conroy
date modified: 26/11/2017
*/
////////////////////////////////////////


#ifndef LLIST_H
#define  LLIST_H







//define structure for polynomial to be stored
/*typedef struct
    {
      double num;
      struct poly_ll *ptr;
      }poly_ll;*/
//define structure  for data needed
 struct term
    {
        double num;
        struct term *ptr;
    };


//define functions
struct term  *createPoly(struct term  *poly);
void display(struct term *head);
struct term *addPoly(struct term *p1, struct term *p2);
struct term *subPoly(struct term *p1, struct term *p2);
struct term *mulPoly(struct term *p1, double *multiplier);
struct term *divPoly(struct term *p1, double *devisor);
int orderPoly (struct term *p1);
    

struct term *normPoly (struct term *p1);


//void deletePoly(poly_ll *term);
#endif

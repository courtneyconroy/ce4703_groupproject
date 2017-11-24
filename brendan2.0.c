#include <stdio.h>
#include <stdlib.h>
#define MAXNUM 10
 
  struct term
    {
        double num;
        struct term *ptr;
    };

//struct term *createPoly(struct term *q); // creates Linked list.

struct term *createPoly(struct term *poly){
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
       now->ptr = (struct term *)malloc(sizeof(struct term));
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
       printf("%s%lf x ^ %d", pad, now->num, i);// replaces temp values with real values entered by user
        now = now->ptr;
        pad = " + ";
        i++;
    }
    putchar('\n');
} 
  int main()
      {
      struct term *q;

      printf("Hello world\n");
      q = createPoly(q);
            printf("Hello world2\n");

      display(q);
      return(0);
      }
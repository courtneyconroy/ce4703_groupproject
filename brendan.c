#include <stdio.h>
#include <stdlib.h>
#define MAXNUM 10
 
  struct term
    {
        double num;
        struct term *ptr;
    };

//struct term *createPoly(struct term *q); // creates Linked list.

struct term *createPoly (struct term *poly){
  int polyNode;
  int iNode;
  int numNode;
  struct term *head, *t, *x;
  
    //create a random number of nodes
  numNode= rand()%(MAXNUM);   // Add 1 because order is 1 greater than the number of coefficients
  poly = (struct term *)malloc(sizeof(struct term));
  printf("Numnode is %d\n", numNode);
  poly->num = rand();   
  poly->ptr = NULL;
  x = poly;
 
    //create the required number of nodes
    for(iNode=1; iNode<numNode; iNode++)
       {
       t = (struct term *)malloc(sizeof(struct term));
       if (t == 0)
	      printf("Out of memory (1)"); // stops program if it runs out of memory
// I think the problem is here. Each node is created and needs to be linked to the previous node using something like the t->ptr = x; But I am not sure of the order of the commands.
       //x = t;
       t->num = rand()%(MAXNUM*10)-1;
       t->ptr = NULL;
       x->ptr = t;
       }
    return(poly);
   }
  
void display(struct term *head) 
{
  struct term *temp; // temp node on linked list
    const char *pad = "";
    int i = 0;
    temp = head;
    while (temp != NULL)
    {
// The fail at runtime happens here - I think that temp->num is pointing somewhere random and this will cause a segmentation fault (this means you tried to access a part of the computer you have no right to). This is what happens if you have a pointer pointing in the wrong place.
       printf("%s %lf x ^ %d\n", pad, temp->num, i);// replaces temp values with real values entered by user
        temp = temp->ptr;
        pad = " + ";
        i++;
    }
    putchar('\n');
} 
  int main()
      {
      struct term *q;

      printf("Hello world\n");
      createPoly(q);
            printf("Hello world2\n");

      display(q);
      return(0);
      }

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
// display function will display the polynomial
void display(struct term *head)
{
  struct term *now; // current node on linked list
    const char *pad = ""; //this will be used to print the + in the equation
    int i = 0; //the first exponent is equal to 0
    now = head;
    //while loop to go through each node in the list and print them in the desired format
    while (now != NULL)
    {
       printf("%s%.2lf x ^ %d", pad, now->num, i);// replaces temp values with real values entered by user
        now = now->ptr;
        pad = " + ";
        i++;
    }
    putchar('\n');
}

//addPoly will add to polinomials together creating a third polinomial
struct term *addPoly(struct term *p1, struct term *p2)
   {
   struct term *now1, *now2, *head, *sum;
   //used to traverse the functions
   now1 = p1; 
   now2 = p2; 
   sum = (struct term *)malloc(sizeof(struct term)); //creates the new polinomial
   head = sum; //saves the start of the link list to return it 

   //the while loop below ensures the function is carried out until the end of both linked lists have been reached
   while (now1 != NULL || now2 != NULL)
      {
      sum->ptr = (struct term *)malloc(sizeof(struct term));
      sum->ptr->ptr = NULL;
      
      if (now1 != NULL && now2 != NULL)//code to execute when both linked lists have terms
        {
        sum->num = now1->num + now2->num; // adds the two coefficients and assigns them to the appropriate term in sum
        // moves the pointers along to the next node
        now1 = now1->ptr; 
        now2 = now2->ptr; 
        }
      else
        if (now1 == NULL) //code to execute when p1 is empty
            {
            sum->num = now2->num; //assigns the term in p2 to sum
            now2 = now2->ptr; //traverses the list 
            }
         else //when p2 is empty
            {
            sum->num = now1->num; //assigns the term in p2 to sum 
            now1 = now1->ptr;

            }
    	 sum = sum->ptr;
      }
   return(head);
   }

//subPoly will subtract p2 from p1 creating a third polinomial
struct term *subPoly(struct term *p1, struct term *p2)
   {
   struct term *now1, *now2, *head, *diff;
   now1 = p1; //used to traverse p1
   now2 = p2; //used to traverse p2
   diff = (struct term *)malloc(sizeof(struct term)); //creates the new polinomial
   head = diff;

   //the while loop below ensures the function is carried out until the end of both linked lists have been reached
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

/* Function to delete the entire linked list */
void deletePoly(struct term *p1)
   {
   /* deref head_ref to get the real head */
   struct term *now, *temp;
   now = p1;
   temp = now;
   
   while (now != NULL) 
   {
       now = now->ptr;
       free(now);
   }
   
   /* deref head_ref to affect the real head back
      in the caller. */
   free(temp);
   p1->ptr = NULL;
   now = p1;
   now = NULL;
   }

  int main()
      {
      struct term *p1, *p2, *sum, *diff, *product, *quotient, *normal, *delete;
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
	  
	  printf("Delete Polynomial\n");
	  deletePoly(p1);
	  display(p1);

      return(0);
      }


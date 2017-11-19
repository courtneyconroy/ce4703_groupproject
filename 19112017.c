// Authors : Panos Brennan, Sinead O'Dowd, Courtney Conroy, Shaun Ryan-Tobin
// Date 19/11/2017 (DD/MM/YYYY)
// Code to make 2 polynomials using a linked list.
// This code creates 2 polynomials and sorts them according to their exponent


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node //structures linked list
{
  double cof;   // value for each coefficient
  int exp;      //value for each exponent
  struct node *link; 
};


struct node *create(struct node *q); // creates first node
struct node *insert(struct node *ptr, struct node *p); // inserts next node
void display(char const *tag, struct node *ptr);
void err_exit(char const *tag);

struct node *create(struct node *q)
{
  int i, n; //counter for length of linked list
    printf("enter the number of nodes: ");
    if (scanf("%d", &n) != 1)
        err_exit("Read error (number of nodes)");
    for (i = 0; i < n; i++) // continuation of counter
    {
        struct node *ptr = (struct node *)malloc(sizeof(struct node));
        if (ptr == 0)
	  err_exit("Out of memory (1)"); // stops program if it runs out of memory
        printf("enter the coefficient and exponent respectively: ");  // asks user to enter values for coefficient and exponent
        if (scanf("%lf%d", &ptr->cof, &ptr->exp) != 2)
	  err_exit("Read error (coefficient and exponent)"); // makes sure coefficient and exponent are entered correctly
        ptr->link = NULL;
        q = insert(ptr, q);
        display("after input", q); // displays polynomial after each input
    }
    return q; // shows polynomial when complete
}

struct node *insert(struct node *ptr, struct node *p) //inserts each part of linked list
{
  struct node *temp, *b;  // temp coefficient by temp exponent
    if (p == NULL)
        p = ptr;
    else
    {
        display("insert: p   = ", p);
        display("insert: ptr = ", ptr);
        if (p->exp < ptr->exp)
        {
            ptr->link = p;
            p = ptr;
        }
        else
        {
            temp = p;
            while ((temp->link != NULL) && (temp->link->exp < ptr->exp))
                display("insert: tmp = ", temp),
                temp = temp->link;
            display("insert: post loop", temp);
            b = temp->link;
            temp->link = ptr;
            ptr->link = b;
        }
    }
    return p;
}

void display(char const *tag, struct node *ptr) 
{
  struct node *temp; // temp node on linked list
    const char *pad = "";
    temp = ptr;
    printf("%s: ", tag);
    while (temp != NULL)
    {
      printf("%s%lf x ^ %d", pad, temp->cof, temp->exp);// replaces temp values with real values entered by user
        temp = temp->link;
        pad = " + ";
    }
    putchar('\n');
}

int main(void) // main function
{
  printf("enter the first polynomial:\n"); // asks the user to enter the first polynomial one piece at a time.
    struct node *p1 = NULL, *p2 = NULL;

    p1 = create(p1); // creates a linked list called p1

    printf("enter the second polynomial:\n");
    p2 = create(p2); // creates a linked list called p2

    display("p1", p1); // displays linked list p1
    display("p2", p2); // displays linked list p2

    return 0;
}

void err_exit(char const *tag)
{
    fprintf(stderr, "%s\n", tag);
    exit(1);// exits application
}

// Authors : Panos Brennan, Sinead O'Dowd, Courtney Conroy, Sean Ryan-Tobin
// Date 19/11/2017 (DD/MM/YYYY)
// Code to make 2 polynomials using a linked list.
// This code creates 2 polynomials and sorts them according to their exponent



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node //structures linked list
{
  double cof;   //value for each coefficient
  int exp;      //value for each exponent
  struct node *link; 
};


struct node *create(struct node *q); // creates Linked list.
struct node *insert(struct node *head, struct node *tail); // inserts next node
void display(char const *tag, struct node *head);
void err_exit(char const *tag);

struct node *create(struct node *q)
{
  int i, n; //counter for length of linked list
    printf("enter the number of nodes: ");
    if (scanf("%d", &n) != 1)
        err_exit("Read error (number of nodes)");
    for (i = 0; i < n; i++) // continuation of counter
    {
        struct node *head = (struct node *)malloc(sizeof(struct node));
        if (head == 0)
	  err_exit("Out of memory (1)"); // stops program if it runs out of memory
        printf("enter the coefficient and exponent respectively: ");  // asks user to enter values for coefficient and exponent
        if (scanf("%lf%d", &head->cof, &head->exp) != 2)
	  err_exit("Read error (coefficient and exponent)"); // makes sure coefficient and exponent are entered correctly
        head->link = NULL;
        q = insert(head, q);
        display("after input", q); // displays polynomial after each input
    }
    return q; // shows polynomial when complete
}

struct node *insert(struct node *head, struct node *tail) //inserts each part of linked list
{
  struct node *temp, *b;  // temp coefficient by temp exponent
    if (tail == NULL)
        tail = head;
    else
    {
        display("insert: tail   = ", tail);
        display("insert: head = ", head);
        if (tail->exp < head->exp)
        {
            head->link = tail;
            tail = head;
        }
        else
        {
            temp = tail;
            while ((temp->link != NULL) && (temp->link->exp < head->exp))
                display("insert: tmp = ", temp),
                temp = temp->link;
            display("insert: post loop", temp);
            b = temp->link;
            temp->link = head;
            head->link = b;
        }
    }
    return tail;
}

void display(char const *tag, struct node *head) 
{
  struct node *temp; // temp node on linked list
    const char *pad = "";
    temp = head;
    printf("%s: ", tag);
    while (temp != NULL)
    {
      printf("%s%lf x ^ %d", pad, temp->cof, temp->exp);// replaces temp values with real values entered by user
        temp = temp->link;
        pad = " + ";
    }
    putchar('\n');
}
//void multiply()
//{
//  int main*p1;
//  double x =2;
//}

int main(void) // main function
{
  printf("Tasks Required\n");
  printf("Tasks\t\t\t\t Completed By   \t Date Completed\n");
  printf("Create Polynomial\t\t\tPanos \t\t 19/11/2017\n");
  printf("Delete Polynomial\n");
  printf("Add two Polynomials\n");
  printf("Subtract two Polynomials\n");
  printf("Multiplication by a Double\n");
  printf("Division by a Double\n");
  printf("Normalise Polynomial\n");
  printf("Return order of polynomial\n");
  printf("Print Polynomial\n");
  printf("\n\n\n\n");
  
  printf("enter the first polynomial:\n"); // asks the user to enter the first polynomial one piece at a time.
    struct node *poly1 = NULL, *poly2 = NULL;

    poly1 = create(poly1); // creates a linked list called p1

    printf("enter the second polynomial:\n");
    poly2 = create(poly2); // creates a linked list called p2

    display("p1", poly1); // displays linked list p1
    display("p2", poly2); // displays linked list p2

    return 0;
}

void err_exit(char const *tag)
{
    fprintf(stderr, "%s\n", tag);
    exit(1);// exits application
}

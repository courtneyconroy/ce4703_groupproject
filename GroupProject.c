/*************************************************************************************************/
//online code
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int cof;                                                	//n
    int exp;							//^n
    struct node *link;
};

struct node *create(struct node *q);
struct node *insert(struct node *ptr, struct node *p);
void display(char const *tag, struct node *ptr);
void err_exit(char const *tag);

struct node *create(struct node *q)
{
    int i, n;						//n is number of nodes, i is counter
    printf("enter the number of nodes: ");
    if (scanf("%d", &n) != 1)
        err_exit("Read error (number of nodes)");
    for (i = 0; i < n; i++)
    {
        struct node *ptr = (struct node *)malloc(sizeof(struct node));
        if (ptr == 0)
            err_exit("Out of memory (1)");				
        printf("enter the coefficient and exponent respectively: ");
        if (scanf("%d%d", &ptr->cof, &ptr->exp) != 2)
            err_exit("Read error (coefficient and exponent)");
        ptr->link = NULL;
        q = insert(ptr, q);				//inserts polynomial 
        display("after input", q);			//shows polynomial when values are entered
    }
    return q;						//shows polynomial when completed
}

struct node *insert(struct node *ptr, struct node *p)
{
    struct node *temp, *b;
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
    struct node *temp;
    const char *pad = "";
    temp = ptr;
    printf("%s: ", tag);
    while (temp != NULL)
    {
        printf("%s%d x ^ %d", pad, temp->cof, temp->exp);
        temp = temp->link;
        pad = " + ";
    }
    putchar('\n');
}

int main(void)
{
    printf("enter the first polynomial:\n");
    struct node *p1 = NULL, *p2 = NULL;

    p1 = create(p1);

    printf("enter the second polynomial:\n");
    p2 = create(p2);

    display("p1", p1);
    display("p2", p2);

    return 0;
}

void err_exit(char const *tag)
{
    fprintf(stderr, "%s\n", tag);
    exit(1);
}
//online code end
/*******************************************/

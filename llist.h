 ///////////
//llist.h
//header file for simple linked list implementation
//authors: Sinead O'Dowd, Panos Brennan, Sean Ryna Tobin, Courtney Conroy
//date: 22/11/2017
//////////


//define error codes for linked list
typedef enum {ok, illegalNode, noMemory} llError;

//define structure for data to be stored in linked list

typedef struct {
  double coeff;
  int exp;
}data;

//define structure for a node of a linked list

typedef struct node {
  data d; //store some data in node
  struct node *successor; //store successor of node
                          //as typedef is not yet completed
                          // name llistnode cannot be used
} llistnode;


//define type for linked list

typedef struct {
  llistnode *head;
  llistnode *current;
} llist;

llist *listCreate();
void nodeCreate (llist *list);


#endif

///////////////////////////////////////////
//linkedList.c
//functions for simple single linked list
//
//authors:...
//date: 22/11/2017
//////////////////////////////////////////

#include <stdlib.h>
#include "llist.h"

//////////////
//create a linked list
//this is a blank linked list, has no value
//basic structure of one
/////////////
llist *listCreate() 
{
  llist *list;
  list = (llist *) malloc(sizeof(llist));
  // check for allocation success
  if (list != NULL) {
    // attempt to allocate memory for head
    list->head = (llnode *) malloc(sizeof(llnode));
    if (list->head != NULL) {
      // allocation successfull, satisfy condition
      // that head points to tail (NULL) and current is head
      list->head->successor = NULL; 
      list->current = list->head;
    } else {
      // need to de-allocate list and set it to NULL
      free(list);
      list = NULL;
    }
  }
  // returned value is as desired, failure of malloc()
  // will return NULL which  indicates also invalid
  // linked list
  return list;
  }

///////////
//add nodes to list
//////////

llError new_Node (struct node **)
{
  llError nodeCreated = ok;
  llistnode *newnode;
  
  // create new node
  newnode = (llistnode *) malloc(sizeof(llistnode));
  // allocation successful?
  if (newnode == NULL) {
    // allocation failure
    nodeCreated = noMemory;
  } else {
    // allocation successful
    // associate data d with newnode
    newnode->d = *d;
    // link newnode into linked list
    // 1. set succcessor of newnode to current nodes's successor
    newnode->successor = list->current->successor;
    // 2. set successor of current node to newnode
    list->current->successor = newnode;
  }
  return nodeCreated;
}

createPoly (struct poly p[]){
  int polyNode;
  int iNode;
 
  //create a random number of nodes
  numNode= rand();
iNode = numNode
  while (iNode >0){
   
    iNode= iNode - 1;
    exp = iNode;
  }

  //create
  double coeff[numNode];
  int iCoeff;
  for(iCoeff=0; iCoeff<=numNode;iCoeff++){
    coeff[iCoeff]=(rand());
  }

  for(iNode=0; iNode<numNode; iNode++)
    {
      
      p[numNode].coeff[]
	p[numNode].exp


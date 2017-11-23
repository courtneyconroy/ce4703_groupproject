///////////////////////////////////////////////////////
// linkedListmain.c
// test main function for linked list implementation
//
// author:	reiner dojen
// date:	25.10.2013
///////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

#include "09-linkedList.h"

int main() 
{
  llist *mylist=NULL;
  data newdata;
  int choice=-1;
  
  while (choice != 0) {
    // provide menu for different operations:
    printf("\t(0) Exit Program\n");
    printf("\t(1) Create new linked list\n");
    printf("\t(2) Insert new data\n");
    printf("\t(3) Delete node\n");
    printf("\t(4) Goto next node\n");
    printf("\t(5) Goto Head\n");
    printf("\t(6) Print current node\n");
    printf("\t(7) Print entire list\n");
    printf("\t(8) Delete entire list\n");
    printf("\nPlease select 0-7:");
    scanf("%d",&choice);
    
    switch (choice) {
      
    case 0: // Exit Program
      break;
      
    case 1: //Create new linked list
      // check if list already exist
      if (mylist != NULL)
	printf("list already in use, cannot "
	       "create new list ...\n");
      else {
	// create list
	mylist = listCreate();
      }
      break;
      
    case 2: // Insert new data
      if (mylist != NULL) {
	// fill newdata with user input
	printf("\nplease enter name: ");
	scanf("%49s",newdata.name);
	printf("\nplease enter description: ");
	scanf("%254s",newdata.description);
	printf("\nplease enter id: ");
	scanf("%d",&(newdata.id));
	// call insertAfter
	if (insertAfter(&newdata, mylist) == ok)
	  printf("\nInserted data successfully\n");
	else 
	  printf("\nInsuffient ressources, operation cancelled\n");
      } else {
	printf("You must create a linked list first ...\n");
      }
      break;
      
    case 3: // delete node
      if (mylist != NULL) {
	// attemtp to delete node and report result
	if (deleteNext(mylist) == ok) 
	  printf("Node deleted ...\n");
	else 
	  printf("Invalid successor of current, operation cancelled\n");
      } else {
	printf("You must create a linked list first ...\n");
      }
      break;
      
    case 4: // goto next node
      if (mylist != NULL) {
	// attempt to goto next node and report result
	if (gotoNextNode(mylist) == ok) 
	  printf("Moved to next node ...\n");
	else 
	  printf("Invalid successor of current, operation cancelled\n");
      } else {
	printf("You must create a linked list first ...\n");
      }
      break;
      
    case 5: // goto head
      if (mylist != NULL) {
	gotoHead(mylist);
      } else {
	printf("You must create a linked list first ...\n");
      }
      break;
      
    case 6: // print current node
      if (mylist != NULL) {
	// print "Head" if current is head
	if (mylist->current == mylist->head) {
	  printf("Head\n");
	} else {
	  // otherwise print all data elements
	  data *d = accessData(mylist);
	  printf("ID = %d\nName = %s\nDescription = %s\n", 
		 d->id, d->name, d->description);
	}
      } else {
	printf("You must create a linked list first ...\n");
      }
      break;
      
    case 7: // print entire list
      if (mylist != NULL) {
	int counter = 0;
	// start at head
	gotoHead(mylist);
	do {
	  // print current node
	  if (mylist->current == mylist->head) {
	    printf("\nHead\n");
	  } else {
	    printf("Node #%d\n", ++counter);
	    data *d = accessData(mylist);
	    printf("\tID = %d\n\tName = %s\n\tDescription = %s\n", 
		   d->id, d->name, d->description);
	  }
	  // goto next node in list
	} while( gotoNextNode(mylist) == ok);
	printf("\n\n");
      } else {
	printf("You must create a linked list first ...\n");
      }
      break;

    case 8: // delete entire list
      if (mylist != NULL) {
	listDelete(mylist);
	mylist = NULL;
      } else {
	printf("You must create a linked list first ...\n");
      }
      break;
      
    default:
      printf("Invalid choice, please select again\n");
    }
    
  }
  return EXIT_SUCCESS;
}

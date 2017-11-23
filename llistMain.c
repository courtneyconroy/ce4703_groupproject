 ///////////
//llistMain.c
//test main function for linked list implementation
//authors: Sinead O'Dowd, Panos Brennan, Sean Ryna Tobin, Courtney Conroy
//date: 22/11/2017
//////////


#include <stdio.h>
#include <stdlib.h>
#include "llist.h"

int main()
{
  //declare list names for 2 polys
  llist *poly1 = NULL;
  llist *poly2 = NULL;
  data newData; //data the user will be asked to input
  int menuChoice = -1; //variable used when user has to choose from menu of operations

  while (menuChoice !=) {
    //menu for different operations:
    printf ("\t (0) Exit Program\n");
    printf("\t(1) Create new polynomial\n");


    switch (menuChoice){

    case 0://Exit Program
      break;

    case 1: //Creat polynomials
      //check if polynomails have been created already
      if ( poly1 != NULL || poly2 != NULL)
	printf(" You have already created one or more polynomials");
      else {
	//create the 2 lists
	poly1 = listCreate();
	poly2 = listCreate();
        printf("You have created 2 polynomials, please enter the data"
             " by choosing 2 from the menu above\n");
      }
      break;
      
    }

    
  }

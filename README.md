# ce4703_groupproject
Project looking for a polynomial for arbitary order

There will be 4 different files.
Read only text file - This will contain info/pseudo code for our operations for this project
Main file - Contain different cases to test the operations
Header file - for simple linked list implementation
Linked List file - implementation of linked list (simple)


Header file:
* define error codes (llError
  ok
  illegalNode
  noMemory
* define structure for data to be stored (data)
  coeff -coefficiant
  exp - expontential
* define structure for node(llistnode)
  data
  successor 
* define type of linked list (llist)
  head
  current 
* function declarations




///////////////
Functions
///////////////


///////
add_poly
///////



void function with poly1, poly2, poly_add
//3 if conditions:1 poly1 > poly2, poly1 <poly2, poly1 =poly2.   (in terms of exp)
while  poly 1 is next and poly 2 is next
{
if exp of poly1 is greater than poly2
  exp of poly is equal to exp of poly1
  coef of poly is equal to coeff of poly1
  poly1 is equal to next poly1
  
else if exp of poly1 is less than poly 2
   exp of poly is equal to exp of poly2
  coef of poly is equal to coeff of poly2
  poly2 is equal to next poly2  
else
  exp of poly is equalt to poly1 exp
  coeff poly is equal to poly1 coeff and poly2 coeff
  poly 1 is equal to next poly1
  poly 2 is equal next poly2
//dynamically create new node



///////////////////
normalise_poly
////////////////// 
#include <float.h>
search array coeff to find max coefficent
Devide array coeff by this max value
#include <stdio.h>
 
int main () {

   int coeff[ n ]; /* n is an array of n integers */
   int i,j;
 
   /* initialize elements of array n to 0 */         
   for ( i = 0; i < n; i++ ) {
      coeff[i]
   }
   
   /* output each array element's value */
   for (j = 0; j < 10; j++ ) {
      printf("Element[%d] = %d\n", j, n[j] );
   }
 
   return 0;
}


///////////////////////
Main file
int main()
{
create
while
switch
Different cases:
case 0: exit program
break
Case 1: Create new linked list
if list = null, print that list is already in use
else create list, list = listCreate function
Case2: Insert new data for polynomials
if liset != Null, enter new data (printf/scanf functions)
  cont.. call insert new node, if the new data from list is ok, print "Success"
        if not print "Unsuccessful, cancelled, create a link list.. break
Case 3: Delete linked list
if list !=null, call delete list function for list, list = NULL
else print you must create list first
Case 4: Print entire list
 if list =null, creat counter and start at head
 do if list current = list head, print head, if not print node with ++counter
 use data to access data from list
 print data
  while list is ok to go to next node, print \n
  else print create lsitn first, break
Case 4: Add 2 polynomials
Case 5: Delete 2 polynomials
Case 6: Multiply by a double
Case 7: Divide by a double
Case 8: Normalise
Case 10: Return order

return EXIT_SUCCESS

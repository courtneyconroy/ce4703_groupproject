#include<stdio.h>
#include <stdlib.h>

int main () {
  double coeff[5]= {2,5,7,5,4}; //n is an array of integers
  int iNorm,jNorm;//varibles forthe for loop
  int maxValue = coeff[0]; //assign the forst value in the array to the max value
  //The below for loop starts at the first value checks if it is larger 
  //than the current max value if it is it rassigns this value to 
  //maxValue other wise maxValue remains unchanged.
  for (iNorm=0;iNorm<=5;iNorm++){
    if (coeff[iNorm]>maxValue){
      maxValue= coeff[iNorm];	
    }
  }
  int iArray;
  for (iArray=0; iArray < (sizeof (coeff) / sizeof (coeff [0]));iArray++){
    printf("%f\n", coeff[iArray]);
  }
  //The for loop the takes this maxium value and devides 
  //each of the coeffcients by it in order to make 
  //them all between 1 and 0 as required
  for (jNorm=0;jNorm<=5;jNorm++){
    coeff[jNorm]=coeff[jNorm]/maxValue;
  }
  //////////////////// 
  //print f statement wont work properly we need to fix it 
  //printf('The normalised array is %',poly1)
  
  // Return the order of the polynomial
  
  double exp [5]={5,35,7,9,5}; // creates an array to test the function.
  int iOrder;//varibles forthe for loop
  int maxValue2 = exp[0]; //assigns the max value to the first element
  //the for loop below starts at the first value checks if it is larger 
  //than the current max value if it is it rassigns this value to 
  //maxValue other wise maxValue remains unchanged.
  for (iOrder=0;iOrder<=5;iOrder++){
    if (exp[iOrder]>maxValue2){
      maxValue2= exp[iOrder];	
    }
    //when the for loop is complete the current maxValue will be the 
    //order of the equation.
    
  }
  ///multipy /devideing polynomials
  int iMult 
   for (jNorm=0;jNorm<=5;jNorm++){
    coeff[jNorm]=coeff[jNorm]/maxValue;
  }
  
}

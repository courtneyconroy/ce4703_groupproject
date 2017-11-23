#include<stdio.h>

int main () {
  double coeff[5]= {2,5,7,5,4}; //n is an array of integers
  int iNorm,jNorm;
  int maxValue = coeff[0];
  for (iNorm=0;iNorm<=5;iNorm++){
    if (coeff[iNorm]>maxValue){
      maxValue= coeff[iNorm];	
    }
  }
  for (jNorm=0;jNorm<=5;jNorm++){
    coeff[jNorm]=coeff[jNorm]/maxValue;
  }
  double exp [5]={5,35,7,9,5};
  int iOrder,jOrder;
  int maxValue = coeff[0];
  for (iOrder=0;iOrder<=5;iOrder++){
    if (exp[iOrder]>maxValue){
      maxValue= exp[iOrder];	
    }
  }
  
}


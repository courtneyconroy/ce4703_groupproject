#include<stdio.h>

int main () {
  double coeff[5]= {2,5,7,5,4}; //n is an array of integers
  int i,j;
  int maxValue = coeff[0];
  for (i=0;i<=5;i++){
    if (coeff[i]>maxValue){
      maxValue= coeff[i];	
    }
  }
  for (j=0;j<=5;j++){
    coeff[j]=coeff[j]/maxValue;
  }

}


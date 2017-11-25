// Code to generate random inputs for main function
// Authors: Panos-Brennan-Andreou, Courtney Conroy, Sinead O'Dowd, Sean Ryan-Tobin




#include <stdio.h>
#include <stdlib.h>

int main()
{
  double coeff;
  //  int node;
  //  printf("Enter a value: ");
  //  scanf("%d",&node);
  int node = (rand() % 20)+1;//generates random number between 1 and 20
  int power = 0; //sets initial power to 0
  while(node>power) //prints coeff and power for each node
    {
      coeff = (double)rand()/RAND_MAX*10.0; //Generates random coefficient for each value
       while (coeff <0)
      	{
	  coeff = (double)rand()/RAND_MAX*10.0;//Makes sure value isnt negative
      	}
       printf("%.1lf\t",coeff); //prints double with one decimal place
       printf("%d\n",power);    //prints power for x
       power=power+1;           //adds 1 to power each time
    }
  
  printf("\n%d\n",node); //prints number of nodes (not needed)
}

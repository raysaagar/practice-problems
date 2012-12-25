/*************************************
 * Codeforces Problem 4A - Watermelon
 * ***********************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//Prototypes

//Global Variables

int
main(int argc, char *argv[])
{

  int weight, half;
  
  //get weight
  scanf("%d",&weight);
  
  if((weight % 2 != 0)||(weight == 0)||(weight == 2)){
	printf("NO\n");
  }
  else{
	/*half = weight - 2;
	if (half % 2 != 0){
	  printf("NO\n");
	}
	else*/
	  printf("YES\n");
  }
  
  return 0;


	
}

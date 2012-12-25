/************************************
 * Codeforces Problem 84A - Toy Army
 * **********************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

//Prototypes

//Global Variables

int
main(int argc, char *argv[])
{

  int soldiers, count, loop;
  count = 0;
  loop = 0;
  
  scanf("%d",&soldiers);
  /*soldiers *= 2;

  while(loop != 2){
	soldiers = soldiers/2;
	count += soldiers;
	loop++;
	}*/

  printf("%d\n",soldiers+(soldiers/2));

  return 0;
}

/******************************************
 * Codeforces Problem 50A - Domino piling
 * ****************************************/


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

//Prototypes

//Global Variables

int
main(int argc, char *argv[])
{

  int i, xdim, ydim, area;


  scanf("%d %d",&xdim,&ydim);

  area = xdim * ydim;
  i = area/2;
  printf("%d\n",i);

  
  return 0;
}

/*****************************************
 * Codeforces Problem 1A - Theater Square
 * ***************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

//Prototypes

//Global Variables

int
main(int argc, char *argv[])
{

  int n,m,a;
  unsigned long long x, y, area;
  //double x, y, area;

  x = 0;
  y = 0;
  
  scanf("%d %d %d",&n,&m,&a);

  x = ceil(((double)n)/a);
  y = ceil(((double)m)/a);
 
  //printf("%d %d\n",x,y);

  area = x * y;

  printf("%lld\n",area);

  return 0;
}

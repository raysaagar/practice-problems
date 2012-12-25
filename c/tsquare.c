/*****************************************
 * Codeforces Problem 1A - Theater Square
 * Incomplete!!
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

  x = 0;
  y = 0;
  
  scanf("%d %d %d",&n,&m,&a);

  while(n > 0){
	x++;
	n -= a;
  }
  while(m > 0){
	y++;
	m -= a;
  }
  area = x * y;

  printf("%llu\n",area);

  return 0;
}

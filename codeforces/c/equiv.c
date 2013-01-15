/********************************************
 * Codeforces Problem 69A - Young Physicist
 * ******************************************/


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

//Prototypes

//Global Variables

int
main(int argc, char *argv[])
{

  int cases, x, y, z;
  int xtotal, ytotal, ztotal;
  x = y = z = 0;
  xtotal = ytotal = ztotal = 0;

  scanf("%d",&cases);
  
  while(cases != 0){
	scanf("%d %d %d",&x, &y, &z);
	cases--;
	xtotal += x;
	ytotal += y;
	ztotal += z;
  }
  if ((xtotal == 0) && (ytotal == 0) && (ztotal == 0))
	printf("YES\n");
  else
	printf("NO\n");
  
  return 0;
}

/*******************************************
 * Codeforces Problem 246A - Buggy Sorting
 * *****************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

//Prototypes

//Global Variables

int
main(int argc, char *argv[])
{

  int n, top;
  
  scanf("%d",&n);
  top = 100;

  if (n < 3){
    printf("-1");
    return 0;
  }

  while(n > 0){
    printf("%d ", top);
    top--;
    n--;
  }

  return 0;
}

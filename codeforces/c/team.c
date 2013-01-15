/****************************************************
 * Codeforces Problem 231A - Team 
 * **************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

//Prototypes

//Global Variables

int main(int argc, char *argv[])
{

  int i, count;
  int numLines;
  int a,b,c;

  scanf("%d",&numLines);
  
  i = 0;
  count = 0;

  while(i < numLines){
    scanf("%d %d %d",&a,&b,&c);
    if((a+b+c) > 1)
        count++;
    i++;
  }

  printf("%d\n",count);
  return 0;
}

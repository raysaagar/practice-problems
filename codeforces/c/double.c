/***************************************
 * Codeforces Problem 82A - Double Cola
 * *************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

//Prototypes

//Global Variables

int main(int argc, char *argv[]){

  int n,subtractor;
  int count;

  char* names[] = {"Sheldon","Leonard","Penny","Rajesh","Howard"};

  count = 0;

  subtractor=5;
  
  scanf("%d",&n);

  // determine which bucket is the last one
  // ie - 5 people, 10 people, 20 people, etc.
  while((n - subtractor) > 0){
    n -= subtractor;
    subtractor *= 2;
  }

  // we should be in the last bucket now
  // determine the specific person now
  int inc;
  inc = subtractor / 5;
  
  count = ceil(((float)n)/inc);

  printf("%s\n",names[count-1]);

  return 0;
}


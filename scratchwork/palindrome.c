/****************************************************
 * **************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

//Prototypes

//Global Variables

int main(int argc, char *argv[])
{

  char word[256];
  scanf("%s",word);

  int numChars;

  for(numChars = 0; numChars < 256; numChars++){
    // get the number of characters
    if (word[numChars] == '\0')
      break;
  }

  int start = 0;
  int end = numChars-1;

  // check all the characters from start to end
  while((word[start] == word[end])){
    if(start > end){
      printf("TRUE\n");
      return 0; 
    }
    start++;
    end--;
  }
  printf("FALSE\n");

  return 0;
}

/****************************************
 * Codeforces Problem 147A - Punctuation
 * **************************************/


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

//Prototypes
void countSpaces(char str[]);
//Global Variables

int
main(int argc, char *argv[])
{

  int count, i, j, numspaces, puncBool;
  char input[10001], output[10001];
  char letter;
  
  count = 0;
  i = 0;
  j = 0;
  puncBool = 0;
  
  while((letter = getchar()) != '\n'){
	input[count] = letter;
	count++;
  }
  count++;
  input[count] = '\0';

  numspaces = 0;
  
  for(i = 0; i <= count; i++){
	if(input[i] == ' '){
	  numspaces++;
	}
	else{
	  if ((input[i] == '.') || (input[i] == ',') || (input[i] == '!') || (input[i] == '?')) {
		output[j] = input[i];
		j++;
		output[j] = ' ';
		j++;
		numspaces = 0;
		puncBool = 1;
		//		printf("case 1\n");
	  }
	  else{
		if((numspaces >= 1) && (puncBool == 0)){
		  output[j] = ' ';
		  j++;
		  //		  printf("case 2\n");
		}
		puncBool = 0;
		numspaces = 0;
		output[j] = input[i];
		j++;
	  }
	}
  }

  //countSpaces(output);
  printf("%s\n", output);
  
  return 0;
}

void countSpaces(char str[]){
  int i, count;
  count = 0;
  
  for(i = 0; i < 10001; i++){
	if(str[i] == ' '){
	  count++;
	}
	if(str[i] == '\0'){
	  printf("spaces: %d\n",count);
	  return;
	}
  }


}

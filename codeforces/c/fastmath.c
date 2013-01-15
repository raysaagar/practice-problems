/****************************************************
 * Codeforces Problem 61A - Ultra-Fast Mathematician
 * **************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

//Prototypes

//Global Variables

int
main(int argc, char *argv[])
{

  int i;
  char num1[101], num2[101], out[101];

  scanf("%s",num1);
  scanf("%s",num2);

  for(i = 0; i <= 100; i++){
	if(num1[i] == '\0'){
	  out[i] = '\0';
	  break;
	}
	if(num1[i] == num2[i]){
	  out[i] = '0';
	}
	else{
	  out[i] = '1';
	}
  }
  printf("%s\n",out);
  return 0;
}

/*************************************
 * Codeforces Problem 96A - Football
 * ***********************************/


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

//Prototypes

//Global Variables

int
main(int argc, char *argv[])
{

  int i, count0, count1;
  char str[101];
  count0 = 0;
  count1 = 0;

  scanf("%s",str);

  for(i = 0; i < 101; i++){
	if(str[i] == '1'){
	  count1++;
	  count0 = 0;
	}
	else if(str[i] == '0'){
	  count1 = 0;
	  count0++;
	}
	
	if((count0 > 6) || (count1 > 6)){
	  printf("YES\n");
	  return 0;
	}

  }

  printf("NO\n");

  return 0;
}

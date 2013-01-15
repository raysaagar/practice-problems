/**********************************************
 * Codeforces Problem 71A - Way Too Long Words
 * ********************************************/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

//Prototypes

//Global Variables

int
main(int argc, char *argv[])
{

  int cases, casenum, length;
  char str[101];
  
  //get cases
  scanf("%d",&cases);
  casenum = 0;
  
  while (casenum < cases){
	scanf("%s", str);
	length = strlen(str);

	if(length > 10){
	  printf("%c%d%c\n",str[0],length-2,str[length-1]);
	}
	else{
	  printf("%s\n", str);
	}
	casenum++;
  }
  return 0;
}

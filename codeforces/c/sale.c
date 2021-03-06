/********************************
 * Codeforces Problem 34B - Sale
 * ******************************/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

//Prototypes


typedef struct node{
  int profit;
  struct node * next;
} valNode;

void printList(valNode* head);

int
main(int argc, char *argv[])
{

  int maxSale, maxCarry, tvNum, carryNum;
  //char str[101];
  int val, total;
  valNode *x,*y;
  valNode *head;
  
  head = (valNode*) malloc(sizeof(valNode));

  x = (valNode*) malloc(sizeof(valNode));
  y = (valNode*) malloc(sizeof(valNode));
  
  //head will be the start of the list
  head->profit = 0;
  head->next = NULL;

  //get maxSale and maxCarry
  scanf("%d %d",&maxSale, &maxCarry);
  tvNum = 0;

  while (tvNum < maxSale){
	scanf("%d", &val);

	if(val < 0){
	  valNode *z = (valNode*) malloc(sizeof(valNode));
	  z->profit = val;
	  z->next = NULL;

	  //handle start of list
	  if(z->profit <= head->profit){
		z->next = head;
		head = z;
	  }
	  //handle insertion in middle of list
	  else{
		x = head;
		y = head->next;
		while(z->profit > y->profit){
		  x = x->next;
		  y = y->next;
		}

		z->next = y;
		x->next = z;
		
	  }
	  //	  printList(head);
	}
	tvNum++;
  }
  
  carryNum = 0;
  total = 0;
  x = head;
  //add up profit
  while((carryNum < maxCarry) && (x->profit != 0)){
	total += abs(x->profit);
	x = x->next;
	carryNum++;
  }

  printf("%d\n",total);
  
  return 0;
}

void printList(valNode* head){

  valNode *x;
	
  x = (valNode*) malloc(sizeof(valNode));;
  x = head;
  
  printf("---Printing List---\n");
  while (x->next != NULL){
	printf("|%d|x", x->profit);
	x = x->next;
  }
  
  printf("\n");


}

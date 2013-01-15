/*************************************
 * Codeforces Problem 144B - Meeting
 * ***********************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

//Prototypes

//Global Variables

typedef struct circle{
  int x;
  int y;
  int radius;
  
} circle;


int
main(int argc, char *argv[])
{

  int xa, xb, ya, yb;
  int numCircles, i,j,k, xlow, xhi, ylow, yhi;
  int dist,dist2, count;
  
  scanf("%d %d %d %d",&xa,&ya,&xb,&yb);
  scanf("%d",&numCircles);

  circle listing[numCircles];
  i = 0;
  dist = 0;
  dist2 = 0;
  count = 0;
  
  while(i < numCircles){
	scanf("%d %d %d", &listing[i].x, &listing[i].y, &listing[i].radius);
	listing[i].radius = listing[i].radius * listing[i].radius;
	i++;
  }

  if(xa <= xb){
	xlow = xa;
	xhi = xb;
  }
  else{
	xlow = xb;
	xhi = xa;
  }
  
  if(ya <= yb){
	ylow = ya;
	yhi = yb;
  }
  else{
	ylow = yb;
	yhi = ya;
  }  

  int covered = 0;
  
   //ylow across (x varies)
  for(i = xlow; i <= xhi; i++){
	for(k = 0; k < numCircles; k++){
	  dist = pow((i - listing[k].x),2) + pow((ylow - listing[k].y),2);
	  //  	  printf("testing (%d,%d) and dist: %d\n",i,ylow,dist);
	  if(dist > listing[k].radius){
		covered = 0;	
	  }
	  else{
		covered = 1;
		break;
	  }
	}
	
	if(covered == 0){
	  count++;
	  //  printf("(%d,%d)-\n",i,ylow);
	}
	
  }

  //  printf("count: %d\n",count);
  
  //yhi across (y varies)
  for(i = xlow; i <= xhi; i++){
	for(k = 0; k < numCircles; k++){
	  dist = pow((i - listing[k].x),2) + pow((yhi - listing[k].y),2);
	  //	  printf("testing (%d,%d) and dist: %d\n",i,yhi,dist);
	  if(dist > listing[k].radius){
		covered = 0;
	  }
	  else{
		covered = 1;
		break;
	  }
	}
	if(covered == 0){
	  count++;
	  //	  printf("(%d,%d)-\n",i,yhi);
	}
  }

  //  printf("count: %d\n",count);
	
  //xlow and yhigh across (y varies)
  for(i = ylow+1; i < yhi; i++){
	for(k = 0; k < numCircles; k++){
	  dist = pow((xlow - listing[k].x),2) + pow((i - listing[k].y),2);
	  if(dist > listing[k].radius){
		//		printf("(%d,%d)y-\n",xlow,i);
		covered = 0;
	  }
	  else{
		covered = 1;
		break;
	  }
	}
	if(covered == 0)
	  count++;
  }

  //xhi across (y varies)

  for(i = ylow+1; i < yhi; i++){
	for(k = 0; k < numCircles; k++){
	  dist = pow((xhi - listing[k].x),2) + pow((i - listing[k].y),2);
	  if(dist > listing[k].radius){
		//		printf("(%d,%d)y--\n",xhi,i);
		covered = 0;
	  }
	  else{
		covered = 1;
		break;
	  }
	}
	if(covered == 0)
	  count++;
  }
  
  printf("%d\n",count);
  

  return 0;
}

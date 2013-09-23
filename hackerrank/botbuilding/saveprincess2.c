/*******************************
 * Bot saves princess - 2
 * ****************************/

#include <stdio.h>

// Prototypes
void nextMove(int n, int x, int y, char grid[n][n]);

int 
main(int argc, char *argv[])
{
  int n, x, y;

  scanf("%d", &n);
  scanf("%d", &x);
  scanf("%d", &y);
  
  char grid[n][n];
  for(int i = 0; i < n; i++){
    scanf("%s", grid[i]);
  }
  nextMove(n, x, y, grid);
  return 0;
}

void nextMove(int n, int x, int y, char grid[n][n]){
  
  // get the initial location of princess
  int locx, locy;
  // check down
  for(int i = 0; i < n; i++){
    // check across
    for(int j = 0; j < n; j++){
      if(grid[i][j] == 'p'){
        locx = i;
        locy = j;
      }
    }
  }

  if(x > locx){
    printf("UP\n");
    grid[y][x-1] = 'm';
  }
  else if(x < locx){
    printf("DOWN\n");
    grid[y][x+1] = 'm';
  }
  else if(y > locy){
    printf("LEFT\n");
    grid[y-1][x] = 'm';
  }
  else if(y < locy){
    printf("RIGHT\n");
    grid[y+1][x+1] = 'm';
  }
  else
    return;
}
/* Tail starts here */

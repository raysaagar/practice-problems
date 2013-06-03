/*******************************
 * Bot saves princess - 1
 * ****************************/

#include <stdio.h>

// Prototypes
void displayPathtoPrincess(int n, char grid[n][n]);

int 
main(int argc, char *argv[])
{
  int n;
  scanf("%d", &n);

  char grid[n][n];
  for(int i = 0; i < n; i++){
    scanf("%s", grid[i]);
  }
  displayPathtoPrincess(n, grid);
  return 0;
}

void displayPathtoPrincess(int n, char grid[n][n]){
  
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

  while(1){
    // get the location of the robot
    int x, y;
    for(int i = 0; i < n; i++){
      // check across
      for(int j = 0; j < n; j++){
        if(grid[i][j] == 'm'){
          x = j;
          y = i;
        }
      }
    }

    grid[y][x] = '-';
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
}
/* Tail starts here */

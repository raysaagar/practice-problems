/****************************************************
 * Implements various sorting algorithms
 * - Completed:
 *   - Merge Sort
 *   - Bubble Sort
 * - TODO:
 *   - Selection Sort
 *   - Insertion Sort
 *   - Heap Sort
 ***************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>

//Prototypes
int* bubblesort(int* arr, int len);
int* mergesort(int* arr, int len);
int* merge(int* left, int* right, int leftLen, int rightLen);
//Global Variables

int main(int argc, char *argv[])
{

  int numLines, a;

  scanf("%d",&numLines);
  int* list = malloc(sizeof(int)*numLines);
  printf("Input : ");
  // initialize all values
  for (int i = 0; i < numLines; i++){
    scanf("%d",&a);
    list[i] = a;
    printf("%2d ", list[i]);
  }
  printf("\n");

  // for timing
  clock_t start = clock(), diff;
  //list = mergesort(list, numLines);
  list = bubblesort(list, numLines);
  diff = clock() - start;
  printf("Sorted: ");
  for(int i = 0; i < numLines; i++){
    printf("%2d ", list[i]);
  }

  printf("\n");
  // print the timing information
  int msec = diff * 1000 / CLOCKS_PER_SEC;
  printf("Time: %d.%d s\n",msec/1000,msec%1000);

  return 0;
}

int* bubblesort(int* arr, int len){

  int tmp;
  for (int i = 1; i < len; i++){
    for (int j = 0; j < len-1; j++){
      if(arr[j] > arr[j+1]){
        tmp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = tmp;
      }
    }
  }

  return arr;
}

int* mergesort(int* arr, int len){
  // base case: if only 1 elt, done splitting array 
  if (len <= 1){
    return arr;
  }

  int mid = len / 2;

  int* left = malloc(sizeof(int)*mid);
  int* right = malloc(sizeof(int)*(len-mid));

  // generate the left array
  for(int i = 0; i < mid; i++){
    left[i] = arr[i];
  }
  // generate the right array
  for(int i = mid; i < len; i++){
    right[i-mid] = arr[i];
  }

  // mergesort (split) the generated arrays
  left = mergesort(left, mid);
  right = mergesort(right, len-mid);

  // merge the split and sorted halves
  int* result = merge(left, right, mid, (len-mid));
  return result;

}

int* merge(int* left, int* right, int leftLen, int rightLen){

  int sz = leftLen + rightLen;
  // create an array to store the merge
  int* result = malloc(sizeof(int) * sz);

  int count = 0;
  int lc = 0;
  int rc = 0;

  while(count < sz){
    // ran out of elts in the left array, merge remains of right side
    if(lc == leftLen){
      memcpy(&result[count],&right[rc],sizeof(int)*(rightLen-rc));
      break;
    }
    // ran out of elts in the right array, merge remains of the left side
    if(rc == rightLen){
      memcpy(&result[count],&left[lc], sizeof(int)*(leftLen-lc));
      break;
    }
    // if the left elt is smaller, merge it
    if(left[lc] < right[rc]){
      result[count] = left[lc];
      lc++;
      count++;
    }
    // else merge the right elt
    else{
      result[count] = right[rc];
      rc++;
      count++;
    }
  }

  return result;
}


/* Task */
/* Given an array of integers arr, return true if the number of occurrences of each value in the array is unique or false otherwise. */


/* Solution Idea:
 * 1) remove all duplicate ones first then count it in first list.
 * */


#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "stdbool.h"


int num_of_occ(int num, int *arr, int arrsize){
  int retval = 0;
  for (int i = 0; i < arrsize; i++) {
    if (arr[i] == num) {
      retval++;
    }
  }
  return retval;
}

int *arr_of_occ(int *arr, int arrsize){
  int *occ_arr = (int *)malloc(arrsize * sizeof(int));
  for (int i = 0; i < arrsize; i++) {
    occ_arr[i] = num_of_occ(arr[i], arr, arrsize);
  }
  return occ_arr;
}

bool uniqueOccurrences(int* arr, int arrSize){
  int *occ_arr = arr_of_occ(arr, arrSize);
  for (int i = 0; i < arrSize; i++) {
    printf("occ_arr[i] is: %d || num_of_occ is: %d\n", occ_arr[i], num_of_occ(occ_arr[i], occ_arr, arrSize));
    if (occ_arr[i] < num_of_occ(occ_arr[i], occ_arr, arrSize)) {
      return false;
    }
  }
  return true;
}


int main()
{
  int a[] = {1,2,2,1,1,3};
  int arrSize = sizeof(a)/sizeof(a[0]);
  int *occ_arr = arr_of_occ(a, arrSize);
  // for (int i = 0; i < arrSize; i++) {
    // printf("arr_of_occ is: %d || num_of_occ for it is: %d\n", occ_arr[i], num_of_occ(occ_arr[i], occ_arr, arrSize));
    // if (occ_arr[i] < num_of_occ(occ_arr[i], occ_arr, arrSize)) {
      // printf("Bro... %d is wrong\n", i);
    // }
  // }
  if (uniqueOccurrences(a, arrSize)) {
    printf("True\n");
  }
  else {
    printf("False\n");
  }
  free(occ_arr);
  return true;
}



/* Task */
/* Given an array of integers arr, return true if the number of occurrences of each value in the array is unique or false otherwise. */

#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "stdbool.h"


int countDupe(int *arr, int arrSize){
  int retval = 0;
  for (int i = 0; i < arrSize; i++)
		for (int j = i+1; j < arrSize; j++)
			if (arr[i] == arr[j]){
        retval++;
        break;
      }
  printf("Retval: %d\narrSize: %d\n", retval, arrSize);
  retval = arrSize - retval;
  return retval;
}


int checkDupe(int *arr, int arrSize){
  for (int i = 0; i < arrSize; i++)
		for (int j = i+1; j < arrSize; j++)
			if (arr[i] == arr[j])
       return false;
  return true;
}


int *countNum(int *arr, int arrSize){
  int *numOfArr = malloc( 4 * arrSize );
  for (int i = 0; i < arrSize; i++) {
    numOfArr[i] = 0;
    for (int j = i; j < arrSize; j++) {
      if (arr[i] == arr[j]) {
        numOfArr[i]++;
      }
   } 
  }
  return numOfArr;
}

// bool uniqueOccurences(int* arr, int arrSize){
  // int reducedSize = countDupe(a, arrSize);
  // int *count = countNum(a, arrSize);
  // for (int i = 0; i < reducedSize; i++) {
    // if (count[i] != 1) {
      // free(count);
      // return false;
    // }
  // }
  // free(count);
  // return true;
// }

int main()
{
  int a[] = {-3,0,1,-3,1,1,1,-3,10,0};
  int arrSize = sizeof(a)/sizeof(a[0]);
  int reducedSize = countDupe(a, arrSize);
  int *count = countNum(a, arrSize);
  printf("R-Size: %d\n", reducedSize);
  for (int i = 0; i < reducedSize; i++) {
    printf("%d\n", count[i]);
  }
  for (int i = 0; i < reducedSize; i++) {
    for (int j = i+1; j < reducedSize; j++) {
    if (count[i] == count[j]) {    
      free(count);
      printf("False aga\n");
      return false;
      }
    }
  }
  printf("True aga\n");
  free(count);
  return true;
}



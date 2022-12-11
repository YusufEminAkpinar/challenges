/* Task */
/* Given an array of integers arr, return true if the number of occurrences of each value in the array is unique or false otherwise. */

#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "stdbool.h"


typedef struct tuple {
  int *arr;
  int len;
} tuple;


bool checkDupe(int *arr, int arrSize){
	for (int i = 0; i < arrSize; i++)
		for (int j = i+1; j < arrSize; j++)
			if (arr[i] == arr[j])
				return false;
	return true;
}


void remElem(int *arr, int arrSize){
  int 
}



void remDupe(int *arr, int arrSize){
  while (!checkDupe) {
    for (int i = 0; i < arrSize; i++) {
      for (int j = i+1; j < arrSize; j++) {
        if (arr[i] == arr[j]) {
          for (int k = j; k < arrSize; k++) {
            
          }
        }
      }
    }
  }
}



int *countNum(int *arr, int arrSize){
  int *numOfArr = (int *)malloc(arrSize * sizeof(int)); 
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


int main(int argc, char const* argv[])
{
  int a[] = {1, 2, 3, 4, 5, 1, 2, 5};
  int arrSize = sizeof(a)/sizeof(a[0]);
  remDupe(a, arrSize);
  for (int i = 0; i < arrSize; i++) {
    printf("%d, ", a[i]);
  }
  printf("\n");
  return 0;
}



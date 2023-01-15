#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "stdbool.h"


/*  Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.
Each letter in magazine can only be used once in ransomNote. */

/* Plan:
 * Number of occurence'lardan git*/


int num_of_occ(char *string, char chr){
  int retval = 0;
  for (size_t i = 0; i < strlen(string); i++) {
    if (string[i] == chr) {
      retval ++;
    }
  }
  return retval;
}


int *arr_of_occ(char *string){
  int *retval = (int *)malloc(strlen(string) * sizeof(int));
  for (size_t i = 0; i < strlen(string); i++) {
    retval[i] = num_of_occ(string, string[i]);
  }
  return retval;
}


bool canConstruct(char *ransomNote, char *magazine){
  int rans = 0;
  int magan = 0;
  for (size_t i = 0; i < strlen(ransomNote); i++) {
    rans = num_of_occ(ransomNote, ransomNote[i]);
    magan = num_of_occ(magazine, ransomNote[i]);
    if (rans > magan) {
      return false;
    }
  }
  return true;
}


int main(int argc, char const* argv[])
{
  
  int *arr = arr_of_occ(some);
  for (size_t i = 0; i < strlen(some); i++) {
    printf("%c | %d\n", some[i], arr[i]);
  }
  return 0;
}

